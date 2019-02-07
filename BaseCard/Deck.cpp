#include "Deck.h"

using namespace std;

//Constructor creates a normal 52 card deck
deck::deck(){
    for(int i = 1; i < 14; i++){
        for(int k = 1; k < 5; k++){
            card *toAdd = new card(k,i);
            deckList.push_back(toAdd);
        }
    }
}

//Gets the number of cards in the deck
int deck::getDeckSize(){
    return deckList.size();
}

//adds a card to the deck
int deck::addCard(int suit, int value){
    card *toAdd = new card(suit,value);
    deckList.push_back(toAdd);
}

//removes a card from the deck
int deck::removeCard(int suit, int value){
    for(int i = 0; i < deckList.size(); i++ ){
        if(deckList[i] -> getSuit() == suit && deckList[i] -> getValue() == value){
            card *tempcard = deckList[i];
            deckList.erase(deckList.begin()+i);
            delete tempcard;
            return 1;
        }
    }
    return -1;
}

//shuffles the deck of cards.
void deck::shuffle(){
    random_shuffle(deckList.begin(),deckList.end());
}


void deck::deal(Player *user){
    card * tempCard = draw();
    cout << tempCard -> getSuitName() << " " << tempCard -> getValueName() << endl;
    vector<card*> tempHand = user -> getCurrentHand();
    tempHand.push_back(tempCard);
    user -> setCurrentHand(tempHand);
}


card * deck::draw(){
    card *temp = deckList.front();
    deckList.erase(deckList.begin());
    return temp;
}