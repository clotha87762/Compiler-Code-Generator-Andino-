
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
//void mstrcpy(char * s1, char* s2);
char* mstrcpy(char* s2);
int init_index = 0;
int now_reg = 0;
int expr_stack_offset;
int expr_temp_offset;
int needed_space = 0;
int reg[11] = {0};
int labelCount = 0;
int labelIndex[1000] = {0};
int claimed_label;
FILE* f_asm ;

#define EXPR_LOAD \
    int r1 , r2; \
    r1 =load_expr(o1,0); \
    if(r1==1){ \
     r1 = 0; \
    } \
    else{ \
     r1 = -o1; \
    } \
    r2= load_expr(o3,1);\
    if(r2==1){ \
     r2 = 1; \
    } \
    else{ \
     r2 = -o3; \
    }

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
%type <ival> blink 
%type <ival> while_stmt if_stmt else_x

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
       $$ = mstrcpy($1);
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
	  table[i].ival = $4.ival;  
          init_index++;
           /* gen code*/
          if($4.offset>=0){
            gen_lwi(0,$4.offset);
            gen_swi(0,stack_cur_offset);
            stack_cur_offset ++;
          }
          else{
            gen_swi($4.offset*(-1),stack_cur_offset);
            stack_cur_offset++;
          }

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
     
         install_symbol($1);
	
          int i = look_up_symbol($1); 
	        table[i].ival = $2.ival;
          table[i].mtype  = $2.type;  

          init_index++;
          /* gen code*/
	          printf("qq%d\n",$2.offset);
	        if($2.offset>=0){
            gen_lwi(0,$2.offset);
            gen_swi(0,stack_cur_offset);
            stack_cur_offset ++;
          }
          else{
            gen_swi($2.offset*(-1),stack_cur_offset);
	    stack_cur_offset++;
          }
	  
          }
        | IDEN              { 
   
	        Check_Var_Not_Exist($1);
          // put value into stack
          install_symbol($1);
          init_index++;
          stack_cur_offset++;

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
      int r = get_reg();
	printf("rrrr%d\n",r);
      if(r<0){
        $$.offset = expr_stack_offset++;
        gen_movi(0,$$.ival);
        gen_swi(0,$$.offset);
      }
      else{
	$$.offset = -r;
 	gen_movi(r,$$.ival);
      }
      
    }
  | var        { 
      $$.sval = mstrcpy($1);
      int i = look_up_symbol($1); 
      $$.type = table[i].mtype; 
      $$.ival=  table[i].ival;  
      //$$.offset = table[i].stack_offset; 
      int r = get_reg();
      if(r<0){
         $$.offset = table[i].stack_offset;
      }
      else{
         gen_lwi(r,table[i].stack_offset);
         $$.offset = -r;
      }
  }
  | var PLUSPLUS           { 
    $$.sval = mstrcpy($1);

    int i = look_up_symbol($1);
    $$.type = table[i].mtype; 
    $$.ival = table[i].ival;
    table[i].ival++; 
    /* add origin var &  */ 
    int r = get_reg();
    if(r<0){
        $$.offset = expr_stack_offset++;
        gen_lwi(0,table[i].stack_offset);
        gen_swi(0,$$.offset);

        gen_addi(0,0,1);
        gen_swi(0,table[i].stack_offset);

    }
    else{
        $$.offset = -r;
        gen_lwi(0,table[i].stack_offset);
        gen_addi(0,0,1);
        gen_swi(0,table[i].stack_offset);
    }


  }
  | var MINUSMINUS          { 
    $$.sval = mstrcpy($1);
    int i = look_up_symbol($1);
    $$.type = table[i].mtype; 
    $$.ival = table[i].ival;
    table[i].ival--; 
    /* add origin var &  */ 
    int r  = get_reg();
    if(r<0){
        $$.offset = expr_stack_offset++;
        gen_lwi(0,table[i].stack_offset);
        gen_swi(0,$$.offset);

        gen_subi(0,0,1);
        gen_swi(0,table[i].stack_offset);

    }
    else{
        $$.offset = -r;
        gen_lwi(0,table[i].stack_offset);
        gen_subi(0,0,1);  // maybe there isn't negative addi ?????
        gen_swi(0,table[i].stack_offset);
    }

    }
//  | func_invoke            {}
  | IDEN '(' exprs_comma_x ')'   { }
 // | var '=' IDEN '(' exprs_comma_x ')'  {} 
  | expr '+' expr          { 

    $$.type = $1.type; 
    $$.ival = $1.ival + $3.ival; 
    //$$.offset = expr_stack_offset++; 
    /* generate code*/
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_add(0,r1,r2);
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
    }
  |  expr '-' expr         {
    $$.type = $1.type; 
    $$.ival = $1.ival - $3.ival;
    //$$.offset = expr_stack_offset++;
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD

    gen_sub(0,r1,r2);
    int x = save_expr($1.offset,$3.offset);
    $$.offset =x;
    }
  |  expr '*' expr         {
   $$.type = $1.type; 
   $$.ival = $1.ival * $3.ival; 
  // $$.offset = expr_stack_offset++;
  int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD

    gen_mul(0,r1,r2);
    int x=save_expr($1.offset,$3.offset);
    $$.offset = x; 
  }
  |  expr '/' expr         { 
  $$.type = $1.type;
 // printf("!!!!%d\n",$3.ival);
  $$.ival = $1.ival / $3.ival; 
  //$$.offset = expr_stack_offset++;
  int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD

    gen_divsr(0,1,r1,r2);
    int x= save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  expr '%' expr          { 
    $$.type = $1.type; 
    $$.ival = $1.ival % $3.ival;  
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD

    gen_divsr(1,0,r1,r2);
    int x=save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  expr '>' expr          {
    $$.type = 4;
     int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_slts(0,r2,r1);
    gen_zeb(0,0);                           // IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;

   }
  |  expr '<' expr          {
     $$.type = 4;
     int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_slts(0,r1,r2);
    gen_zeb(0,0);            // IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  expr GE expr           { 
    $$.type = 4;
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_slts(0,r1,r2);
    gen_sltsi(0,0,1);
    gen_zeb(0,0);            // IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  expr LE expr          { 
    $$.type = 4;
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_slts(0,r2,r1);
    gen_sltsi(0,15,1);  
    gen_zeb(0,0);                  // IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  expr EQUAL expr       { 
    $$.type = 4;
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_xor(0,r1,r2);
    gen_slti(0,0,1);
    gen_zeb(0,0);
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
    
  }
  |  expr NOTEQUAL expr    { $$.type = 4; 
    $$.type = 4;
    int o1 = $1.offset;
    int o3 = $3.offset;
    EXPR_LOAD
    gen_xor(0,r1,r2);
    gen_movi(1,0);
    gen_slt(0,1,0);
    gen_zeb(0,0);
    int x = save_expr($1.offset,$3.offset);
    $$.offset = x;
  }
  |  NOT expr             { 
     $$.type = 4;
     int r = load_expr($2.offset,0);
     if(r==1){
       r= 0;
     }
     else{
       r= -$2.offset;
     }
     gen_slti(0,r,1);
     gen_zeb(0,0);
     
     if( r==0 ){
        gen_swi(0,$2.offset);
     }
     else{
        gen_ori(r,0,0);
     }

     $$.offset = $2.offset;

  }
  |  expr ANDAND expr     { 
      $$.type = 4; 
      int o1 = $1.offset;
    int o3 = $3.offset;
      EXPR_LOAD
      int l = labelCount;
      labelCount += 2;
      gen_beqz(r1,l);
      gen_beqz(r2,l);
      gen_movi(0,1);
      gen_j(l+1);
      gen_label(l);
      gen_movi(0,0);
      gen_label(l+1);
      int x = save_expr($1.offset,$3.offset);
      $$.offset = x;
  }
  |  expr OROR expr         {
     $$.type = 4;  
     int o1 = $1.offset;
    int o3 = $3.offset;
     EXPR_LOAD
     int l = labelCount;
     labelCount +=3;
     gen_bnez(r1,l);
     gen_beqz(r2,l+1);
     gen_label(l);
     gen_movi(0,1);
     gen_j(l+2);
     gen_label(l+1);
     gen_movi(0,0);
     gen_label(l+2);
    
     int x = save_expr($1.offset,$3.offset);
     $$.offset = x;

  }
  |  '-' expr %prec UMINUS   {
    $$.type = $2.type; 
    $$.ival = $2.ival * (-1);
     int r = load_expr($2.offset,0);
     if(r==1){
       r= 0;
     }
     else{
       r= -$2.offset;
     }
     gen_subri(0,r,0);

     if( r==0 ){
        gen_swi(0,$2.offset);
     }
     else{
        gen_ori(r,0,0);
     }

     $$.offset = $2.offset;
  }
  | '(' expr ')'            {
	 $$.type = $2.type; 
	$$.ival = $2.ival; 
	$$.offset = $2.offset;
	 //gen_lwi(0,$2.offset);
	//gen_swi(0,$$.offset);
	}
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
 if($4.offset>=0){
  gen_lwi(0,$4.offset);
 }
 else{
  gen_ori(0,$4.offset*(-1),0);
 }
 gen_swi(0,table[i].stack_offset);
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


if_stmt: IF {Init_Expr();} '('  expr { End_Expr();}')'{
   
   int L = labelCount;
   labelCount ++;
   push_lstack(L);
   if($4.offset>=0){
        gen_lwi(0,$4.offset);
        gen_slti(0,0,1);
        gen_bnez(0,L);
   }
   else{
      gen_slti(0,-$4.offset,1);
      gen_bnez(0,L);
   }

}  else_x {
   
}
;

else_x: compound {
		int L = pop_lstack();
		gen_label(L);
	}
	|
	compound ELSE{
		int L = labelCount;
		labelCount++;		
		gen_j(L);
		int L2 = pop_lstack();
		gen_label(L2);
		push_lstack(L);
	 }
	compound{
		 int L = pop_lstack();
		 gen_label(L);
	} 
	;

while_stmt: WHILE '(' {Init_Expr(); } expr {
	End_Expr(); 
	int L  = labelCount++;
	int L2 = labelCount++; 
	gen_j(L2);
	 gen_label(L) ;
	 push_lstack(L);
	 push_lstack(L2);
	}
	')' compound  {
	int L2 = pop_lstack();
	int L =  pop_lstack(); 
        gen_label(L2);
        if($4.offset>=0){
           gen_lwi(0,$4.offset);
           gen_slti(0,0,1);
           gen_beqz(0,L);
        }
        else{
           gen_slti(0,-$4.offset,1);
           gen_beqz(0,L);
        }
      
      }
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

blink : DIGITAL_WRITE '('{ Init_Expr();} expr ',' INT_LIT ')' ';'{
        End_Expr();
        if($4.offset>=0){
        gen_lwi(0,$4.offset);
        }
        else{
        gen_ori(0,$4.offset*(-1),0);
        }
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
	if($4.offset>=0){
        gen_lwi(0,$4.offset);
        }
        else{
        gen_ori(0,$4.offset*(-1),0);
        }
	gen_bal("delay");
        
     }
     ;





%%

int main(void)
{
    reg[0] = 1; // set reg 0, 1 ,5 not usable
    reg[1] = 1;
    reg[5] = 1;   
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
     fprintf(f_asm,"\n");
     fprintf(f_asm," addi $sp, $sp, -%d\n",(stack_cur_offset + needed_space + 10)*4);
     fprintf(f_asm,"%s",output);
     fprintf(f_asm," addi $sp, $sp, %d\n",(stack_cur_offset + needed_space +10)*4 );
}

void Init_Expr(){
  expr_stack_offset = stack_cur_offset;
}

void End_Expr(){
    int i;
    for(i=2;i<11;i++){
      reg[i] = 0;
    }
    reg[5] = 1;
    if( expr_stack_offset - stack_cur_offset + 1 > needed_space){
    needed_space = expr_stack_offset - stack_cur_offset + 1; 
    }
    
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

void gen_subi(int r0, int r1, int con){
    char temp[1000];
    sprintf(temp," subi $r%d, $r%d, %d\n",r0,r1,con);
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
void gen_ori(int r1,int r2, int cons){
    char temp[1000];
    sprintf(temp," ori $r%d, $r%d, %d\n",r1,r2,cons);
    strcat(output,temp);

}

void gen_beqc(int r1,int cons,int i){
    char temp[1000];
    sprintf(temp," beqc $r%d, %d, L%d\n",r1,cons,i);
    strcat(output,temp);
}

void gen_bnec(int r1,int cons,int i){
    char temp[1000];
    sprintf(temp," bnec $r%d, %d, L%d\n",r1,cons,i);
    strcat(output,temp);
}

void gen_beq(int r1,int r2,int i){
    char temp[1000];
    sprintf(temp," beq $r%d, $r%d, L%d\n",r1,r2,i);
    strcat(output,temp);
}

void gen_bne(int r1,int r2,int i){
  char temp[1000];
    sprintf(temp," bne $r%d, $r%d, L%d\n",r1,r2,i);
    strcat(output,temp);
}

void gen_bnez(int q,int i){
  char temp[1000];
   sprintf(temp," bnez $r%d, L%d\n",q,i);
   strcat(output,temp);
}

void gen_sltsi(int q ,int r , int cons){
  char temp[1000];
   sprintf(temp," sltsi $r%d, $r%d,  %d\n",q,r,cons);
   strcat(output,temp);
}

void gen_slts(int q,int r1,int r2){
   char temp[1000];
   sprintf(temp," slts $r%d, $r%d, $r%d\n",q,r1,r2);
   strcat(output,temp);
}


void gen_slt(int q,int r1,int r2){
   char temp[1000];
   sprintf(temp," slt $r%d, $r%d, $r%d\n",q,r1,r2);
   strcat(output,temp);
}

void gen_slti(int r0,int r1,int cons){
  char temp[1000];
  sprintf(temp," slti $r%d, $r%d, %d\n",r0,r1,cons);
  strcat(output,temp);
}

void gen_beqz(int q,int i){
  char temp[1000];
   sprintf(temp," beqz $r%d, L%d\n",q,i);
   strcat(output,temp);
}

void gen_j(int i){
   char temp[1000];
   sprintf(temp," j L%d\n",i);
   strcat(output,temp);
}

void gen_zeb(int r1,int r2){
   char temp[1000];
   sprintf(temp," zeb $r%d, $r%d\n",r1,r2);
   strcat(output,temp);
}
 
void gen_subri(int r1,int r2,int cons){
  char temp[1000];
   sprintf(temp," subri $r%d, $r%d, %d\n",r1,r2,cons);
   strcat(output,temp);
}

void gen_xor(int r0,int r1,int r2){
  char temp[1000];
   sprintf(temp," xor $r%d, $r%d, $r%d\n",r0,r1,r2);
   strcat(output,temp);
}

void gen_label(int i){
   char temp[1000];
   sprintf(temp,"L%d:\n",i);
   strcat(output,temp);
}


int get_reg(){
  int i=0;
  for(i=2;i<5;i++){
      if(reg[i]==0){
        reg[i] = 1;
        return i;
      }
  }
  return -1;
}

void pop_instruction(){
   int i;
   i = strlen(output)-1;
   char c ;
   do{
	c = output[i];
	output[i] = '\0';
	
   }while(c!='\n');
   c= output[strlen(output)-1];
   while(c!='\n'){
	output[strlen(output)-1] = '\0';
	c = output[strlen(output)-1];
   }
}

int load_expr(int x , int r){
    //if(x<0){
  //    gen_addi(r,-x);
//	}
    //else{
      if(x>=0){
	gen_lwi(r,x);
      	return 1;
      }
   return 0;
  //  }
}


int  save_expr(int x , int y){
    if(x<0){
        gen_ori(-x,0,0);
        reg[-y] = 0; 
	return x;
    }
    else if(y<0){
        gen_ori(-y,0,0);
        reg[-x] = 0;
	return y;
    }
    else{
        gen_swi(0,x);
	return x;
    }
}

