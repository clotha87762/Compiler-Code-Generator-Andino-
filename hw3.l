
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "y.tab.h"

int lineCount = 1;
int lineIndex = 0;
char lineBuffer[50000];
int srcOn = 1;
int tokenOn = 1;
typedef enum {
	KEY,ID,OP,PUNC,INTEGER,L_DOUBLE,CHARACTER,SCI,STRING
}PTYPE;

void PrintEOFSrc();
void PutToBuffer(char* token);
void ClearBuffer();
void PrintSrc();
void PrintToken(PTYPE t,char* text);
void PrintEOFSrc();
void Error();
void mstrcpy(char * s1, char* s2);
char* mstrcpy2(char* s2);

%}

VID   [a-zA-Z0-9_]
chl   [a-z]
chu   [A-Z]
alpha [a-zA-Z]
digit [0-9]
ad	  [a-zA-Z0-9]
BLANK		(([\ \t])|("/*".*"*/"))

CMT 	"/*".*"*/"
LCMT	"//"[^\n]*\n
CH 		(\\\')|(\\\")|(\\\?)|(\\\\)|(\\t)|(\\n)|[^\'\\\n]
STRCH	(\\\')|(\\\")|(\\\?)|(\\\\)|(\\t)|(\\n)|[^\"\\\n]


SEP		((\ )| (\t) | (\n) | ("+") | ("-") | ("*") | ("/") | ("%") | ("++") | ("--") | ("<") |(">")|("<=")|(">=")|("==")|("=")|("!=")|("!")|("&&")|("||")|("&")|(":")|(";")|(",")|("[")|("]")|("(")|(")")|("{")|("}"))

FSUFIX	[fFlL]
ISUFIX	[uUlL]|(ll)|(LL)

%x	LINECOMMENT
%x	COMMENT



%%

<LINECOMMENT>[^\n]	{PutToBuffer(yytext);}
<LINECOMMENT>\n		{PutToBuffer(yytext);PrintSrc();ClearBuffer();lineCount++;BEGIN 0;}
<COMMENT>\*\/		{PutToBuffer(yytext);BEGIN 0;}
<COMMENT>\n		{PutToBuffer(yytext);PrintSrc();ClearBuffer();lineCount++;}
<COMMENT>.		{PutToBuffer(yytext);}
\/\/	{BEGIN LINECOMMENT;PutToBuffer(yytext);}
\/\*	{BEGIN COMMENT; PutToBuffer(yytext);}

^{BLANK}*#{BLANK}*pragma{BLANK}+source{BLANK}+on{BLANK}*("//")?	{srcOn = 1;PutToBuffer(yytext);BEGIN LINECOMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+source{BLANK}+on{BLANK}*("/*")?	{srcOn = 1;PutToBuffer(yytext);BEGIN COMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+source{BLANK}+off{BLANK}*("//")? 		{srcOn = 0;PutToBuffer(yytext);BEGIN LINECOMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+source{BLANK}+off{BLANK}*("/*")? 		{srcOn = 0;PutToBuffer(yytext);BEGIN COMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+token{BLANK}+on{BLANK}*("//")?				{tokenOn = 1;PutToBuffer(yytext);BEGIN LINECOMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+token{BLANK}+on{BLANK}*("/*")?				{tokenOn = 1;PutToBuffer(yytext);BEGIN COMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+token{BLANK}+off{BLANK}*("//")?				{tokenOn = 0;PutToBuffer(yytext);BEGIN LINECOMMENT;}
^{BLANK}*#{BLANK}*pragma{BLANK}+token{BLANK}+off{BLANK}*("/*")?				{tokenOn = 0;PutToBuffer(yytext);BEGIN COMMENT;}
^{BLANK}*#(_|{ad}|{BLANK})*		{Error();}




"void"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return VOID;}
"int"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return INT;}
"double"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return DOUBLE;}
"bool"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return BOOL;}
"char"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return CHAR;}
"null"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return NUL;}
"for"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return FOR;}
"while"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return WHILE;}
"do"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return DO;}
"if"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return IF;}
"else"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return ELSE;}
"switch"		{PutToBuffer(yytext);PrintToken(KEY,yytext);  return SWITCH;}
"return"		{PutToBuffer(yytext);PrintToken(KEY,yytext);  return RETURN;}
"break"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return BREAK;}
"continue"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return CONTINUE;}
"const"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return CONST;}
"true"		{PutToBuffer(yytext);PrintToken(KEY,yytext);  yylval.bval = 1; return BOOL_LIT;}
"false"		{PutToBuffer(yytext);PrintToken(KEY,yytext); yylval.bval= 0; return BOOL_LIT;}
"struct"		{PutToBuffer(yytext);PrintToken(KEY,yytext);  return STRUCT;}
"case"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return CASE;}
"default"		{PutToBuffer(yytext);PrintToken(KEY,yytext); return DEFAULT;}

"clearerr"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"fclose"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext);return IDEN;}
"fdopen"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext);return IDEN;}
"feof"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"ferror"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext);return IDEN;}
"fflush"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fgetc"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fgetpos"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fgets"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);  return IDEN;}
"fileno"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fopen"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fprintf"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fpurge"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fputc"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext); return IDEN;}
"fputs"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext);  return IDEN;}
"fread"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"freopen"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fscanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fseek"	{PutToBuffer(yytext);PrintToken(KEY,yytext); mstrcpy(yylval.sval,yytext); return IDEN;}
"fsetpos"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"ftell"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"fwrite"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"getc"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"getchar"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"gets"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"getw"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"mktemp"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"perror"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"printf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"putc"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"putchar"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"puts"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"putw"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"remove"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"rewind"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"scanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"setbuf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"setbuffer"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"setlinebuf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"setvbuf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"sprintf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"sscanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"strerror"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"sys_errlist"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"sys_nerr"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"tempnam"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"tmpfile"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"tmpnam"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"ungetc"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"vfprintf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
o"vfscanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"vprintf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"vscanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"vsprintf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}
"vsscanf"	{PutToBuffer(yytext);PrintToken(KEY,yytext);mstrcpy(yylval.sval,yytext);return IDEN;}

"digitalWrite"		{PutToBuffer(yytext);PrintToken(KEY,yytext);return DIGITAL_WRITE;}
"delay"		{PutToBuffer(yytext);PrintToken(KEY,yytext);return DELAY;}
"LOW"		{ PutToBuffer(yytext);PrintToken(KEY,yytext);yylval.ival = 0; return LOW;}
"HIGH"		{ PutToBuffer(yytext);PrintToken(KEY,yytext); yylval.ival = 1;return HIGH;}


0{digit}+{ISUFIX}?				{/*printf("invalid integer!\n");*/Error();}
[1-9]{digit}*{ISUFIX}?		{PutToBuffer(yytext);PrintToken(INTEGER,yytext); yylval.ival = atoi(yytext); return INT_LIT;}
0{ISUFIX}?					{PutToBuffer(yytext);PrintToken(INTEGER,yytext); yylval.ival = atoi(yytext); return INT_LIT;}


{digit}+({alpha}|_)+		{Error();}
({alpha}|_){VID}*		{PutToBuffer(yytext);PrintToken(ID,yytext);yylval.sval= mstrcpy2(yytext);printf("s%s\n",yylval.sval);  return IDEN;}


{digit}+\.{digit}*[eE][+-]?{digit}+{FSUFIX}?	{PutToBuffer(yytext);PrintToken(SCI,yytext); yylval.dval = atof(yytext); return DOUBLE_LIT;}
{digit}+\.{digit}*[eE][+-]?{digit}+{FSUFIX}?(\.|_|{ad})+	{/*printf("SCI Error\n");*/Error(); }
\.{digit}+[eE][+-]?{digit}+{FSUFIX}?		{PutToBuffer(yytext);PrintToken(SCI,yytext);yylval.dval = atof(yytext); return DOUBLE_LIT;}
\.{digit}+[eE][+-]?{digit}+{FSUFIX}?(\.|_|{ad})+		{/*printf("SCI Error\n");*/Error();}
{digit}+[eE][+-]?{digit}+{FSUFIX}?			{PutToBuffer(yytext);PrintToken(SCI,yytext);yylval.dval = atof(yytext); return DOUBLE_LIT;}
{digit}+[eE][+-]?{digit}+{FSUFIX}?(\.|_|{ad})+		{/*printf("SCI Error\n");*/Error();}

{digit}+\.{digit}*{FSUFIX}?		{PutToBuffer(yytext);PrintToken(L_DOUBLE,yytext);yylval.dval = atof(yytext); return DOUBLE_LIT;}
{digit}+\.{digit}*{FSUFIX}?(\.|_|{ad})+		{/*printf("double Error\n");*/Error();}
\.{digit}+{FSUFIX}?			{PutToBuffer(yytext);PrintToken(L_DOUBLE,yytext);yylval.dval = atof(yytext); return DOUBLE_LIT;}
\.{digit}+{FSUFIX}?(\.|_|{ad})+		{/*printf("double Error\n");*/Error();}



\'{CH}\'           {	PutToBuffer(yytext);PrintToken(CHARACTER,yytext);yylval.cval = yytext[1]; return CHAR_LIT;}
L?\"{STRCH}*\"		{
						PutToBuffer(yytext);
						char* temp;
						if(yytext[0]=='L'){
							temp = (char*)malloc(sizeof(char)*(strlen(yytext)+3)); 
							temp[0] = '\0';
							int i=0;
							for(i=0;i<strlen(yytext)-3;i++)
								temp[i] = yytext[i+2];
							temp[i] = '\0';
						}
						else{
							temp = (char*)malloc(sizeof(char)*(strlen(yytext)+3)); 
							int i=0;
							temp[0] = '\0';
							for(i=0;i<strlen(yytext)-2;i++)
								temp[i] = yytext[i+1];
							temp[i] = '\0';
						}
						PrintToken(STRING,temp);
						//yylval.lit.type = 3;
						mstrcpy(yylval.sval,temp);
						return STRING_LIT;
					}  
L?\"/{STRCH}*		{/*printf("only one double-quote!\n");*/Error();}

"+"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '+';}
"-"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '-';}
"*"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '*';}
"/"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '/';}
"%"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '%';}
"++"		{PutToBuffer(yytext);PrintToken(OP,yytext); return PLUSPLUS;}
"--"		{PutToBuffer(yytext);PrintToken(OP,yytext); return MINUSMINUS;}
"<"		{PutToBuffer(yytext);PrintToken(OP,yytext);  return '<';}
"<="		{PutToBuffer(yytext);PrintToken(OP,yytext); return LE;}
">"		{PutToBuffer(yytext);PrintToken(OP,yytext);  return '>';}
">="		{PutToBuffer(yytext);PrintToken(OP,yytext); return GE;}
"=="		{PutToBuffer(yytext);PrintToken(OP,yytext); return EQUAL;}
"!="		{PutToBuffer(yytext);PrintToken(OP,yytext); return NOTEQUAL;}
"="		{PutToBuffer(yytext);PrintToken(OP,yytext);  return '=';}
"&&"		{PutToBuffer(yytext);PrintToken(OP,yytext);  return ANDAND;}
"||"		{PutToBuffer(yytext);PrintToken(OP,yytext); return OROR;}
"!"		{PutToBuffer(yytext);PrintToken(OP,yytext); return NOT;}
"&"		{PutToBuffer(yytext);PrintToken(OP,yytext); return '&';}

":"		{PutToBuffer(yytext);PrintToken(PUNC,yytext); return ':';}
"("		{PutToBuffer(yytext);PrintToken(PUNC,yytext); return '(';}
")"		{PutToBuffer(yytext);PrintToken(PUNC,yytext); return ')';}
"["		{PutToBuffer(yytext);PrintToken(PUNC,yytext); return '[';}
"]"		{PutToBuffer(yytext);PrintToken(PUNC,yytext); return ']';}
"{"		{PutToBuffer(yytext);PrintToken(PUNC,yytext);  return '{';}
"}"		{PutToBuffer(yytext);PrintToken(PUNC,yytext);  return '}';}
"."		{PutToBuffer(yytext);PrintToken(PUNC,yytext);  return '.';}
","		{PutToBuffer(yytext);PrintToken(PUNC,yytext);  return ',';} 
";"		{PutToBuffer(yytext);PrintToken(PUNC,yytext);  return ';';}

\n		{PutToBuffer(yytext); PrintSrc();ClearBuffer();lineCount++;}
		

(" ")|(\t)	{PutToBuffer(yytext);}
\0		{PrintEOFSrc();}

.		{}

%%


/*
int main(int argc , char* argv[]){

	yylex();


	return 0;
}
*/
int yywrap(){
	return 1;
}

void PutToBuffer(char* token){
	strcat(lineBuffer,token);
}

void ClearBuffer(){
	memset(lineBuffer,0,50000);
}

void PrintToken(PTYPE t,char* text){
	
	if(tokenOn==1){
		switch(t){
			case KEY:
				printf("#key:%s\n",text);
				break;
			case ID:
				printf("#id:%s\n",text);
				break;
			case OP:
				printf("#op:%s\n",text);
				break;
			case PUNC:
				printf("#punc:%s\n",text);
				break;
			case INTEGER:
				printf("#integer:%s\n",text);
				break;
			case L_DOUBLE:
				printf("#double:%s\n",text);
				break;
			case CHARACTER:
				printf("#char:%s\n",text);
				break;
			case SCI:
				printf("#sci:%s\n",text);
				break;
			case STRING:
				printf("#string:%s\n",text);
				break;
			default:
				Error();
		}
	}
	
}

void PrintSrc(){
	if(srcOn==1){
		printf("%d:%s",lineCount,lineBuffer);
	}
}

void PrintEOFSrc(){
	if(srcOn==1&&strlen(lineBuffer)>0){
		printf("%d:%s",lineCount,lineBuffer);
		printf("\n");
	}
}

void Error(){
	fprintf(stderr,"Error at line %d: %s\n",lineCount,yytext);exit(1);
}


char* mstrcpy2(char* s2){
	char* s1;
 	s1 = (char*) malloc(sizeof(char) * (strlen(s2)+10));
	strcpy(s1,s2);
	printf("s1:%s\n",s1);
	return s1;
}

void mstrcpy(char* s1, char* s2){
}
