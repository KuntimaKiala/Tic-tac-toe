


output : main.o TickTacToeBoard.o
	g++ -std=c++11 main.o TickTacToeBoard.o -o ouput 

main.o : main.cpp
	g++ -c main.cpp 

TickTacToeBoard.o : TickTacToeBoard.cpp TickTacToeBoard.h
	g++ -c TickTacToeBoard.cpp


clean :
	rm -r *.o output
