
/* This is a simpled gcc grammar */
/* Copyright (C) 1987 Free Software Foundation, Inc. */
/* BISON parser for a simplied C by Jenq-kuen Lee  Sep 20, 1993    */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "type.h"
char output[300000];

extern char* yytext;
extern int lineCount;
extern char lineBuffer[50000];
char   *install_symbol();
void mstrcpy(char * s1, char* s2);
int init_index = 0;
int now_reg = 0;
int expr_stack_offset;
int expr_temp_offset;
int needed_space = 0;
FILE* f_asm ;

%}

%start program
%union { 
         int       ival ;
         char      cval ;
         char      * sval;
         double     dval;
	 int	    bval;
         lit_type   lit;
     
       }

%token <sval>  IDEN  STRING_LIT
%token <ival> INT_LIT BOOL_LIT 
%token <ival> INT DOUBLE BOOL CHAR VOID STRUCT
%token <ival> CONST SWITCH CASE DEFAULT IF ELSE FOR WHILE DO RETURN CONTINUE BREAK NUL TRUE FALSE
%token <ival> PLUSPLUS MINUSMINUS ANDAND OROR GE LE EQUAL NOTEQUAL NOT
%token <cval> CHAR_LIT 
%token <dval> DOUBLE_LIT
%token <ival> HIGH LOW DIGITAL_WRITE DELAY

%type <lit> literal expr init const_init
%type <sval> var
%type <ival> type
%type <ival> blink lowhigh

%left <ival> OROR
%left <ival> ANDAND
%left <ival> NOT
%left <ival> '>' '<' EQUAL NOTEQUAL GE LE
%left <ival> '+' '-'
%left <ival> '*' '/' '%'
%right <ival> UMINUS
%left <ival> PLUSPLUS MINUSMINUS





%%






program :  first_func_def  extdefs    {
     printf("No syntax error!\n");
     Write_Assembly();
    }
    	|  extdefs_no_func  first_func_def extdefs	{printf("No syntax error!\n");Write_Assembly();}
	| first_func_def  {printf("No syntax error!\n");Write_Assembly();}
	|  extdefs_no_func first_func_def {printf("No syntax error!\n");Write_Assembly();}
	;


var : IDEN indexs       {
      Check_Var_Exist($1);
      /* supposely, there should be no array.........*/
   }
   | IDEN               {
      Check_Var_Exist($1);
      mstrcpy($$,$1);
   }
   ;

//extdefs_no_func_x: /* empty */        {}
 //       |  extdefs_no_func          {}
//        ;

extdefs_no_func : extdefs_no_func  extdef_no_func        {}
        | extdef_no_func            {}
        ; 

extdef_no_func: type  IDEN '('  para_in ')' ';'    {}   // function declaration
  | VOID  IDEN '('  para_in ')' ';'    {}  
  | type iden_list_init  ';'    {
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = $1;
        }
        else if(table[cur_counter-1-i].mtype != $1){
           Init_Type_Not_Match();
        }
     }
     init_index = 0;
  }
  | CONST type const_iden_list ';'      {}
  ;

iden_list_init: iden_list_init ','  IDEN            {
          Check_Var_Not_Exist($3);
          /* put value into stack */
          install_symbol($3);   
          //stack_cur_offset++; 
          init_index++;
         stack_cur_offset++;
  }
	| iden_list_init ',' IDEN init                   { 
        Check_Var_Not_Exist($3);
        /* put value into stack */
         install_symbol($3);
          int i = look_up_symbol($3); 
          table[i].mtype  = $4.type;  
          init_index++;
           /* gen code*/
          gen_lwi(0,$4.offset);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;
   }
	| iden_list_init ','  IDEN indexs_dec array_init       {}
        | iden_list_init ','  IDEN indexs_dec         {}
	| IDEN init               { 
	printf("b\n");
         Check_Var_Not_Exist($1);
         // put value into stack
         printf("b1\n"); 
         install_symbol($1);
	 printf("b11\n");
          int i = look_up_symbol($1); 
          table[i].mtype  = $2.type;  
          init_index++;
          /* gen code*/
	  printf("b2\n");
          gen_lwi(0,$2.offset);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;
	  printf("bbb\n");
          }
        | IDEN              { 
          printf("a\n");
	  Check_Var_Not_Exist($1);
          // put value into stack
          install_symbol($1);
          init_index++;
          stack_cur_offset++;
	  printf("aa\n");
          }
	| IDEN indexs_dec array_init        {}
        | IDEN indexs_dec   {}
	;

const_iden_list : const_iden_list ','  IDEN const_init     
        {  
          Check_Var_Not_Exist($3);
          install_symbol($3);
          /* put value into stack*/
          stack_cur_offset++; 
          int i = look_up_symbol($3); 
          table[i].mtype  = $4.type;  
          init_index++;
          /* gen code*/
          gen_movi(0,$4.ival);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;

        }
        | IDEN const_init         { 
            
          Check_Var_Not_Exist($1);
          install_symbol($1);
          /* put value into stack*/
          stack_cur_offset++; 
          int i = look_up_symbol($1); 
          table[i].mtype  = $2.type;  
          init_index++;
           /* gen code*/
          gen_movi(0,$2.ival);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;

          }
        ;

const_init : '=' literal        {
  
  $$.type = $2.type; 
  if($$.type==0){
    $$.ival = $2.ival;
  } 
  else if($$.type==1){
    $$.dval = $2.dval;
  }
  else if($$.type==2){
    $$.cval = $2.cval;
  }
  else if($$.type==4){
    $$.bval = $2.bval;
  }

  }
  ;


//extdefs_x: /* empty */      {}
//    |  extdefs           {}
//    ;

extdefs: extdefs extdef    {}
    | extdef               {}
    ; 


extdef: type  IDEN '('  para_in ')' ';'     {}  // function declaration
  | VOID  IDEN '('  para_in ')' ';'     {}  // function declaration
  | func_def                 {}
  | type iden_list_init  ';'       {}
  | CONST type const_iden_list ';'        {}
  ;

decs_x : /* empty */          {}
     | decs               {}
     ;


decs :  decs  dec        {}
   |  dec               {}
   ;

dec:   type iden_list_init  ';'       {}
     | CONST type const_iden_list ';'     {}
     ;

expr_x : /* empty */           {}
    | expr                 {}
    ;

expr: literal               {
    $$.type = $1.type; 
    $$.ival = $1.ival; 
    $$.offset = expr_stack_offset++;
    gen_movi(0,$$.ival);
    gen_swi(0,$$.offset);
    }
  | var                     { 
      mstrcpy($$.sval,$1);
      int i = look_up_symbol($1); 
      $$.type = table[i].mtype; 
      $$.ival=table[i].ival;  
      $$.offset = table[i].stack_offset; 
     // gen_lwi(0,table[i].stack_offset);
     // gen_swi(0,$$.offset);
  }
  | var PLUSPLUS           { 
    mstrcpy($$.sval,$1);
    int i = look_up_symbol($1);
    $$.type = table[i].mtype; 
    $$.ival = table[i].ival;
    table[i].ival++; 
    /* add origin var &  */ 
    $$.offset = table[i].stack_offset;//expr_stack_offset++; 
   // gen_lwi(0,table[i].stack_offset);
    //gen_swi(0,$$.offset);
    }
  | var MINUSMINUS          { 
    mstrcpy($$.sval,$1);
    int i = look_up_symbol($1);
    $$.type = table[i].mtype; 
    $$.ival = table[i].ival;
    table[i].ival--; 
    /* add origin var &  */ 
    $$.offset = table[i].stack_offset;//expr_stack_offset++; 
    //gen_lwi(0,table[i].stack_offset);
    //gen_swi(0,$$.offset);
    }
//  | func_invoke            {}
  | IDEN '(' exprs_comma_x ')'   { }
 // | var '=' IDEN '(' exprs_comma_x ')'  {} 
  | expr '+' expr          { 
    $$.type = $1.type; 
    $$.ival = $1.ival + $3.ival; 
    $$.offset = expr_stack_offset++; 
    /* generate code*/

    gen_lwi(0,$1.offset);
    gen_lwi(1,$3.offset);
    gen_add(0,0,1);
    gen_swi(0,$$.offset);
    }
  |  expr '-' expr         {
    $$.type = $1.type; 
    $$.ival = $1.ival - $3.ival;
    $$.offset = expr_stack_offset++;

    gen_lwi(0,$1.offset);
    gen_lwi(1,$3.offset);
    gen_sub(0,0,1);
    gen_swi(0,$$.offset);
    }
  |  expr '*' expr         {
   $$.type = $1.type; 
   $$.ival = $1.ival * $3.ival; 
   $$.offset = expr_stack_offset++;

    gen_lwi(0,$1.offset);
    gen_lwi(1,$3.offset);
    gen_mul(0,0,1);
    gen_swi(0,$$.offset);
   }
  |  expr '/' expr         { 
  $$.type = $1.type;
  $$.ival = $1.ival / $3.ival; 
  $$.offset = expr_stack_offset++;

   gen_lwi(2,$1.offset);
    gen_lwi(3,$3.offset);
    gen_divsr(0,1,2,3);
    gen_swi(0,$$.offset);
  }
  |  expr '%' expr          { 
    $$.type = $1.type; 
    $$.ival = $1.ival % $3.ival;  
     $$.offset = expr_stack_offset++;

    gen_lwi(2,$1.offset);
    gen_lwi(3,$3.offset);
    gen_divsr(0,1,2,3);
    gen_swi(1,$$.offset);
  }
  |  expr '>' expr          { $$.type = 4; if($1.ival > $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr '<' expr          { $$.type = 4; if($1.ival < $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr GE expr           { $$.type = 4; if($1.ival >= $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr LE expr          { $$.type = 4;  if($1.ival <= $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr EQUAL expr       { $$.type = 4;  if($1.ival == $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr NOTEQUAL expr    { $$.type = 4;   if($1.ival != $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  NOT expr             { $$.type = 4;   if($2.ival !=0){$$.ival = 0;}else{$$.ival = 1;} $$.offset = expr_stack_offset++;}
  |  expr ANDAND expr     { $$.type = 4;   if($1.ival && $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  expr OROR expr         {$$.type = 4;   if($1.ival || $3.ival){$$.ival = 1;}else{$$.ival = 0;} $$.offset = expr_stack_offset++;}
  |  '-' expr %prec UMINUS   {$$.type = $2.type; $$.ival = $2.ival * (-1); $$.offset = expr_stack_offset++;}
  | '(' expr ')'            { $$.type = $2.type; $$.ival = $2.ival; $$.offset = expr_stack_offset++;}
  //| '(' var ')' PLUSPLUS    {}
  //| '(' var ')' MINUSMINUS  {}
  ; 



expr_no_invoke: literal     {}
  | var                     {}
  | var PLUSPLUS            {}
  | var MINUSMINUS          {}
  | expr_no_invoke '+' expr_no_invoke          {}
  |  expr_no_invoke '-' expr_no_invoke         {}
  |  expr_no_invoke '*' expr_no_invoke         {}
  |  expr_no_invoke '/' expr_no_invoke         {}
  |  expr_no_invoke '%' expr_no_invoke          {}
  |  expr_no_invoke '>' expr_no_invoke          {}
  |  expr_no_invoke '<' expr_no_invoke          {}
  |  expr_no_invoke GE expr_no_invoke           {}
  |  expr_no_invoke LE expr_no_invoke          {}
  |  expr_no_invoke EQUAL expr_no_invoke       {}
  |  expr_no_invoke NOTEQUAL expr_no_invoke    {}
  |  NOT expr_no_invoke             {}
  |  expr_no_invoke ANDAND expr_no_invoke     {}
  |  expr_no_invoke OROR expr_no_invoke         {}
  |  '-' expr_no_invoke %prec UMINUS   {}
  | '(' expr_no_invoke ')'            {}
  //| '(' var ')' PLUSPLUS    {}
  //| '(' var ')' MINUSMINUS  {}
  ;



stmts_x : /* empty */    {}
    | stmts   {}
    ;

stmts:  stmts  stmt   {}
    | stmt     {}
    ;

stmt: var '=' {  Init_Expr();   } expr ';'    { 
 int i = look_up_symbol($1); 
 table[i].ival = $4.ival;
 End_Expr(); 
 /* should  implicit type conversion ??*/  
 gen_lwi(1,$4.offset);
 gen_swi(1,table[i].stack_offset);
 /* push var back*/ 
 }
  |  blink          {}
  |  if_stmt        {}
  |  while_stmt     {}
  |  switch_stmt    {}
  |  for_stmt      {}
  //| func_invoke     {}
  //| var  '=' IDEN '(' exprs_comma_x ')' ';'
  | IDEN '(' exprs_comma_x ')' ';'
  | RETURN expr ';'   {}
  | BREAK ';'       {}
  | CONTINUE ';'    {}
  ;


if_stmt: IF '(' expr ')' compound ELSE compound   {}
     	| IF '(' expr ')' compound {}
	;


while_stmt: WHILE '(' expr ')' compound      {}
      | DO compound WHILE '(' expr ')' ';'  {}
      ;
 
for_stmt : FOR '(' expr_x ';' expr_x ';' expr_x  ')' compound   {}
         ;
switch_stmt : SWITCH '(' IDEN ')' '{' cases default_x '}'   {}
	;
cases: cases case  {}
   | case         {}
   ;

case: CASE CHAR_LIT ':' stmts_x   {}
   | CASE INT_LIT ':' stmts_x     {}
   ;  

default_x: /* empty */    {}
     |  DEFAULT ':' stmts_x   {}
     ;




//func_invoke: IDEN '('  exprs_comma_x ')' ';'     {printf("101\n");}
//       | var '=' IDEN '(' exprs_comma_x ')' ';'     {printf("102\n");}          //  這邊我把 IDEN -> VAR
//          ;


first_func_def : type IDEN '(' para_in ')' compound  {}
	       |  VOID  IDEN '(' para_in ')' compound {}
		;
func_def: type IDEN '(' para_in ')' compound   {}
	| VOID  IDEN '(' para_in ')' compound {}
	;
compound: '{'  decs_x stmts_x  '}'    {}
	;


exprs_comma_x: /* empty */    {}
    | exprs_comma     {}
    ;

exprs_comma: exprs_comma ',' expr     {}
  | expr    {}
  ;

exprs_comma_no_invoke_x : /* empty */    {}
              | exprs_comma_no_invoke   {}
              ;

exprs_comma_no_invoke : exprs_comma_no_invoke ',' expr_no_invoke   {}
            | expr_no_invoke   {}
            ; 


init :  '=' { Init_Expr(); }expr /* change to expr */  { 
    
    End_Expr();
    $$.type = $3.type;
    $$.offset = $3.offset;
    $$.ival = $3.ival;
    
    //gen_lwi(0,$2.offset);
  }
  ;

array_init: '=' '{' exprs_comma_no_invoke_x '}'  {}
      ;

para_in : /* empty */  {}
    |  paras   {}
    ;

paras:  paras ',' para  {}
   |  para  {}
   ;

para: type IDEN indexs_dec  {}
   |  type IDEN
   ;

//indexs_dec_x: /* empty */ {printf("123\n");}
//     |  indexs_dec  {printf("124\n");}
//     ;

indexs_dec: indexs_dec  index_dec  {}
    | index_dec  {}
    ;

index_dec: '[' INT_LIT ']'  {}
	;
//indexs_x :/* empty */   {}
//    | indexs   {}
//    ;

indexs: indexs index  {}
    | index   {}
    ;

index: '[' expr ']' {}
   ;


type : INT    { $$ = 0;}
    | DOUBLE   { $$ = 1;}
    | CHAR    { $$ = 2;}
    | BOOL    { $$ = 4;}
    ; 
 

literal: CHAR_LIT { $$.type = 2; $$.cval = $1;}
     | INT_LIT    { $$.type = 0; $$.ival = $1;}
     | DOUBLE_LIT  { $$.type = 1; $$.dval = $1;}
     | BOOL_LIT    { $$.type = 4; $$.bval = $1;}
     | STRING_LIT  {  /* no array or pointer, so no string */ }
     ;

blink : DIGITAL_WRITE '('{ Init_Expr();} expr ',' lowhigh ')' ';'{
        End_Expr();
        gen_lwi(0,$4.offset);
	if($6 == 1){
        gen_movi(1,1);
	}
	else{
	gen_movi(1,0);
	}
        gen_bal("digitalWrite");

        }
     | DELAY '('{Init_Expr();} expr ')' ';'{
        End_Expr();
        gen_lwi(0,$4.offset);
        gen_bal("delay");

     }
     ;

lowhigh : LOW{$$ = $1;}
	| HIGH{ $$ = $1;}
	;



%%

int main(void)
{
    
    init_symbol_table();
    yyparse();
    return 0;
}

/*
 *	  s - the error message to be printed
 */
void  yyerror(char* msg)
{
   fprintf( stderr, "*** Error at line %d: %s\n", lineCount, lineBuffer );
   fprintf( stderr, "\n" );
   fprintf( stderr, "Unmatched token: %s\n", yytext );
   fprintf( stderr, "*** syntax error\n"); 
   exit(-1); 
}

void Write_Assembly(){
     f_asm = fopen("assembly","w");
     fprintf(f_asm," addi $sp, $sp, -%d\n",(stack_cur_offset + needed_space + 5)*4);
     fprintf(f_asm,"%s",output);
     fprintf(f_asm," addi $sp, $sp, %d\n",(stack_cur_offset + needed_space +5)*4 );
}

void Init_Expr(){
  expr_stack_offset = stack_cur_offset;
}

void End_Expr(){
    needed_space = expr_stack_offset - stack_cur_offset + 1;
}


void Init_Type_Not_Match(){
  fprintf( stderr ,"Error at line %d : Initialization type not matched with declaration type\n",lineCount);
}

void Check_Var_Not_Exist(char* s){
  int i = look_up_symbol(s);
  if(i>=0 && table[i].scope == cur_scope){
    fprintf(stderr, " Error at line %d :Re-declaration of already used variable name in a same scope\n",lineCount);
  }
}

void Check_Var_Exist(char *s){
  int i = look_up_symbol(s);
  if(i<0){
    fprintf(stderr,"Error ar line %d :Use a variable before it is declared!!\n",lineCount);
  }
}

void gen_add(int r0 , int r1 , int r2){
  char temp[1000];
  sprintf(temp," add $r%d, $r%d, $r%d\n",r0,r1,r2);
  strcat(output,temp);
}

void gen_addi(int r0, int r1, int con){
    char temp[1000];
    sprintf(temp," addi $r%d, $r%d, %d\n",r0,r1,con);
    strcat(output, temp);
}

void gen_sub(int r0 , int r1 , int r2){
    char temp[1000];
    sprintf(temp," sub $r%d, $r%d, $r%d\n",r0,r1,r2);
   strcat(output,temp);
}

void gen_mul(int r0 , int r1 , int r2){
  char temp[1000];
  sprintf(temp," mul $r%d, $r%d, $r%d\n",r0,r1,r2);
  strcat(output,temp);
}

void gen_divsr(int r0 , int r1 , int r2 , int r3){
   char temp[1000];
   sprintf(temp," divsr $r%d, $r%d, $r%d, $r%d\n",r0,r1,r2,r3);
  strcat(output,temp);
}

void gen_movi(int r0,int con){
    char temp[1000];
    sprintf(temp," movi $r%d, %d\n",r0,con);
    strcat(output,temp);
}

void gen_lwi(int r0,int offset){
    char temp[1000];
    sprintf(temp," lwi $r%d, [$sp+(%d)]\n",r0,offset*4);
    strcat(output,temp);
}

void gen_swi(int r0,int offset){
    char temp[1000];
    sprintf(temp," swi $r%d, [$sp+(%d)]\n",r0,offset*4);
    strcat(output,temp);
}

void gen_jal(char *s){
    char temp[1000];
    sprintf(temp," jal %s\n",s);
    strcat(output,temp);
}

void gen_ret(){
    strcat(output," ret\n");
}

void gen_bal(char* s){
   char temp[1000];
    sprintf(temp," bal %s\n",s);
    strcat(output,temp);
}
