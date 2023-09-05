all: main

main: main.out libs
	gcc main.out -o main -L. singleLLO.a doubleLLO.a circularLLO.a

main.out: main.c
	gcc -c main.c -o main.out

singleLLO.out: singleLLO.c
	gcc -c singleLLO.c -o singleLLO.out

singleLLO.a: singleLLO.out
	ar rcs singleLLO.a singleLLO.out

doubleLLO.out: doubleLLO.c
	gcc -c doubleLLO.c -o doubleLLO.out

doubleLLO.a: doubleLLO.out
	ar rcs doubleLLO.a doubleLLO.out

circularLLO.out: circularLLO.c
	gcc -c circularLLO.c -o circularLLO.out

circularLLO.a: circularLLO.out
	ar rcs circularLLO.a circularLLO.out

libs: singleLLO.a doubleLLO.a circularLLO.a

clean:
	rm -f main *.out *.a