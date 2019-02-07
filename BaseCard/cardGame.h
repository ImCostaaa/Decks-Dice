#ifndef CARD_GAME_H
#define CARD_GAME_H

#include "Deck.h"

/**
 * @brief CardGame class creates a interface for all card games to follow.
 * @details CardGame class provides all card games a deck of cards and a player list to let the programmer use in game logic.
 * @author Jacob Ross 250892852 
 **/
class cardGame{
    public:
        /**
         * @brief CardGame constructor creates a base card game
         * @details CardGame constructor creates a base card game, and creates a new deck for the user to use.
         * @author Jacob Ross 250892852 
         * @returns cardGame object
         **/
        cardGame();
        /**
         * @brief CardGame deconstructor frees memory for objects being used
         * @details CardGame deconstructor frees the current deck being used
         * @author Jacob Ross 250892852 
         **/
        ~cardGame();
        /**
         * @brief play function contains all game logic, run to play
         * @details play function contains all game logic, implentation of this function is completely up to game designer
         * @author Jacob Ross 250892852 
         **/ 
        virtual void play() = 0;
    private:
        deck *playingDeck;
        std::vector<Player*> playerList;
};
#endif