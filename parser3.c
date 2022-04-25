#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "y.tab.h"
#include <string.h>

/*Lluka Stojollari*/

extern AstNode *TreeRoot;



int yylex();
int yyparse();

				

void spaces(int n)
{  int i;
   
   for(i=0; i<n; i++) printf(" ");
}

void traverse(AstNode *p,int n)
{  int i;

   n=n+3;
   if(p )
   {
      switch (p->NodeType)
      {
         case astProgram: 
            spaces(n); printf("\nastProgram\n"); 
         break;
		 case astStmt_List:
			spaces(n); printf("astStmt_List\n");
		 break;
		 case astEmptyStmt_List:
			spaces(n); printf("astEmptyStmt_List\n");
		 break;
		 case astDeclaration:
			spaces(n); printf("astDeclaration\n");
		 break;
         case astINTConst: 
            spaces(n); printf("INT=%s\n",(p->SymbolNode)->name); 
         break;
         case astFLOATConst: 
            spaces(n); printf("FLOAT= %s\n",(p->SymbolNode)->name); 
         break;
		 case astTYPE_INT: 
            spaces(n); printf("astTYPE_INT\n"); 
         break;
         case astTYPE_FLOAT: 
            spaces(n); printf("astTYPE_FLOAT\n"); 
         break;
		 case astIDList:
			spaces(n); printf("astIDList\n");
		 break;
		 case astI_D:
			spaces(n); printf("astI_D= %s\n",(p->SymbolNode)->name);
		 break;
		 case astRval:
			spaces(n); printf("astRval\n");
		 break;
		 case astExpr:
			spaces(n); printf("astExpr\n");
		 break;
		 case astAssign_Stmt:
			spaces(n); printf("astAssign_Stmt\n");
		 break;
		 case astTerm:
			spaces(n); printf("astTerm\n");
		 break;
		 case astAssign_Expr:
			spaces(n); printf("astAssign_Expr\n");
		 break;
		 case astStmt:
			spaces(n); printf("astStmt\n");
		 break;
		 case astComp_Stmt:
			spaces(n); printf("astComp_Stmt\n");
		 break;
		 case astNULL_Stmt_Semicolon:
			spaces(n); printf("astNULL_Stmt_Semicolon\n");
		 break;
		 case astFor_Stmt:
			spaces(n); printf("astFor_Stmt\n");
		 break;
		 case astEMPTY_Opassign_Expr:
			spaces(n); printf("astEMPTY_Opassign_Expr\n");
		 break;
		 case astOpassign_Expr:
			spaces(n); printf("astOpassign_Expr\n");
		 break;
		 case astOpbool_Expr:
			spaces(n); printf("astOpbool_Expr\n");
		 break;
		 case astEMPTYOpbool_Expr:
			spaces(n); printf("astEMPTYOpbool_Expr\n");
		 break;
		 case astWhile_Stmt:
			spaces(n); printf("astWhile_Stmt\n");
		 break;
		 case astIf_Stmt:
			spaces(n); printf("astIf_Stmt\n");
		 break;
		 case astEMPTY_Else_Part:
			spaces(n); printf("astEMPTY_Else_Part\n");
		 break;
		 case astBool_Expr:
			spaces(n); printf("astBool_Expr\n");
		 break;
		 case astC_Op_eq:
			spaces(n); printf("astC_Op_eq\n");
		 break;
		 case astC_Op_lt :
			spaces(n); printf("astC_Op_lt\n");
		 break;
		 case astC_Op_gt:
			spaces(n); printf("astC_Op_gt\n");
		 break;
		 case astC_Op_le:
			spaces(n); printf("astC_Op_le\n");
		 break;
		 case astC_Op_ge:
			spaces(n); printf("astC_Op_ge\n");
		 break;
		 case astC_Op_neq:
			spaces(n); printf("astC_Op_neq\n");
		 break;
		 case astFactor:
			spaces(n); printf("astFactor \n");
		 break;
		 case astElse_Part:
			spaces(n); printf("astElse_Part\n");
		 break;
		 case astRval_Add:
			spaces(n); printf("astRval_Add\n");
		 break;
		 case astENDofWhile:
			spaces(n); printf("astENDofWhile\n");
		 break;
		  case astI_Dv:
			spaces(n); printf("astI_Dv= %s\n",(p->SymbolNode)->name);
		 break;
		 case astStmt_print:
			spaces(n); printf("astStmt_print\n");
		 break;
		 case astExpr_Rval:
			spaces(n); printf("astExpr_Rval\n");
		 break;
		 case astRval_Minus:
			spaces(n); printf("astRval_Minus\n");
		 break;
		 case astTerm_mult:
			spaces(n); printf("astTerm_mult\n");
		 break;
		 case astTerm_div:
			spaces(n); printf("astTerm_div\n");
		 break;
		 case astThen_Stmt:
			spaces(n); printf(" astThen_Stmt\n");
		 break;
		
		
		
	
	
         default: 
            printf("AGNOSTO=%d\n",p->NodeType);
      }
      for(i=0; i<4; i++) {
		  traverse(p->pAstNode[i],n);
		   
	  }
   }
}

void main(void)
{  
   AstNode *p;
   Init_Hash_Table();
   Init_Cross_Link_Head();
  
   if(!yyparse()) 
   {
	  printf("\nSYNTAX TREE\n");
      p=TreeRoot;
      traverse(p,-3);
	  printf("ACCEPTED");
	  
   }
   else{
	   printf("REJECTED");
   }
	
    
}