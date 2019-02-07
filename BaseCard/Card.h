#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <stdexcept>

/**
 * @brief Card class represents a playing card with a suit and value.
 * @details Card class provides functions to convert number values of cards to their string representation. \n
 * Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King \n
 * Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
 * @author Jacob Ross 250892852 
 **/
class card{
    public:
        /**
         * @brief Card constructor creates a Card object.
         * @details Card constructor creates a Card object using numbers to represent the values of the cards.
         * @param value Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King
         * @param suit Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
         * @returns card object
         * @author Jacob Ross 250892852 
         **/
        card(int suit, int value);
        /**
         * @brief getSuit gets the suit value as an integer
         * @details Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King
         * @returns suit value as an integer
         * @author Jacob Ross 250892852 
         **/
        int getSuit();
        /**
         * @brief getValue gets the card value as an integer
         * @details Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
         * @returns card value as an integer
         * @author Jacob Ross 250892852 
         **/
        int getValue();
        /**
         * @brief getSuit gets the suit value as an String
         * @details Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
         * @returns suit value as an String
         * @author Jacob Ross 250892852 
         **/
        std::string getSuitName();
        /**
         * @brief getValue gets the card value as an String
         * @details Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King
         * @returns card value as an String
         * @author Jacob Ross 250892852 
         **/
        std::string getValueName();
    private:
        const int ACE = 1;
        const int JACK = 11;
        const int QUEEN = 12;
        const int KING = 13;
        const int SPADE = 1;
        const int CLUB = 2;
        const int HEART = 3;
        const int DIAMOND = 4;
        int suit;
        int value;
};
#endif