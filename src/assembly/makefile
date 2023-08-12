Process_asqg: main.o string_graph.o
	g++ -std=c++2a -g -Wall main.o string_graph.o -o Process_asqg

main.o: main.cpp string_graph.h
	g++ -std=c++2a -g -Wall -c main.cpp

string_graph.o: string_graph.h string_graph.cpp
	g++ -std=c++2a -g -Wall -c string_graph.cpp

clean:
	rm *.o Process_asqg