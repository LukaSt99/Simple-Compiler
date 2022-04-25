%{

/*Lluka Stojollari*/

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>
#define T_eof      0

%}

letter [a-zA-Z]
digit  [0-9]
dot    [.]
W [ \t\r\n]

id  {letter}({letter}|{digit}|_)*
int_num  		{digit}+
float_num       {digit}+{dot}{digit}+
mainclass   "mainclass"
public      "public"
static	    "static"
void	    "void"
main 	    "main"
int 	    "int"
float	    "float"
println	    "println"
for	    	"for"
while	    "while"
if	    	"if"
else	    "else"
eq	    	"=="
e	    	"="
lt	    	"<" 
gt 	    	">" 
le	    	"<="
ge	    	">="
neq   	    "!="
div	    	"/"
mult	    "*"
minus	    "-"
plus	    "+"
comma	    ","
semi	    ";"
lbrack	    "{"
rbrack	    "}"
lparen	    "("
rparen	    ")"

%%


{mainclass}  {return T_mainclass;}
{public}     {return T_public;}
{static}     {return T_static;}
{void}       {return T_void;} 
{main}       {return T_main;}
{println}    {return T_println;}
{for}        {return T_for;}
{while}      {return T_while;}
{if}         {return T_if;}
{else}       {return T_else;}
{int}        {
				yylval.type.value = 10;
				return T_int;
			 }
{float}      {
				yylval.type.value = 11;
				return T_float;
			 }
{eq}         {return T_eq;}
{lt}         {return T_lt;}
{gt}         {return T_gt;}
{le}         {return T_le;}
{ge}         {return T_ge;}
{neq}        {return T_neq;}
{e}	    	 {return T_e;}
{comma}	     {return T_comma;}
{plus}	     {return T_plus;}
{minus}	     {return T_minus;}
{mult}	     {return T_mult;}
{div}	     {return T_div;}
{semi}	     {return T_semi;}
{lbrack}     {return T_lbrack;}
{rbrack}     {return T_rbrack;}
{lparen}     {return T_lparen;}
{rparen}     {return T_rparen;}
{id}         {
			  strcpy(yylval.ystr,yytext);
		      return id;
			 }
{int_num}    {
		      strcpy(yylval.val.str,yytext);
			  yylval.val.type = "int";
              yylval.val.a = atoi(&yytext[0]);
			  return int_num;
			 }
{float_num}  {
			  strcpy(yylval.val.str,yytext);
			  yylval.val.type = "float";
              yylval.val.b = atof(&yytext[0]);
			  return float_num;
			 }
{W}+    { /* nothing */ }
<<EOF>> { return T_eof; }
%%