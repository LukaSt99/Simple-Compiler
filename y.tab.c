#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "parser.yacc"

/*Λουκάς Στογιολάρης ΑΕΜ:3413*/

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

#line 62 "parser.yacc"
typedef union
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
} YYSTYPE;
#line 90 "y.tab.c"
#define T_mainclass 257
#define T_public 258
#define T_static 259
#define T_void 260
#define T_main 261
#define T_println 262
#define T_for 263
#define T_while 264
#define T_if 265
#define T_else 266
#define T_comma 267
#define T_plus 268
#define T_minus 269
#define T_mult 270
#define T_div 271
#define T_semi 272
#define T_lbrack 273
#define T_rbrack 274
#define T_lparen 275
#define T_rparen 276
#define T_e 277
#define int_num 278
#define float_num 279
#define id 280
#define T_int 281
#define T_float 282
#define T_eq 283
#define T_lt 284
#define T_gt 285
#define T_le 286
#define T_ge 287
#define T_neq 288
#define UMINUS 289
#define THEN 290
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,   12,    4,    4,    5,    5,   13,   22,   23,
    6,    6,    8,    9,    9,   10,   10,   11,   14,   15,
   15,    7,   16,   16,   16,   16,   16,   16,   17,   17,
   17,   18,   18,   18,   19,   19,   19,   19,   24,   24,
   20,   21,
};
short yylen[] = {                                         2,
   11,    3,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    5,    3,    1,    1,    3,    1,    1,    2,    3,
    1,    1,    9,    1,    0,    1,    0,    5,    6,    2,
    0,    3,    1,    1,    1,    1,    1,    1,    3,    3,
    1,    3,    3,    1,    3,    2,    1,    1,    1,    1,
    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,   51,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,   52,   14,
   15,    9,    0,    4,    0,    6,    7,   10,   11,    8,
    0,    5,    0,    1,    0,    0,    0,    0,    2,    3,
    0,   17,    0,   19,    0,    0,   49,   50,    0,    0,
    0,   44,    0,   21,   48,    0,   24,    0,    0,    0,
    0,   13,   20,   46,   47,    0,    0,    0,    0,    0,
    0,    0,   33,   34,   35,   36,   37,   38,    0,    0,
    0,   16,   45,   12,    0,    0,   42,   43,   26,    0,
   32,   28,    0,    0,    0,   29,    0,   30,    0,   23,
};
short yydgoto[] = {                                       2,
   22,   23,   24,   25,   41,   58,   59,   26,   56,   90,
   27,   28,   29,   30,   96,   79,   50,   51,   52,    4,
   31,   32,   54,   55,
};
short yysindex[] = {                                   -230,
 -248,    0,    0, -240, -224, -219, -216, -220, -228, -231,
 -225, -116, -223, -226, -218, -215, -214,    0,    0,    0,
    0,    0, -210,    0, -248,    0,    0,    0,    0,    0,
 -221,    0, -207,    0, -260, -213, -260, -260,    0,    0,
 -251,    0, -260,    0, -260, -260,    0,    0, -202, -246,
 -245,    0, -221,    0,    0, -206,    0, -107, -201, -200,
 -248,    0,    0,    0,    0, -198, -193, -260, -260, -260,
 -260, -260,    0,    0,    0,    0,    0,    0, -260, -116,
 -116,    0,    0,    0, -245, -245,    0,    0,    0, -192,
    0,    0, -185, -213, -116,    0, -191,    0, -116,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -188,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -113,
 -174,    0, -180,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -153, -147,    0,    0,    0,    0,
    0,    0, -120, -183,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   86,    0,  -22,    0,    0,  -29,  -30,    0,    5,    0,
    0,    0,    0,    0,    0,    0,    0,  -38,  -42,  -18,
  -33,    0,  -12,    0,
};
#define YYTABLESIZE 181
short yytable[] = {                                      33,
   40,   53,   64,   53,   53,   49,   42,   60,   45,   53,
   33,   65,   53,   63,   46,   61,   66,   47,   48,   19,
   62,   68,   69,   57,   70,   71,    1,   87,   88,   85,
   86,    3,    5,    6,   65,   65,   65,   65,   53,    7,
    9,   89,   82,    8,   11,   53,   10,   12,   35,   91,
   34,   14,   15,   16,   17,   43,   36,   92,   93,   37,
   38,   18,   12,   39,   44,   72,   19,   33,   33,   19,
   20,   21,   98,   67,   80,   81,  100,   83,   84,   94,
   95,   57,   33,   25,   99,   27,   33,   47,   47,   47,
   47,   47,   25,   41,   41,   47,   13,   41,   97,    0,
    0,   41,   47,   47,   47,   47,   47,   47,   41,   41,
   41,   41,   41,   41,   39,   39,    0,    0,   39,    0,
   40,   40,   39,    0,   40,    0,    0,    0,   40,   39,
   39,   39,   39,   39,   39,   40,   40,   40,   40,   40,
   40,   31,   31,   31,   31,   14,   15,   16,   17,    0,
    0,   31,   31,   31,    0,   18,   12,    0,   22,   31,
   31,   31,   22,   19,   20,   21,    0,    0,    0,   22,
   22,   22,   22,   22,   22,   73,   74,   75,   76,   77,
   78,
};
short yycheck[] = {                                      12,
   23,   35,   45,   37,   38,   35,   25,   38,  269,   43,
   23,   45,   46,   43,  275,  267,   46,  278,  279,  280,
  272,  268,  269,   36,  270,  271,  257,   70,   71,   68,
   69,  280,  273,  258,   68,   69,   70,   71,   72,  259,
  261,   72,   61,  260,  276,   79,  275,  273,  275,   79,
  274,  262,  263,  264,  265,  277,  275,   80,   81,  275,
  275,  272,  273,  274,  272,  272,  280,   80,   81,  280,
  281,  282,   95,  276,  276,  276,   99,  276,  272,  272,
  266,   94,   95,  272,  276,  272,   99,  268,  269,  270,
  271,  272,  276,  268,  269,  276,   11,  272,   94,   -1,
   -1,  276,  283,  284,  285,  286,  287,  288,  283,  284,
  285,  286,  287,  288,  268,  269,   -1,   -1,  272,   -1,
  268,  269,  276,   -1,  272,   -1,   -1,   -1,  276,  283,
  284,  285,  286,  287,  288,  283,  284,  285,  286,  287,
  288,  262,  263,  264,  265,  262,  263,  264,  265,   -1,
   -1,  272,  273,  274,   -1,  272,  273,   -1,  272,  280,
  281,  282,  276,  280,  281,  282,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  283,  284,  285,  286,  287,
  288,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_mainclass","T_public",
"T_static","T_void","T_main","T_println","T_for","T_while","T_if","T_else",
"T_comma","T_plus","T_minus","T_mult","T_div","T_semi","T_lbrack","T_rbrack",
"T_lparen","T_rparen","T_e","int_num","float_num","id","T_int","T_float","T_eq",
"T_lt","T_gt","T_le","T_ge","T_neq","UMINUS","\"THEN\"",
};
char *yyrule[] = {
"$accept : Program",
"Program : T_mainclass I_D T_lbrack T_public T_static T_void T_main T_lparen T_rparen Comp_Stmt T_rbrack",
"Comp_Stmt : T_lbrack Stmt_List T_rbrack",
"Stmt_List : Stmt_List Stmt",
"Stmt_List : Stmt",
"Stmt : Assign_Stmt",
"Stmt : For_Stmt",
"Stmt : While_Stmt",
"Stmt : If_Stmt",
"Stmt : Comp_Stmt",
"Stmt : Declaration",
"Stmt : Null_Stmt",
"Stmt : T_println T_lparen Expr T_rparen T_semi",
"Declaration : Type Id_List T_semi",
"Type : T_int",
"Type : T_float",
"Id_List : Id_List T_comma I_D",
"Id_List : I_D",
"Null_Stmt : T_semi",
"Assign_Stmt : Assign_Expr T_semi",
"Assign_Expr : I_Dv T_e Expr",
"Expr : Assign_Expr",
"Expr : Rval",
"For_Stmt : T_for T_lparen Opassign_Expr T_semi Opbool_Expr T_semi Opassign_Expr T_rparen Stmt",
"Opassign_Expr : Assign_Expr",
"Opassign_Expr :",
"Opbool_Expr : Bool_Expr",
"Opbool_Expr :",
"While_Stmt : T_while T_lparen Bool_Expr T_rparen Stmt",
"If_Stmt : T_if T_lparen Bool_Expr T_rparen Stmt Else_Part",
"Else_Part : T_else Stmt",
"Else_Part :",
"Bool_Expr : Expr C_Op Expr",
"C_Op : T_eq",
"C_Op : T_lt",
"C_Op : T_gt",
"C_Op : T_le",
"C_Op : T_ge",
"C_Op : T_neq",
"Rval : Rval T_plus Term",
"Rval : Rval T_minus Term",
"Rval : Term",
"Term : Term T_mult Factor",
"Term : Term T_div Factor",
"Term : Factor",
"Factor : T_lparen Expr T_rparen",
"Factor : T_minus Factor",
"Factor : I_Dv",
"Factor : NUM",
"NUM : int_num",
"NUM : float_num",
"I_D : id",
"I_Dv : id",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 580 "parser.yacc"
#include "parser2.txt"
#line 330 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 104 "parser.yacc"
{
				p1=new_symbol(yyvsp[-9].stnode->SymbolNode->name);
				TreeRoot=MkNode(astProgram,p1,yyvsp[-9].stnode,yyvsp[-1].stnode,NULL,NULL);
				TreeRoot->available=1;
				TreeRoot->code_generation=0;
				
				char tmp[NAME_MAX+1];
				strcpy(tmp, yyvsp[-9].stnode->SymbolNode->name);

				mips_data = fopen(strcat(yyvsp[-9].stnode->SymbolNode->name,".data"), "w+");
				fprintf(mips_data, "\n%s\n", ".data");
				fprintf(mips_data, "newline: .asciiz  \"\\n\"\n");
				
				
				
				strcpy(yyvsp[-9].stnode->SymbolNode->name,tmp);
				
				mips_text = fopen(strcat(yyvsp[-9].stnode->SymbolNode->name,".text"), "w+");
				fprintf(mips_text, "\n%s\n", ".text");
				strcpy(yyvsp[-9].stnode->SymbolNode->name,tmp);
			
				code_generation(yyvsp[-1].stnode);
				exe_Postorder(yyvsp[-1].stnode);
				
				fclose(mips_data);
				fclose(mips_text);
				
				mips_data = fopen(strcat(yyvsp[-9].stnode->SymbolNode->name,".data"), "r");
				strcpy(yyvsp[-9].stnode->SymbolNode->name,tmp);
				mips_text = fopen(strcat(yyvsp[-9].stnode->SymbolNode->name,".text"), "r");
				strcpy(yyvsp[-9].stnode->SymbolNode->name,tmp);
				mips_code = fopen(strcat(yyvsp[-9].stnode->SymbolNode->name,".s")   , "w+");
				
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
break;
case 2:
#line 155 "parser.yacc"
{
				yyval.stnode=yyvsp[-1].stnode;
	    }
break;
case 3:
#line 162 "parser.yacc"
{
				p1=new_symbol("stmt_list");
		 		yyval.stnode=MkNode(astStmt_List,p1,yyvsp[-1].stnode,yyvsp[0].stnode,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 4:
#line 169 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 5:
#line 176 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 6:
#line 180 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 7:
#line 184 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 8:
#line 188 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 9:
#line 192 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 10:
#line 196 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 11:
#line 200 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;		
	    }
break;
case 12:
#line 204 "parser.yacc"
{
				p1=new_symbol("print");
				yyval.stnode=MkNode(astStmt_print,p1,yyvsp[-2].stnode,NULL,NULL,NULL);	
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 13:
#line 214 "parser.yacc"
{                          			     
				yyval.stnode=MkNode(astDeclaration,NULL,yyvsp[-2].stnode,yyvsp[-1].stnode,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				p2=pop_vs();											
				p1=pop_vs();							       
				cpy_attributes(p2,p1);									
				p2=reverse_cross_links(p2);					   			
				Link_Symbol_to_Cross_Link(p2);								
				add_symbols_to_table(p2);								
				discard_symbol(p1);	
		}
break;
case 14:
#line 230 "parser.yacc"
{
				p1=new_symbol("");
				set_class_types(p1,10);
				p1->disposable=TRUE;
				yyval.stnode=MkNode(astTYPE_INT,NULL,NULL,NULL,NULL,NULL); 
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				push_vs(p1);
				
	    }
break;
case 15:
#line 242 "parser.yacc"
{
				yyval.stnode=MkNode(astTYPE_FLOAT,NULL,NULL,NULL,NULL,NULL); 
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				p1=new_symbol("");
				set_class_types(p1,11);
				p1->disposable=TRUE;
				push_vs(p1);
	    }
break;
case 16:
#line 255 "parser.yacc"
{		
				yyval.stnode=MkNode(astIDList,NULL,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);\
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				p3=pop_vs();
				p1=pop_vs();
				p3->Next_in_Cross_Link=p1;
				push_vs(p3);			
	    }
break;
case 17:
#line 265 "parser.yacc"
{	
				yyval.stnode=yyvsp[0].stnode;			
		}
break;
case 18:
#line 272 "parser.yacc"
{		
				yyval.stnode=MkNode(astNULL_Stmt_Semicolon,NULL,NULL,NULL,NULL,NULL);	
	    }
break;
case 19:
#line 279 "parser.yacc"
{
				yyval.stnode=yyvsp[-1].stnode;	
		}
break;
case 20:
#line 286 "parser.yacc"
{		
				p=new_symbol("assign_expr");
				yyval.stnode=MkNode(astAssign_Expr,p,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
				yyval.stnode->available=1;	
				yyval.stnode->code_generation=0;				
		}
break;
case 21:
#line 296 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 22:
#line 300 "parser.yacc"
{
				
				yyval.stnode=yyvsp[0].stnode;
				
	    }
break;
case 23:
#line 309 "parser.yacc"
{
				yyval.stnode=MkNode(astFor_Stmt,NULL,yyvsp[-6].stnode,yyvsp[-4].stnode,yyvsp[-2].stnode,yyvsp[0].stnode);
				yyvsp[-4].stnode->previous=yyval.stnode;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				
	    }
break;
case 24:
#line 320 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
		
	    }
break;
case 25:
#line 325 "parser.yacc"
{
	   
				yyval.stnode=MkNode(astEMPTY_Opassign_Expr,NULL,NULL,NULL,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
		
	    }
break;
case 26:
#line 336 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 27:
#line 340 "parser.yacc"
{
				
				yyval.stnode=MkNode(astEMPTYOpbool_Expr,NULL,NULL,NULL,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 28:
#line 350 "parser.yacc"
{   	
				yyval.stnode=MkNode(astWhile_Stmt,NULL,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
				yyvsp[-2].stnode->previous=yyval.stnode;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 29:
#line 360 "parser.yacc"
{
				yyval.stnode=MkNode(astIf_Stmt,NULL,yyvsp[-3].stnode,yyvsp[-1].stnode,yyvsp[0].stnode,NULL); 
				yyvsp[-3].stnode->previous=yyval.stnode;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
		}
break;
case 30:
#line 370 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
		  
		}
break;
case 31:
#line 375 "parser.yacc"
{
				yyval.stnode=MkNode(astEMPTY_Else_Part,NULL,NULL,NULL,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
		}
break;
case 32:
#line 384 "parser.yacc"
{
				p1=new_symbol("bool_expr");
				yyval.stnode=MkNode(astBool_Expr,p1,yyvsp[-2].stnode,yyvsp[-1].stnode,yyvsp[0].stnode,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
		}
break;
case 33:
#line 394 "parser.yacc"
{
				p1=new_symbol("==");
				yyval.stnode=MkNode(astC_Op_eq,p1,NULL,NULL,NULL,NULL);
				yyval.stnode->oper=1;			
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 34:
#line 402 "parser.yacc"
{		
	   
				p1=new_symbol("<");
				yyval.stnode=MkNode(astC_Op_lt,p1,NULL,NULL,NULL,NULL);	
				yyval.stnode->oper=2;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
			    
	    }
break;
case 35:
#line 412 "parser.yacc"
{
				p1=new_symbol(">");
				yyval.stnode=MkNode(astC_Op_gt,p1,NULL,NULL,NULL,NULL);	 
				yyval.stnode->oper=3;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
			
	    }
break;
case 36:
#line 421 "parser.yacc"
{
				p1=new_symbol("<=");
				yyval.stnode=MkNode(astC_Op_le,p1,NULL,NULL,NULL,NULL);	
				yyval.stnode->oper=4;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
			
	    }
break;
case 37:
#line 430 "parser.yacc"
{
				p1=new_symbol(">=");
				yyval.stnode=MkNode(astC_Op_ge,p1,NULL,NULL,NULL,NULL);	
				yyval.stnode->oper=5;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
			
	    }
break;
case 38:
#line 439 "parser.yacc"
{
				p1=new_symbol("!=");
				yyval.stnode=MkNode(astC_Op_neq,p1,NULL,NULL,NULL,NULL);	
				yyval.stnode->oper=6;
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;				
	    }
break;
case 39:
#line 450 "parser.yacc"
{
				p=new_symbol("rval_Add");
	     		yyval.stnode=MkNode(astRval_Add,p,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 40:
#line 457 "parser.yacc"
{
				p=new_symbol("rval_minus");				
				yyval.stnode=MkNode(astRval_Minus,p,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);	
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;				
	    }
break;
case 41:
#line 464 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;	
	    }
break;
case 42:
#line 471 "parser.yacc"
{
				p=new_symbol("Term_mult");
				yyval.stnode=MkNode(astTerm_mult,p,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 43:
#line 478 "parser.yacc"
{
				p=new_symbol("Term_div");
				yyval.stnode=MkNode(astTerm_div,p,yyvsp[-2].stnode,yyvsp[0].stnode,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
	    }
break;
case 44:
#line 485 "parser.yacc"
{	   
				yyval.stnode=yyvsp[0].stnode;		
	    }
break;
case 45:
#line 492 "parser.yacc"
{
				yyval.stnode=yyvsp[-1].stnode;	
	    }
break;
case 46:
#line 496 "parser.yacc"
{
			    p=new_symbol("");
				yyval.stnode=MkNode(astFactor,p,yyvsp[0].stnode,NULL,NULL,NULL);	
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;				
	    }
break;
case 47:
#line 503 "parser.yacc"
{
				yyval.stnode=yyvsp[0].stnode;
	    }
break;
case 48:
#line 507 "parser.yacc"
{
				if(yyvsp[0].val.type=="int")
				{
					p1=new_symbol(yyvsp[0].val.str);
					p1->typos=10;
					p1->disposable=FALSE;
					p1->lvalue=FALSE;
					p1->timi=yyvsp[0].val.a;				
					push_vs(p1);
					yyval.stnode=MkNode(astINTConst,p1,NULL,NULL,NULL,NULL);
					yyval.stnode->available=1;
					yyval.stnode->code_generation=0;
				}
				if(yyvsp[0].val.type=="float")
				{
					p1=new_symbol(yyvsp[0].val.str);
					p1->typos=11;
					p1->disposable=FALSE;
					p1->lvalue=FALSE;
					p1->timi2=yyvsp[0].val.b;
					push_vs(p1);
					yyval.stnode=MkNode(astFLOATConst,p1,NULL,NULL,NULL,NULL);
					yyval.stnode->available=1;
					yyval.stnode->code_generation=0;
				}
	    }
break;
case 49:
#line 537 "parser.yacc"
{
				strcpy(yyval.val.str,yyvsp[0].val.str);
				yyval.val.type="int";
				yyval.val.a = yyvsp[0].val.a;	
				
		}
break;
case 50:
#line 544 "parser.yacc"
{
				strcpy(yyval.val.str,yyvsp[0].val.str);
				yyval.val.type="float";
				yyval.val.b = yyvsp[0].val.b;
		}
break;
case 51:
#line 553 "parser.yacc"
{
				p1=new_symbol(yyvsp[0].ystr);
				yyval.stnode=MkNode(astI_D,p1,NULL,NULL,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				push_vs(p1);
				
				
		}
break;
case 52:
#line 566 "parser.yacc"
{
				p1=findsymb(yyvsp[0].ystr);
				if(!p1) {
					printf("Identifier not declared\n");
					exit(1);
				}
				yyval.stnode=MkNode(astI_Dv,p1,NULL,NULL,NULL,NULL);
				yyval.stnode->available=1;
				yyval.stnode->code_generation=0;
				p1=create_id(p1);
				push_vs(p1);
		}
break;
#line 977 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
