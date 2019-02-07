#ifndef CARD_GAME_FACTORY_H
#define CARD_GAME_FACTORY_H

#include "cardGame.h"
#include "../War/War.h"
#include <string>

/**
 * @brief cardGameFactory class creates a factory that creates a card game.
 * @details CardGameFactory class creates a factory that creates a card game, the type of game is passed in the createCardGame function.
 * @author Jacob Ross 250892852 
 **/
class cardGameFactory{
    public:
        /**
         * @brief cardGameFactory constructor creates a factory that creates a card game.
         * @details cardGameFactory class creates a factory that creates a card game.
         * @returns cardGameFactory object
         * @author Jacob Ross 250892852 
         **/
        cardGameFactory();
        /**
         * @brief createCardGame function creates the card game that is passed in the parameters
         * @details cardGameFactory function take the string passed and creates the appropiate type of game
         * @param name String containing the name of the game to be created, must be a valid game
         * @param players Vector containing a pointers to all players playing the game
         * @returns cardGame object
         * @author Jacob Ross 250892852 
         **/
        cardGame* createCardGame(std::string name, std::vector<Player*> players);
};
#endif