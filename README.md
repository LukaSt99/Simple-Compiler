# Simple-Compiler-From-Scratch
1. Generate the syntax analysis code from the specification file parser.yacc
    yacc -dv parser.yacc

2. Generate the lexical analysis code from the specification file lexer.flex
    flex lexer.flex

3. Compile the generated C code files in lex.yy.c and in y.tab.c using the command
    gcc lex.yy.c y.tab.c parser3.c zyywrap.c

4.  Your compiler is the executable file a.exe

5. Run the produced compiler for the provided (or other) test input
		a < example4.txt

Or you can run the compile.bat in your directory 

The x86 assembly machine code is generated in the example4.s , example4.data and example4.text 
files.
