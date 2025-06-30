grammar SolidityScript;

source
  : script* EOF
  ;

script
  : variableDeclaration 
  | functionCall
  ;

variableDeclaration
  : (identifier matchedParentheses?) '=' expression
  ;

functionCall
  : CHAIN '.' DEPLOY scope? (solFile | xtlFile) ('(' arguments? ')')?
  | CHAIN '.' identifier chainParams?
  | STOPWATCH '.' identifier
  | vizTrace
  | (identifier '=')? expression count? scope? '(' arguments? ')'
  | identifier '<<' inputCSV
  ;

vizTrace
  : 'viz' '.' 'trace' identifier ('[' numberLiteral ']')?
  ;

chainParams
  : contractName
  | numberLiteral
  ;

contractName
  : identifier
  ;

deployAddress
  : identifier
  ;

inputCSV
  : identifier '.csv'
  ;

count
  : '*' numberLiteral
  | '*' identifier
  | '*' UINT32 '.' RANDOM randomCallArguments
  ;

scope
  : '@' identifier (('.' (ALL | RANDOM | INTRA | CROSS)) | ('[' numberLiteral ']'))?
  | '@' numberLiteral
  ;

arguments
  : argument (',' argument)*
  ;

argument
  : explicitTypeValue | expression
  ;

explicitTypeValue
  : (numberLiteral | StringLiteral) '::' type
  ;

type
  : (UINT16 | UINT32 | UINT256 | ADDRESS | BOOL | BYTES)
  ;

identifier
  : Identifier
  ;

expression locals [int expressionType = -1]
  : EVMC_ADDRESS '[' numberLiteral ']'					{$expressionType = 0;}
  | randomCall								            {$expressionType = 1;}
  | expression '.' identifier				      		{$expressionType = 2;}	
  | numberLiteral							            {$expressionType = 3;}	
  | boolLiteral											{$expressionType = 4;}
  | StringLiteral							            {$expressionType = 5;}
  | stringArray								            {$expressionType = 6;}
  | structArray                           				{$expressionType = 7;}
  | identifier ('[' numberLiteral ']')?			  		{$expressionType = 8;}	
  ;

randomCall
  : (UINT16 | UINT32 | UINT256 | ADDRESS | BOOL) '.' RANDOM randomCallCount? randomCallArguments?
  | identifier '.' RANDOM randomCallCount?
  ;

stringArray
  : '{' StringLiteral (',' StringLiteral)* '}'
  ;

structArray
  : '{' arguments '}' ('[' numberLiteral ']')?
  ;

randomCallCount
  : '[' numberLiteral ']'
  ;

randomCallArguments
  : '(' arguments ? ')'
  ;

numberLiteral
  : DecimalNumber 
  | HexNumber
  ;

matchedParentheses
  : ('['']')
  ;

solFile
  : directivePath? identifier '.sol';

xtlFile
  : directivePath? identifier '.xtl';

directivePath: WINPATH | UNIXPATH;

WINPATH: WIN_ABSOLUTE_PATH | WIN_REALATIVE_PATH;
	WIN_ABSOLUTE_PATH: DRIVE? WIN_SLASH (DIRNAME WIN_SLASH)*;
	WIN_REALATIVE_PATH: (DIRNAME WIN_SLASH)+;
		fragment DRIVE: [a-zA-Z] ':';
		fragment WIN_SLASH: '\\';
		fragment DIRNAME: FILENAME* | '.' | '..';
		fragment FILENAME: (Identifier | '-');
UNIXPATH: UNIX_ABSOLUTE_PATH | UNIX_REALATIVE_PATH;
	UNIX_ABSOLUTE_PATH: UNIX_SLASH (DIRNAME UNIX_SLASH)*;
	UNIX_REALATIVE_PATH: (DIRNAME UNIX_SLASH)+;
		fragment UNIX_SLASH: '/';

CHAIN
  : 'chain'
  ;

STOPWATCH
  : 'stopwatch'
  ;

RANDOM
  : 'random'
  ;

ALL
  : 'all'
  ;

INTRA
  : 'intra'
  ;

CROSS
  : 'cross'
  ;
  
UINT16
  : 'uint16'
  ;

UINT32
  : 'uint32'
  ;

UINT256
  : 'uint256'
  ;

ADDRESS
  : 'address'
  ;

BOOL
  : 'bool'
  ;

EVMC_ADDRESS
  : 'evmc::address'
  ;

BYTES
  : 'bytes32'
  ;

StringLiteral
  : '"' StringCharacter* '"'
  ;

boolLiteral
  : TRUE | FALSE
  ;

TRUE
  : 'true'
  ;

FALSE
  : 'false'
  ;

DEPLOY
  : 'deploy'
  ;

fragment
StringCharacter
  : ~["\r\n\\] | ('\\' .) 
  ;

Identifier
  : IdentifierStart IdentifierPart* 
  ;

fragment
IdentifierStart
  : [a-zA-Z$_] 
  ;

fragment
IdentifierPart
  : [a-zA-Z0-9$_] 
  ;

DecimalNumber
  : ( DecimalDigits | (DecimalDigits? '.' DecimalDigits) ) ( [eE] DecimalDigits )? 
  ;

fragment
DecimalDigits
  : [0-9] ( '_'? [0-9] )* 
  ;

HexNumber
  : '0' [xX] HexCharacter*
  ;

fragment
HexCharacter
  : [0-9A-Fa-f] ;

WS
  : [ \t\r\n\u000C]+ -> skip 
  ;
CommentSingleLine: ('//' | '#') ~[\r\n]* -> channel(HIDDEN);
CommentMultiLine: '/*' .*? '*/' -> channel(HIDDEN);