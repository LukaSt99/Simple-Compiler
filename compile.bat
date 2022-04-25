yacc -dv parser.yacc
flex lexer.flex
gcc y.tab.c lex.yy.c parser3.c zyywrap.c
a <example4.txt