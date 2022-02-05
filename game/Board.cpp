#include <iostream> 
using namespace std;
class board{
    public:
        string placement[9] = {
        "1", "2", "3",
        "4", "5", "6",
        "7", "8", "9"};

        void displayBoard(){
            cout << placement[0] << " | " << placement[1] << " | " << placement[2] << endl;
            cout << "---+---+---" << endl;
            cout << placement[3] << " | " << placement[4] << " | " << placement[5] << endl;
            cout << "---+---+---" << endl;
            cout << placement[6] << " | " << placement[7] << " | " << placement[8] << endl;
        }
        void placeSymbol(string symbol){
            string column;
            bool place = false;

            while (place == false){
                int placeSymble;
                cout << "What place would you like: ";
                cin >> placeSymble;

                if( placeSymble - 1 > 8 | placeSymble - 1 < 0){
                    cout << "This spot is out of range please enter a valide spot." << endl;
                }
                else{
                    if (placement[placeSymble - 1] == "X" | placement[placeSymble - 1] == "O"){
                        cout << "This spot is already taken please select a differnt one." << endl;
                    }
                    else{
                        placement[placeSymble - 1] = symbol;
                        place = true;
                    }                   
                }
            }
        }

        int switchTurn(int turn){
            turn = (turn + 1) % 2;
            return turn;
        }

        bool checkForWin(string symbol){
            if(placement[0] == symbol && placement[1] == symbol && placement[2] == symbol){ // check for winner in row 1
                return false;
            }
            else if(placement[3] == symbol && placement[4] == symbol && placement[5] == symbol){ // check for winner in row 2
                return false;
            }
            else if(placement[6] == symbol && placement[7] == symbol && placement[8] == symbol){ // check for winner in row 3
                return false;
            }
            else if(placement[0] == symbol && placement[3] == symbol && placement[6] == symbol){ // check for winner in column 1
                return false;
            }
            else if(placement[1] == symbol && placement[4] == symbol && placement[7] == symbol){ // check for winner in column 2
                return false;
            }
            else if(placement[2] == symbol && placement[5] == symbol && placement[8] == symbol){ // check for winner in column 3
                return false;
            }
            else if(placement[0] == symbol && placement[4] == symbol && placement[8] == symbol){ // check for winner diagonal
                return false;
            }
            else if(placement[6] == symbol && placement[4] == symbol && placement[2] == symbol){ // check for winner diagonal
                return false;
            }
            else{
                return true; // if there is not a winner move this turn the game will keep going on
            }
        }

    void resetBoard(){
        placement[0] = "1";
        placement[1] = "2";
        placement[2] = "3";
        placement[3] = "4";
        placement[4] = "5";
        placement[5] = "6";
        placement[6] = "7";
        placement[7] = "8";
        placement[8] = "9";

    }
};