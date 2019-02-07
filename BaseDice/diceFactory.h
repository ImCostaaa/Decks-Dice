#ifndef DICEFACTORY_H
#define DICEFACTORY_H

#include "diceGame.h"
#include "../Pig/pig.h"
#include <string>

/**
 * @brief Creates a faactory that produces dice games
 * @author Owen Hunsburger 250919957
 * @description creates a factory which in turn creates a dice game based on the input name 
 **/

class diceFactory
{
    public:
    /**
    * @brief Empty constructor function
    * @author Owen Hunsburger 250919957
    * @returns Allows for the factory to be called and produce a game
    * @details the calass
    **/
        diceFactory();

        /**
         * @brief creates a dice game based on the parameters
         * @author Owen Hunsburger 250919957
         * @param name is a String that tells the function which game to create
         * @param players is a Vector that contains pointers to all players that are playing the game
         * @returns diceGame object
         * @details The function creates an instance of a game based on the input game name and allows the inputted used to play
         **/
        diceGame * createDiceGame(std::string name,std::vector<Player*> players);
};
#endif
