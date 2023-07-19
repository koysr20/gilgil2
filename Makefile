#Makefile
all: hex_sum

hex_sum: testc.o
	gcc -o hex_sum testc.o

testc.o: testc.c
	gcc -c -o testc.o testc.c
clean:
	rm -f hex_sum
	rm -f *.o
