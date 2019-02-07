#ifndef DECK_H
#define DECK_H

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Card.h"
#include "../BasePlayer/Player.h"

/**
 * @brief deck class creates deck of cards
 * @details deck class creates deck of cards, each card is a pointer to a card object
 * @author Jacob Ross 250892852 
 **/
class deck{
    public:
        /**
         * @brief deck constructor creates a deck of cards
         * @details deck constructor creates deck of cards, each card is a pointer to a card object, by default this create a deck of 52 cards
         * @returns deck object
         * @author Jacob Ross 250892852 
         **/
        deck();
        /**
         * @brief getDeckSize function returns the size of the deck
         * @details getDeckSize function returns the number of cards currently left in the deck
         * @returns Integer that is the size of the deck
         * @author Jacob Ross 250892852 
         **/
        int getDeckSize();
        /**
         * @brief addCard function adds a card to the deck
         * @details addCard function creates a new card and adds it to the deck
         * @param suit Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
         * @param value Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King
         * @author Jacob Ross 250892852 
         **/
        int addCard(int suit, int value);
        /**
         * @brief addCard function removes a card to the deck
         * @details addCard function removes a card from the deck
         * @param suit Suit values are: 1 being Spade, 2 being Club, 3 being Heart, 4 being Diamond
         * @param value Face values are: 1 being Ace, 11 being Jack, 12 being Queen, 13 being King
         * @author Jacob Ross 250892852 
         **/
        int removeCard(int suit, int value);
        /**
         * @brief suffle function randomizes the cards in the deck
         * @details suffle function randomizes the cards in the deck
         * @author Jacob Ross 250892852 
         **/
        void shuffle();
        /**
         * @brief deal function deals a card to a Player
         * @details deal function deals a card from the deck and adds it to a players hand
         * @param user User to add the card to
         * @author Jacob Ross 250892852 
         **/
        void deal(Player *user);
        /**
         * @brief draw function draws a card from the deck
         * @details draw function draws a card from the deck, once the card is drawn the card is removed
         * @returns a pointer to a card object
         * @author Jacob Ross 250892852 
         **/
        card * draw();
    private:
        int deckSize;
        std::vector<card*> deckList;
};

#endif