all: main

main: main.out libs
	gcc main.out -o main -L. wordCount.a

main.out: task2.c
	gcc -c task2.c -o main.out

wordCount.out: wordCount.c
	gcc -c wordCount.c -o wordCount.out

wordCount.a: wordCount.out
	ar rcs wordCount.a wordCount.out

libs: wordCount.a

clean:
	rm -f main *.out *.a