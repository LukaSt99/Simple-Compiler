#define SYM_TABLE_SIZE 			41
#define MAX_CROSS_LINKS 		1
#define NAME_MAX  				32

#define astProgram				399
#define astId 	   				400
#define astINTConst      		401
#define astFLOATConst			402
#define astI_D			   	 	403
#define astIDList	 			404
#define astDeclaration			405
#define astStmt_List			406
#define astEmptyStmt_List		407
#define astTYPE_INT				408
#define astTYPE_FLOAT			409
#define astFactor				410
#define astRval					411
#define astExpr					412
#define astAssign_Stmt			413
#define astTerm					414
#define astAssign_Expr			415
#define astStmt					416
#define astComp_Stmt			417
#define astNULL_Stmt_Semicolon  418
#define	astFor_Stmt				419
#define	astEMPTY_Opassign_Expr  420
#define	astOpassign_Expr		421	
#define	astOpbool_Expr			422
#define	astEMPTYOpbool_Expr		423
#define astWhile_Stmt			424
#define	astIf_Stmt				425
#define astEMPTY_Else_Part		426
#define astBool_Expr			427	
#define	astC_Op_eq				428
#define astC_Op_lt 				429
#define astC_Op_gt				430
#define astC_Op_le				431
#define astC_Op_ge				432
#define astC_Op_neq				433
#define	astElse_Part			434
#define	astRval_Add  			435
#define astENDofWhile			436
#define astI_Dv					437
#define astStmt_print			438
#define astExpr_Rval			439
#define astTerm_div				440
#define astTerm_mult			441
#define astRval_Minus			442
#define astThen_Stmt			444

#define TRUE  1
#define FALSE 0


typedef struct symbol_tag {
	
   unsigned char name[NAME_MAX+1]; 
   char regist[NAME_MAX+1];
   
   char   release_register;
   int 	  release_nr_register;
   
   char   release_register2;
   int 	  release_nr_register2;
   

   int 	  convert_to_float; // true or false
   int    typos;                         
   int    timi;
   float  timi2;                 
   int 	  disposable;                  
   int 	  lvalue;   
   int 	  operator; // for +,-,/,*
   struct symbol_tag *Next_in_Cross_Link;
   struct symbol_tag *NextSymbol;
   struct symbol_tag *PrevSymbol;
   
} symbol;

typedef struct AstNode_tag {
	
    int    NodeType;
	int    available;
	int    code_generation;
	int    its_num;
    struct symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4];
	struct AstNode_tag *previous;
	struct symbol_tag  *exprL;
	struct symbol_tag  *exprR;
	int    oper;		//numbers for operators
	int    bool_expr;	//tRue or false for statements
	
} AstNode;

void yyerror(char *);
void Init_Hash_Table(void);
void Init_Cross_Link_Head(void);
AstNode *MkNode(int,symbol *,AstNode *,AstNode *,AstNode *,AstNode *);
void push_vs(symbol *);
symbol *pop_vs(void);
symbol *new_symbol(char *);
int hash_function(char *);
int set_class_types(symbol *, int);
void cpy_attributes(symbol *, symbol *);
symbol *reverse_cross_links(symbol *);
void Link_Symbol_to_Cross_Link(symbol *);
void addsymb(symbol *);
symbol *findsymb(char *);
void add_symbols_to_table(symbol *);
void discard_symbol(symbol *);
void copy_value(symbol *, symbol *);
void copy_symbol(symbol *, symbol *);
symbol *create_id(symbol *);