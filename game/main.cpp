#include <iostream> 
using namespace std;
#include "Board.cpp"
#include "Player.cpp"

int main(){
    // classes that are called
    board gameBoard; // set up and creat a game board
    player playerOne; // create player one (player X)
    player playerTwo; // create player two (player O)

    // set class variables 
    playerOne.symbol = "X";
    playerTwo.symbol = "O";
    string name;
    
    cout << "What is the name of player 1: ";
    cin >> name;
    playerOne.setPlayerName(name);
    cout << "What is the name of player 2: ";
    cin >> name;
    playerTwo.setPlayerName(name);
    
    // variables
    bool game = true; // bool for the game loop as long as this is true the game will go on
    bool round = true; // bool for the game loop for each round of the game
    int turn = 0; // this value will allow the game to know whos turn it is

    // lists that will be needed for the game
    string list[2] = {playerOne.symbol, playerTwo.symbol}; // list of player (X and O)
    
    // temp variables
    string keep;

    // game loop
    while (game == true){
        while(round == true){
            cout << playerOne.playerName << " score: " << playerOne.score;
            cout << "       ";
            cout << playerTwo.playerName << " score: " << playerOne.score << endl;
            gameBoard.displayBoard();
            gameBoard.placeSymbol(list[turn]);
            round = gameBoard.checkForWin(list[turn]);
            if(round == true){
                turn = gameBoard.switchTurn(turn);
            }
            else{
                if(list[turn] == "X"){
                    cout << "The winner this round is " << playerOne.playerName << endl;
                    playerOne.score = playerOne.score + 1;
                } 
                else{
                    cout << "The winner this round is " << playerTwo.playerName << endl;
                    playerOne.score = playerTwo.score + 1;
                }
            } 
        }
        // to do add an if that checks to see if a players score is 3
        cout << playerOne.playerName << ": " << playerOne.score << "   ";
        cout << playerTwo.playerName << ": " << playerTwo.score << endl;
        if(playerOne.score == 3){
            cout << playerOne.playerName << " is the winner!" << endl;
            game = false;
        } else if(playerTwo.score == 3){
            cout << playerTwo.playerName << " is the winner!" << endl;
            game = false;
        }
        else{
            gameBoard.resetBoard();
            round = true;
        }
    }
}