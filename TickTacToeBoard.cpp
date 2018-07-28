#include "TickTacToeBoard.h"
#include <iostream>

using namespace std ;

TickTacToeBoard::TickTacToeBoard()
{

  nbPlays = 0 ;
  cout << "Welcome to the ticktactoe !\n" << endl ;

}


void TickTacToeBoard :: boardInit() {


    for (int row = 0; row < 3; row++){
        for (int columns = 0; columns < 3; columns++){
            board[row][columns] = '.' ;
    }
}


}


void TickTacToeBoard :: boardPrint() {


    for (int row = 0; row < 3; row++){
        cout << row + 1 << " | " ;
        for (int columns = 0; columns < 3; columns++){
           cout << board[row][columns] ;
           cout <<  " | " ;


    }
    cout  << "\n" ;
    cout << "---------------" ;

    cout  << "\n" ;


    }
     cout  << "  | 1 | 2 | 3 |" ;

}

void TickTacToeBoard :: choseMarks() {

    cout << "Player 1, chose your mark (O or X ) :";
    cin >> marker1 ;
    cout  << "\n" ;
    cout << "Player 2, chose your mark (O or X ) :";
    cin >> marker2 ;
    cout  << "\n" ;

}


bool TickTacToeBoard :: CheckWinningPlayer(){


    bool isThereWinner = false ;

    // each element of row and column
    for( int i = 0 ; i < 3; i++){

        if ( board[i][0] == board[i][1] and board[i][0] == board[i][2]  and  board[i][0] != '.')  {

        isThereWinner = true ;
        return isThereWinner ;
        }
        else {
            isThereWinner = false ;

        }

    }

    // each element of column
    for( int i = 0 ; i < 3; i++){
        if (board[0][i] == board[1][i] and board[0][i] == board[2][i]   and  board[0][i] != '.') {
        isThereWinner = true ;

        return isThereWinner ;

        }
        else {
            isThereWinner = false ;

        }
    }



 //  left diagonal
 if (board[0][2] == board[1][1] and  board[0][2] == board[2][0]   and  board[0][2] != '.') {
        isThereWinner = true ;
         cout <<  board[0][2]<< board[1][1]<< board[2][0] << endl ;
        return isThereWinner ;

        }
        else {
           isThereWinner  = false ;

        }


//  right diagonal
 if ((board[0][0] == board[1][1]) and (board[0][0] == board[2][2]  ) and ( board[0][0] != '.')) {
        isThereWinner = true ;

        return isThereWinner ;

        }
        else {
             isThereWinner = false ;

        }




return isThereWinner ;

}

void TickTacToeBoard :: GameLoop() {


switchPlayer= false ;
KeepPlaying= true;
quit = 'n';
int columns;
int row ;
bool IsThereWinner = false;

while (KeepPlaying == true ) {
    if (switchPlayer == false) {


        cout << "\n";
        cout << "Choose the X-cordinate :";
        cin >> row ;
        cout << "\n";
        cout << "Choose the Y-cordinate :";
        cin >> columns ;

        if ((row > 0 and row < 4) and (columns > 0 and columns < 4)) {
        if ( board[row-1][columns-1] != '.' ) {
            cout << "Ocuppied, choose another one \n\n" ;
             nbPlays-- ;


        }
        else {
            board[row-1][columns-1] = marker1 ;
            switchPlayer  = true ;
            IsThereWinner = CheckWinningPlayer() ;
            if (IsThereWinner == true) {
            boardPrint() ;
            cout << "\nPlayer 1 as won \n" ;
            cout << "Ready for your next chalendge ? \n";
            cout << "Press Y to keep playing and N to quit : " ;
            cin >> quit ;
            if (quit == 'N' or  quit == 'n' ) {
                cout << " Thanks for playing \n" ;
                KeepPlaying = false ;
            }
            if (quit == 'Y' or  quit == 'y'){
             cout << "New GAME\n" ;
             nbPlays = -1 ;
                boardInit() ;
                 cout << " \n";
            }
            }
        }
        }
        else {
          cout << "Invalid, choose again \n\n" ;
          nbPlays-- ;

        }
        boardPrint() ;


    }

    else {

        cout << "\n";
        cout << "Choose the X-cordinate :";
        cin >> row ;
        cout << "\n";
        cout << "Choose the Y-cordinate :";
        cin >> columns ;

        if ((row > 0 and row < 4) and (columns > 0 and columns < 4)) {
            if ( board[row-1][columns-1] != '.') {
                cout << "Ocuppied, choose another one \n\n" ;
                 nbPlays-- ;
            }
            else {
                board[row-1][columns-1] = marker2 ;
                switchPlayer  = false ;
                IsThereWinner = CheckWinningPlayer() ;
                if (IsThereWinner == true) {

                    boardPrint() ;
                    cout << "\nplayer 2 as won \n" ;
                    cout << "Ready for your next chalendge ? \n";
                    cout << "Press Y to keep playing and N to quit : " ;
                    cin >> quit ;
                    if (quit == 'N' or  quit == 'n' ) {
                        cout << " Thanks for playing \n" ;
                        KeepPlaying = false ;
                    }
                    if (quit == 'Y' or  quit == 'y'){
                    nbPlays = -1 ;
                        boardInit() ;
                        cout << " \n";
                    }
            }
        }
        }

         else {
          cout << "Invalid, choose again \n" ;
          nbPlays-- ;

        }
        boardPrint() ;




    }




    if (nbPlays >= 8 and IsThereWinner != true) {
        cout << "\n\n**TIGHT** \n";
        cout << "Press Y to keep playing and N to quit : " ;
        cin >> quit ;
        if (quit == 'N' or  quit == 'n' ) {
            cout << " Thanks for playing \n" ;
            KeepPlaying = false ;

        }
        if (quit == 'Y' or  quit == 'y'){
            KeepPlaying = true ;
            cout << " \n";
            nbPlays = 0 ;
            boardInit() ;
        }


    }
nbPlays++ ;
//cout << "\n\n\niter" << nbPlays << endl ;
}


}
