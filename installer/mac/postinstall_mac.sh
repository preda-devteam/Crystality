#! /bin/bash
echo "Crystality Installed success"
chmod -R 775 /Applications/Crystality
rm -rf /usr/local/lib/libevmone.0.8.dylib
ln -s /Applications/Crystality/bin/libevmone.0.8.dylib /usr/local/lib/
osascript -e 'tell application (path to frontmost application as text)
display alert "make sure VS code `code` is installed in PATH(https://code.visualstudio.com/docs/setup/mac#_launching-from-the-command-line) and run `bash /Applications/Crystality/scripts/register_mac.sh`."
end'
exit 0
