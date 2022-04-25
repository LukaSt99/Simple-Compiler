%{

/*Lluka Stojollari*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "defs.h"

	
int yylex();
int yyparse();

FILE *mips_data;
FILE *mips_text;
FILE *mips_code;

int i_if=0;
int i_while=0;
int i_for=0;

int divf=-1;
int addf=-1;
int subf=-1;
int multf=-1;
int facf=-1;

int divt=-1;
int addt=-1;
int subt=-1;
int multt=-1;
int fact=-1;

symbol *Cross_Link_Head[MAX_CROSS_LINKS];

typedef struct hash_tab {
   int numbsymbols;
   symbol *table[SYM_TABLE_SIZE];
} HASH_TAB;

HASH_TAB ht;

int TopOfStack=-1;
symbol *vs[30];

int Top_stack=-1;
AstNode *stack[100];

int Top_code_stack=-1;
AstNode *code_stack[100];

symbol *Symbol_free=NULL; 
symbol *p,*p1,*p2,*p3;
int  t[10] =  {0,0,0,0,0,0,0,0,0,0};
int  f[32] =  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int  s[8]  =  {0,0,0,0,0,0,0,0};
AstNode *TreeRoot;

%}

%union
{
    int   yint;
	float yfloat;
	char  ystr[81];
    struct AstNode_tag *stnode;
	
	struct{
		int a;
		float b;
		char *type;
		char  str[81];
	}val;

	struct{
	 int value;
	}type;
}

%token T_mainclass T_public T_static T_void T_main T_println T_for T_while T_if
%token T_if T_else T_comma T_plus T_minus
%token T_mult T_div T_semi T_lbrack T_rbrack T_lparen T_rparen T_e
%token <val>   int_num float_num 
%token <ystr>  id
%token <type>  T_int  T_float
%token <yint> T_eq T_lt T_gt T_le T_ge T_neq  

%type <stnode> Program Comp_Stmt Stmt_List Stmt Type Id_List Expr Bool_Expr 
%type <stnode> For_Stmt Opassign_Expr Opbool_Expr While_Stmt Declaration Null_Stmt
%type <stnode> If_Stmt Else_Part C_Op Rval Term Factor  I_D I_Dv Assign_Stmt Assign_Expr
%type <val> 	NUM 

%left T_plus T_minus
%left T_mult T_div 
%left UMINUS 

%right "THEN" T_else

%%                 


Program :   T_mainclass I_D T_lbrack T_public T_static T_void T_main T_lparen T_rparen Comp_Stmt T_rbrack 
	    {
				p1=new_symbol($2->SymbolNode->name);
				TreeRoot=MkNode(astProgram,p1,$2,$10,NULL,NULL);
				TreeRoot->available=1;
				TreeRoot->code_generation=0;
				
				char tmp[NAME_MAX+1];
				strcpy(tmp, $2->SymbolNode->name);

				mips_data = fopen(strcat($2->SymbolNode->name,".data"), "w+");
				fprintf(mips_data, "\n%s\n", ".data");
				fprintf(mips_data, "newline: .asciiz  \"\\n\"\n");
				
				
				
				strcpy($2->SymbolNode->name,tmp);
				
				mips_text = fopen(strcat($2->SymbolNode->name,".text"), "w+");
				fprintf(mips_text, "\n%s\n", ".text");
				strcpy($2->SymbolNode->name,tmp);
			
				code_generation($10);
				exe_Postorder($10);
				
				fclose(mips_data);
				fclose(mips_text);
				
				mips_data = fopen(strcat($2->SymbolNode->name,".data"), "r");
				strcpy($2->SymbolNode->name,tmp);
				mips_text = fopen(strcat($2->SymbolNode->name,".text"), "r");
				strcpy($2->SymbolNode->name,tmp);
				mips_code = fopen(strcat($2->SymbolNode->name,".s")   , "w+");
				
				char c;
			
				while ((c = fgetc(mips_data)) != EOF) {
					  fputc(c, mips_code); 		  
					  }
				while ((c = fgetc(mips_text)) != EOF) {
					  fputc(c, mips_code);
				      }
				 
				fclose(mips_data);
				fclose(mips_text);
				fclose(mips_code);
				
	    }
	    ;
	    
        
Comp_Stmt:  T_lbrack Stmt_List T_rbrack 
	    {
				$$=$2;
	    }	
	    ;
	   

Stmt_List: Stmt_List  Stmt 
	    {
				p1=new_symbol("stmt_list");
		 		$$=MkNode(astStmt_List,p1,$1,$2,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
	    }
	    | Stmt 
	    {
				$$=$1;
	    }
	    ;
	   

Stmt:   Assign_Stmt 
	    {
				$$=$1;
	    }
	    | For_Stmt 
	    {
				$$=$1;
	    }
	    | While_Stmt 
	    {
				$$=$1;
	    }
	    | If_Stmt
        {
				$$=$1;
	    }
	    | Comp_Stmt 
	    {
				$$=$1;
	    }
	    | Declaration  
	    {
				$$=$1;
	    }
	    | Null_Stmt   
	    {
				$$=$1;		
	    }
	    | T_println T_lparen Expr T_rparen T_semi
	    {
				p1=new_symbol("print");
				$$=MkNode(astStmt_print,p1,$3,NULL,NULL,NULL);	
				$$->available=1;
				$$->code_generation=0;
	    }
	    ;
	   
	   
Declaration: Type Id_List T_semi 
	    {                          			     
				$$=MkNode(astDeclaration,NULL,$1,$2,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
				p2=pop_vs();											
				p1=pop_vs();							       
				cpy_attributes(p2,p1);									
				p2=reverse_cross_links(p2);					   			
				Link_Symbol_to_Cross_Link(p2);								
				add_symbols_to_table(p2);								
				discard_symbol(p1);	
		}
	    ;
		
		
Type:    T_int  
	    {
				p1=new_symbol("");
				set_class_types(p1,10);
				p1->disposable=TRUE;
				$$=MkNode(astTYPE_INT,NULL,NULL,NULL,NULL,NULL); 
				$$->available=1;
				$$->code_generation=0;
				push_vs(p1);
				
	    }
	    | 
		T_float 
	    {
				$$=MkNode(astTYPE_FLOAT,NULL,NULL,NULL,NULL,NULL); 
				$$->available=1;
				$$->code_generation=0;
				p1=new_symbol("");
				set_class_types(p1,11);
				p1->disposable=TRUE;
				push_vs(p1);
	    }
	    ;
	   

Id_List:  Id_List T_comma I_D 
	    {		
				$$=MkNode(astIDList,NULL,$1,$3,NULL,NULL);\
				$$->available=1;
				$$->code_generation=0;
				p3=pop_vs();
				p1=pop_vs();
				p3->Next_in_Cross_Link=p1;
				push_vs(p3);			
	    }
	    | I_D 
	    {	
				$$=$1;			
		}
	    ;


Null_Stmt: T_semi 
	    {		
				$$=MkNode(astNULL_Stmt_Semicolon,NULL,NULL,NULL,NULL,NULL);	
	    }
	    ;
	   
	   
Assign_Stmt: Assign_Expr T_semi 
		{
				$$=$1;	
		}
	    ;
	   
	   
Assign_Expr: I_Dv T_e Expr 
		{		
				p=new_symbol("assign_expr");
				$$=MkNode(astAssign_Expr,p,$1,$3,NULL,NULL);
				$$->available=1;	
				$$->code_generation=0;				
		}
		;
		
		
Expr:  Assign_Expr 
	    {
				$$=$1;
	    }
	    | Rval 
	    {
				
				$$=$1;
				
	    }
	    ;


For_Stmt:  T_for T_lparen Opassign_Expr T_semi Opbool_Expr T_semi Opassign_Expr T_rparen Stmt
	    {
				$$=MkNode(astFor_Stmt,NULL,$3,$5,$7,$9);
				$5->previous=$$;
				$$->available=1;
				$$->code_generation=0;
				
	    }
	    ; 


Opassign_Expr:Assign_Expr
	    {
				$$=$1;
		
	    }
	    | /*empty*/
	    {
	   
				$$=MkNode(astEMPTY_Opassign_Expr,NULL,NULL,NULL,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
		
	    }
	    ;


Opbool_Expr: Bool_Expr
	    {
				$$=$1;
	    }
 	    | /*empty*/
	    {
				
				$$=MkNode(astEMPTYOpbool_Expr,NULL,NULL,NULL,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
	    }
	    ;


While_Stmt: T_while T_lparen Bool_Expr T_rparen Stmt
	    {   	
				$$=MkNode(astWhile_Stmt,NULL,$3,$5,NULL,NULL);
				$3->previous=$$;
				$$->available=1;
				$$->code_generation=0;
	    }
	    ;


If_Stmt:  T_if T_lparen Bool_Expr T_rparen Stmt Else_Part  
		{
				$$=MkNode(astIf_Stmt,NULL,$3,$5,$6,NULL); 
				$3->previous=$$;
				$$->available=1;
				$$->code_generation=0;
		}
	    ;


Else_Part: T_else Stmt  
		{
				$$=$2;
		  
		}
		| 	 /*empty*/   %prec "THEN" //https://stackoverflow.com/questions/12731922/reforming-the-grammar-to-remove-shift-reduce-conflict-in-if-then-else
		{
				$$=MkNode(astEMPTY_Else_Part,NULL,NULL,NULL,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
		}
		;
		
	 
Bool_Expr: Expr C_Op Expr
	    {
				p1=new_symbol("bool_expr");
				$$=MkNode(astBool_Expr,p1,$1,$2,$3,NULL);
				$$->available=1;
				$$->code_generation=0;
		}
		;
		

C_Op:   T_eq //1 ==
	    {
				p1=new_symbol("==");
				$$=MkNode(astC_Op_eq,p1,NULL,NULL,NULL,NULL);
				$$->oper=1;			
				$$->available=1;
				$$->code_generation=0;
	    }
	    | T_lt //2 <
	    {		
	   
				p1=new_symbol("<");
				$$=MkNode(astC_Op_lt,p1,NULL,NULL,NULL,NULL);	
				$$->oper=2;
				$$->available=1;
				$$->code_generation=0;
			    
	    } 
	    | T_gt //3 >
	    {
				p1=new_symbol(">");
				$$=MkNode(astC_Op_gt,p1,NULL,NULL,NULL,NULL);	 
				$$->oper=3;
				$$->available=1;
				$$->code_generation=0;
			
	    } 
	    | T_le //4 <=
	    {
				p1=new_symbol("<=");
				$$=MkNode(astC_Op_le,p1,NULL,NULL,NULL,NULL);	
				$$->oper=4;
				$$->available=1;
				$$->code_generation=0;
			
	    } 
	    | T_ge //5 >=
	    {
				p1=new_symbol(">=");
				$$=MkNode(astC_Op_ge,p1,NULL,NULL,NULL,NULL);	
				$$->oper=5;
				$$->available=1;
				$$->code_generation=0;
			
	    } 
	    | T_neq //6 !=
	    {
				p1=new_symbol("!=");
				$$=MkNode(astC_Op_neq,p1,NULL,NULL,NULL,NULL);	
				$$->oper=6;
				$$->available=1;
				$$->code_generation=0;				
	    }
	    ;
		
		
Rval:   Rval T_plus Term
	    {
				p=new_symbol("rval_Add");
	     		$$=MkNode(astRval_Add,p,$1,$3,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
	    }
	    | Rval T_minus Term
	    {
				p=new_symbol("rval_minus");				
				$$=MkNode(astRval_Minus,p,$1,$3,NULL,NULL);	
				$$->available=1;
				$$->code_generation=0;				
	    }
	    | Term 
	    {
				$$=$1;	
	    }
	    ;


Term:    Term T_mult Factor
	    {
				p=new_symbol("Term_mult");
				$$=MkNode(astTerm_mult,p,$1,$3,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
	    }
	    | Term T_div Factor
	    {
				p=new_symbol("Term_div");
				$$=MkNode(astTerm_div,p,$1,$3,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
	    }
	    | Factor 
	    {	   
				$$=$1;		
	    }
	    ;
	   
	   
Factor:    T_lparen Expr T_rparen
	    {
				$$=$2;	
	    }
	    | T_minus Factor %prec UMINUS
	    {
			    p=new_symbol("");
				$$=MkNode(astFactor,p,$2,NULL,NULL,NULL);	
				$$->available=1;
				$$->code_generation=0;				
	    }
	    | I_Dv 
	    {
				$$=$1;
	    }
	    | NUM 
	    {
				if($1.type=="int")
				{
					p1=new_symbol($1.str);
					p1->typos=10;
					p1->disposable=FALSE;
					p1->lvalue=FALSE;
					p1->timi=$1.a;				
					push_vs(p1);
					$$=MkNode(astINTConst,p1,NULL,NULL,NULL,NULL);
					$$->available=1;
					$$->code_generation=0;
				}
				if($1.type=="float")
				{
					p1=new_symbol($1.str);
					p1->typos=11;
					p1->disposable=FALSE;
					p1->lvalue=FALSE;
					p1->timi2=$1.b;
					push_vs(p1);
					$$=MkNode(astFLOATConst,p1,NULL,NULL,NULL,NULL);
					$$->available=1;
					$$->code_generation=0;
				}
	    }
	    ;


NUM : int_num   
		{
				strcpy($$.str,$1.str);
				$$.type="int";
				$$.a = $1.a;	
				
		}
		| float_num 
		{
				strcpy($$.str,$1.str);
				$$.type="float";
				$$.b = $1.b;
		}
		;


I_D:   id 
		{
				p1=new_symbol($1);
				$$=MkNode(astI_D,p1,NULL,NULL,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
				push_vs(p1);
				
				
		}
		;
	
	
I_Dv:  id 
		{
				p1=findsymb($1);
				if(!p1) {
					printf("Identifier not declared\n");
					exit(1);
				}
				$$=MkNode(astI_Dv,p1,NULL,NULL,NULL,NULL);
				$$->available=1;
				$$->code_generation=0;
				p1=create_id(p1);
				push_vs(p1);
		}
		;
%%
#include "parser2.txt"
