/*
Author : Kuntima
Description : A shop
Date : 28/7/2018
Usage : g++ -std=c++11 main.cpp TickTacToeBoard.cpp -o main
Note : A lot can be changed, this is nothing more than a prototype that I wanted to create to train myself, my goal is to do AI TickTackToe Game
       Issues : I do not prevent the players choosing the same marks.
                I did not make all characters available for mark, for example choosing £ will present a problem

*/
#include <iostream>
#include <string>
#include "TickTacToeBoard.h"

using namespace std;

int main(){


    TickTacToeBoard Game ; // Creating the game object
    Game.choseMarks() ;   // Creating marks ID for the player
    Game.boardInit();    // Initalizing the game
    Game.boardPrint() ;  // showing the game
    Game.GameLoop() ;    // game loop

    return 0;
}
