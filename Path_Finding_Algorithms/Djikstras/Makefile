run: main.o graph.o
	g++ main.o graph.o -o run

main.o: main.cpp main.h 
	g++ -c main.cpp 

graph.o: graph.cpp graph.h
	g++ -c graph.cpp
clean:
	rm *.o
cleanAll: 
	rm *.o run