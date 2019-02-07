#ifndef DICE_GAME_H
#define DICE_GAME_H

#include "dice.h"
#include <vector>
#include "../BasePlayer/Player.h"

/**
 * @brief Interface for all dice games to use
 * @author Owen Hunsburger 250919957
 * @details Provides each dice game with dice and players required
**/


class diceGame{
    public:
        /**
        * @brief Constructor for creating a dice game
        * @author Owen Hunsburger 250919957
         * @returns a dice game
         * @details Creates a new instance of a dice game
        **/
        diceGame();
        /**
        * @brief Deconstructor for the dice game which frees memory
        * @author Owen Hunsburger 250919957
        * @details Deletes the dice used in previously made dice game
        **/
        ~diceGame();

        /**
        * @brief play function which allows the players to play the game
        * @author Owen Hunsburger 250919957
        * @details calls the game which implements the game logic and takes user input
        **/
        virtual void play() = 0;
    private:
        dice *playingDice;
        std::vector<Player*> playerList;
};
#endif