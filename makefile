all: jogodavida

jogodavida: main.o arquivo.o funcoes.o validacao.o grade.o
	gcc	main.o arquivo.o funcoes.o validacao.o grade.o -o jogodavida

main.o: main.c
	gcc -c main.c

arquivo.o: arquivo.c
	gcc -c arquivo.c

funcoes.o: funcoes.c
	gcc -c funcoes.c

validcao.o: validacao.c
	gcc -c validacao.c

grade.o: grade.c
	gcc -c grade.c

clean: 
	rm -rf *o hello	