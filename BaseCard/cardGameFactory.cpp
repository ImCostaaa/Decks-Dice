#include "cardGameFactory.h"

using namespace std;
cardGameFactory::cardGameFactory(){}

cardGame* cardGameFactory::createCardGame(string name, vector<Player*> players){
    if(name == "War"){
        return new War(players);
    }
    else if(name == "Blackjack")
    {
       // return new Blackjack(/*players*/);
    }
    
}