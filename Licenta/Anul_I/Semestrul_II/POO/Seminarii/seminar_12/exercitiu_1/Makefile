all: main.o Vizitator.o VizitatorCitrice.o Fruct.o Mar.o Portocala.o
	g++ main.o -o main

main.o: main.cpp
	g++ -c main.cpp

Vizitator.o: Vizitator.cpp
	g++ -c Vizitator.cpp

Fruct.o: Fruct.cpp
	g++ -c Fruct.cpp

Mar.o: Mar.cpp
	g++ -c Mar.cpp

Portocala.o: Portocala.cpp
	g++ -c Portocala.cpp

rm: clean
	rm main

clean:
	rm *.o
	
