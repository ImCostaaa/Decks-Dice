#include "diceGame.h"

using namespace std;

diceGame::diceGame(){
    playingDice = new dice();
}
diceGame::~diceGame(){
    delete playingDice;
}