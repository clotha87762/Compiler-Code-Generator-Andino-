all:
	flex hw3.l
	byacc -d -v hw3.y
	gcc -o codegen lex.yy.c y.tab.c symboltable.c
