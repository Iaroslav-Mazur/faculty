all: main
	
main: main.o singelton.o singelton2.o
	g++ singelton.o singelton2.o main.o -o main


singelton.o: singelton.cpp
	g++ -c singelton.cpp

singelton2.o: singelton2.cpp
	g++ -c singelton2.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o

