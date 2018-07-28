#ifndef TICKTACTOEBOARD_H
#define TICKTACTOEBOARD_H
#include <string>




class TickTacToeBoard
{
    public:

        TickTacToeBoard();       // The construct, with the only purpose of wellcoming the player
        void boardInit() ;      //  The function that creates the board, a 3x3 empty board
        void boardPrint() ;    //   The function that shows in the screen the game
        void choseMarks() ;   //    The function that gives each player a marker to play.
        void GameLoop( ) ;   //     The function that shows the evolution of the game
        bool CheckWinningPlayer () ; // The function that checks if we have a winner

    protected:
    private:
        char board[3][3] ;  // the board
        char marker1;       // the marker for player 1
        char marker2;       // The marker for player 2
        bool switchPlayer;  // A variable that tells when to swicth from one player to another
        bool KeepPlaying;   // A variable that tells if we want keep playing after winning the game
        char quit ;          // Note used, can be removed
        int nbPlays ;        // A variable to tell us that the board if full

};

#endif // TICKTACTOEBOARD_H
