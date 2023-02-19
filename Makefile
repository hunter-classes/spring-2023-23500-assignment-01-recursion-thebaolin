main: main.o funcs.o
		g++ -o main main.o funcs.o

main.o: main.cpp funcs.cpp

funcs.o: funcs.cpp funcs.h

clean:
		rm -f *.o a.out main