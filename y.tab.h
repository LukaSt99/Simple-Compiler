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
extern YYSTYPE yylval;
