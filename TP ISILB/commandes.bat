flex lexical.l
bison -d synt.y 
gcc lex.yy.c synt.tab.c -lfl -ly  -o compIsil2020.exe
