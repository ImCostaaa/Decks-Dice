#include "Card.h"

using namespace std;
/*
*Card constructor makes a card, 1 is spade, 2 is club, 3 is heart, 4 is diamond 
*
*/
card::card(int s, int v){
    if(v <= KING && v >= ACE){
        value = v;
    }
    else{
        throw std::invalid_argument("Received card value < 1 or > 14");
    }
    if(s <= DIAMOND && s >= SPADE){
        suit = s;
    }
    else{
        throw std::invalid_argument("Received suit value < 1 or > 4");
    }
}

/*
*getSuit gets the int value of the suit
*
*/
int card::getSuit(){
    return suit;
}

//getValue gets the int value of the card
int card::getValue(){
    return value;
}

//Gets name of the suit
string card::getSuitName(){
    string toReturn;
    if(suit == SPADE){
        toReturn = "Spade";
    }
    else if(suit == CLUB){
        toReturn = "Club";
    }
    else if(suit == HEART){
        toReturn = "Heart";
    }
    else if(suit == DIAMOND){
        toReturn = "Diamond";
    }
    return toReturn;
}

//gets name of the value of card
string card::getValueName(){
    string toReturn;
    if(value == ACE){
        toReturn = "Ace";
    }
    else if(value == KING){
        toReturn = "King";
    }
    else if(value == QUEEN){
        toReturn = "Queen";
    }
    else if(value == JACK){
        toReturn = "Jack";
    }
    else{
        toReturn = to_string(value);
    }
    return toReturn;
}