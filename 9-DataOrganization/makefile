all: main

main: main.out libs
	gcc main.out -o main -L. singleLLO.a

main.out: main.c
	gcc -c main.c -o main.out

singleLLO.out: singleLLO.c
	gcc -c singleLLO.c -o singleLLO.out

singleLLO.a: singleLLO.out
	ar rcs singleLLO.a singleLLO.out

libs: singleLLO.a

clean:
	rm -f main *.out *.a