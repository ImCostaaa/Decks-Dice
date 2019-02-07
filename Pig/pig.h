#ifndef PIG_H
#define PIG_H

#include <string>
#include <iostream>
#include <vector>
#include "../BaseDice/diceGame.h"
#include "../BaseDice/diceFactory.h"

/**
 * @brief Contains all the logic required for pig, a dice game
 * @author Owen Hunsburger 250919957
 * @details Uses dice object and a vector of players, uses diceGame as a template
**/

class pig : public diceGame
{
    public:
        pig(std::vector<Player*> players);
        ~pig();
        void play();
    private:
        std::vector<Player*> playerList;
        int numOfPlayers;
        dice *d;
        int score;
        int currentRoll;
        bool playing;
        std::string input;
        std::string plyr;
        int topScore;
        Player topPlayer;
        bool tie;
        int count;
};

#endif