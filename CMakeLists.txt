cmake_minimum_required(VERSION 3.8)

project(EVMHost)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_language(C CXX)

if(NOT USE_EVMONE_SRC)
	option(USE_EVMONE_SRC ON)
endif()

set(SOURCE_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
set(ANTLR_DIRECTORY ${CMAKE_SOURCE_DIR}/3rdParty/antlr4)
set(EVMONE_DIRECTORY ${CMAKE_SOURCE_DIR}/3rdParty/evmone)

#Add source files
file(GLOB ANTLR_GENERATED_SOURCES
    ${SOURCE_DIRECTORY}/script_parser/SolidityScript*.cpp
	${SOURCE_DIRECTORY}/transpiler/*.cpp
	${EVMONE_DIRECTORY}/src/keccak.c
)

file(GLOB EVMONE_SOURCES
	${EVMONE_DIRECTORY}/src/*.c
    ${EVMONE_DIRECTORY}/src/*.cpp
)

file(GLOB EVM_SOURCES
	${CMAKE_SOURCE_DIR}/include/ed25519/*.c
	${SOURCE_DIRECTORY}/EVM*.cpp
	${SOURCE_DIRECTORY}/main.cpp)

#Specify the include directories
include_directories(${SOURCE_DIRECTORY})
include_directories(${SOURCE_DIRECTORY}/script_parser)
include_directories(${SOURCE_DIRECTORY}/transpiler)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${ANTLR_DIRECTORY}/src/)

#Specifiy the static and shared library directories
if(WIN32)
	link_directories(${ANTLR_DIRECTORY}/lib/win/)
	link_directories(${EVMONE_DIRECTORY}/lib/win/)
elseif(UNIX AND NOT APPLE)
	link_directories(${ANTLR_DIRECTORY}/lib/linux/)
	link_directories(${EVMONE_DIRECTORY}/lib/linux/)
elseif(APPLE)
	set(CMAKE_OSX_DEPLOYMENT_TARGET 11.0)
	link_directories(${ANTLR_DIRECTORY}/lib/mac/)
	link_directories(${EVMONE_DIRECTORY}/lib/mac/lib/)
endif()

#Define the executable
if(USE_EVMONE_SRC)
	add_executable(EVMHost ${ANTLR_GENERATED_SOURCES} ${EVM_SOURCES} ${EVMONE_SOURCES})
    target_link_libraries(EVMHost antlr4-runtime)
else()
	add_executable(EVMHost ${ANTLR_GENERATED_SOURCES} ${EVM_SOURCES} )
    target_link_libraries(EVMHost evmone antlr4-runtime)
endif()

set_target_properties(EVMHost PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<0:>"
OUTPUT_NAME "crystality")

if(UNIX OR APPLE)
	add_compile_options(-Wno-attributes)
	#Find necessary packages
	find_package(Threads REQUIRED)
	if(THREADS_HAVE_PTHREAD_ARG)
	target_compile_options(PUBLIC EVMHost "-pthread")
	endif()
	target_link_libraries(EVMHost ${CMAKE_THREAD_LIBS_INIT})
endif()

add_custom_command(TARGET EVMHost POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:EVMHost>/solc)
if(WIN32)
	add_custom_command(TARGET EVMHost POST_BUILD
						COMMAND ${CMAKE_COMMAND} -E copy ${EVMONE_DIRECTORY}/lib/win/evmone.dll ${ANTLR_DIRECTORY}/lib/win/$<LOWER_CASE:$<CONFIG>>/antlr4-runtime.dll $<TARGET_FILE_DIR:EVMHost>
						COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/3rdParty/solc/solc-windows.exe $<TARGET_FILE_DIR:EVMHost>/solc)
elseif(UNIX AND NOT APPLE)
	add_custom_command(TARGET EVMHost POST_BUILD
						COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/3rdParty/solc/solc-static-linux $<TARGET_FILE_DIR:EVMHost>/solc
                   		COMMAND chmod u+x $<TARGET_FILE_DIR:EVMHost>/solc/solc-static-linux)
elseif(APPLE)
	add_custom_command(TARGET EVMHost POST_BUILD
						COMMAND ${CMAKE_COMMAND} -E copy ${EVMONE_DIRECTORY}/lib/mac/lib/libevmone.0.8.dylib $<TARGET_FILE_DIR:EVMHost>
						COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/3rdParty/solc/solc-macos $<TARGET_FILE_DIR:EVMHost>/solc
						COMMAND chmod u+x $<TARGET_FILE_DIR:EVMHost>/solc/solc-macos)
endif()

option(BUNDLE_OPS "default is OFF" OFF)
message(STATUS "BUNDLE_OPS is ${BUNDLE_OPS}....")

if(BUNDLE_OPS)
  set(BUNDLE_PATH ${CMAKE_SOURCE_DIR}/bundle)
  set(AppVersion "0.1.0" CACHE STRING "setup bundle package AppVersion")
  file(GLOB VSIX_FILE ${CMAKE_SOURCE_DIR}/crystality*.vsix)
  add_custom_target(bundle_package
    COMMENT "Starting to build package, this will tack a few minutes....."
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${BUNDLE_PATH}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}
  )
  add_dependencies(bundle_package EVMHost)
  if(WIN32)
  	file(GLOB_RECURSE PS1 LIST_DIRECTORIES FALSE ${CMAKE_SOURCE_DIR}/installer/win/*.ps1)
	add_custom_command(TARGET bundle_package POST_BUILD
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/bin/solc
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/examples
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/scripts
	COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/extensions
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bin ${BUNDLE_PATH}/Crystality/bin
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/contracts/test_cases ${BUNDLE_PATH}/Crystality/examples
	COMMAND ${CMAKE_COMMAND} -E copy ${VSIX_FILE} ${BUNDLE_PATH}/Crystality/extensions/crystality.vsix
	COMMAND ${CMAKE_COMMAND} -E copy ${PS1} ${BUNDLE_PATH}/Crystality/scripts
	)
	set(iscc "C:\\Program Files (x86)\\Inno Setup 6\\ISCC.exe")
    add_custom_command(TARGET bundle_package POST_BUILD
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      COMMENT "Building package...."
      COMMAND ${iscc} /Qp /DVERSION="${AppVersion}" ./installer/win/crystality.iss
    )
  elseif(UNIX AND NOT APPLE)
	add_custom_command(TARGET bundle_package POST_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "prepare bundle env, copying directory to bundle_path.............."
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/usr/lib
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/opt/Crystality/bin/solc
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/DEBIAN
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/opt/Crystality/scripts
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/opt/Crystality/examples
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/opt/Crystality/extensions
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bin ${BUNDLE_PATH}/Crystality/opt/Crystality/bin
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/contracts/test_cases ${BUNDLE_PATH}/Crystality/opt/Crystality/examples
		COMMAND ${CMAKE_COMMAND} -E chdir ./ cp -a ${CMAKE_SOURCE_DIR}/installer/linux/register*.sh ${BUNDLE_PATH}/Crystality/opt/Crystality/scripts
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/installer/linux/postinstall_linux.sh ${BUNDLE_PATH}/Crystality/DEBIAN/postinst
      	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/installer/linux/control_linux ${BUNDLE_PATH}/Crystality/DEBIAN/control
		COMMAND ${CMAKE_COMMAND} -E copy ${VSIX_FILE} ${BUNDLE_PATH}/Crystality/opt/Crystality/extensions/crystality.vsix
	)
	add_custom_command(TARGET bundle_package POST_BUILD
		COMMENT "starting bundle package......."
		COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/bundle chmod -R 0755 ./Crystality
		COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/bundle sed -i 's/^Version.*/Version: ${AppVersion}/g' ./Crystality/DEBIAN/control
		COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/bundle dpkg-deb --build Crystality Crystality_${AppVersion}_amd64.deb
    )
  elseif(APPLE)
	add_custom_command(TARGET bundle_package POST_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "prepare bundle env, copying directory to bundle_path.............."
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/bin
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/scripts
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/crystality/examples
		COMMAND ${CMAKE_COMMAND} -E make_directory ${BUNDLE_PATH}/Crystality/extensions
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bin ${BUNDLE_PATH}/Crystality/bin
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/contracts/test_cases ${BUNDLE_PATH}/crystality/examples
		COMMAND ${CMAKE_COMMAND} -E chdir ./ cp -a ${CMAKE_SOURCE_DIR}/installer/mac/* ${BUNDLE_PATH}/Crystality/scripts/
		COMMAND ${CMAKE_COMMAND} -E copy ${VSIX_FILE} ${BUNDLE_PATH}/Crystality/extensions/crystality.vsix
	)
	add_custom_command(TARGET bundle_package POST_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "starting bundle package......."
		COMMAND ${CMAKE_COMMAND} -E chdir ./ bash ${BUNDLE_PATH}/Crystality/scripts/bundle_mac.sh
		COMMAND ${CMAKE_COMMAND} -E chdir ./ packagesbuild ${BUNDLE_PATH}/Crystality/scripts/Crystality.pkgproj -F ${CMAKE_SOURCE_DIR}
    )
  endif()
endif()
