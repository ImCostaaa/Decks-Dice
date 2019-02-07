#ifndef DICE_H
#define DICE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * @author Owen Hunsburger 250919957
 * @brief Simulates the rolling of dice
 * @details The Dice class allows the users to input the number of sides on the dice and the number of rolls.
 **/
class dice
{
    public:
        /**
         * @brief Empty constructor to allow the declaration of a Dice object
         * @author Owen Hunsburger 250919957
         * @returns NULL
         * @details Allows objects in other classes to call the roll command, delaring the number of sides and rolls each time the function is called.
         **/
        dice();

        /**
         * @brief Simulates the roll of (Y) dice with (X) sides
         * @author Owen Hunsburger 250919957
         * @param numOfSides is an int that represents the number of sides on the dice thats to be rolled
         * @param numOfRolls is an int that represents the number of times the dice will be rolled
         * @returns The sum of all the required rolls
         * @details Randomly generate a number (Z), modulo the number by X then add 1. Performs this Y times, adding the total of each simulated roll to the returned value. 
         **/
        int roll(int numOfSides, int numOfRolls);   //roll Y dice with X sides and return the sum of the rolls (X = numOfSides, Y = numOfRolls)
    
    private:
        int sum;
};

#endif
