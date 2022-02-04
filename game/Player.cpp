#include <iostream> 
using namespace std;

class player{
    public:
    string playerName;
    int score = 0;
    string symbol;

    void setPlayerName(string name){
        playerName = name;
    }
};