all: lex.yy.c y.tab.h aux.c
	gcc lex.yy.c y.tab.c aux.c -ll -ly -o limbaj

force:
	lex limbaj.l
	yacc -d limbaj.y
	gcc lex.yy.c y.tab.c aux.c -ll -ly -o limbaj
	rm -f lex.yy.c y.tab.h y.tab.c

lex.yy.c: limbaj.l
	lex limbaj.l

y.tab.h:
	yacc -d limbaj.y

clean:
	rm -f lex.yy.c y.tab.h y.tab.c
