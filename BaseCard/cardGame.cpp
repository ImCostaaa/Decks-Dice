#include "cardGame.h"

using namespace std;

cardGame::cardGame(){
    playingDeck = new deck();
}
cardGame::~cardGame(){
    delete playingDeck;
}