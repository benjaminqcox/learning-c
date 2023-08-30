all: driver

driver: driver.out libs
	gcc driver.out -o driver -L. lib1.a lib2.a

driver.out: driver.c
	gcc -c driver.c -o driver.out
	
lib1.out: lib1.c
	gcc -c lib1.c -o lib1.out
	
lib2.out: lib2.c
	gcc -c lib2.c -o lib2.out

lib1.a: lib1.out
	ar rcs lib1.a lib1.out

lib2.a: lib2.out
	ar rcs lib2.a lib2.out

libs: lib1.a lib2.a

clean:
	rm -f driver *.out *.a