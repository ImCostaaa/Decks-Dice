#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "../BasePlayer/Player.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

/**
*
*@brief  Provides Class representation of the LeaderBoard and ways to view the LeaderBoard
*@details Allows any Player while in the menu  to view the entire LeaderBoard or the highscores of a specific Player
*@author Mark Jaskiewicz 250925120
**/

class LeaderBoard{
  public:
/**
*@brief Constructor for the LeaderBoard gets all the highscore data from the Data file
*@returns returns a vector contains all Player names and highscores, Also every Game name
*
*@details Uses the Data file defined in The Player.h file, Skips all unneeded Information Ie. Login info
**/
    LeaderBoard();

/**
*@brief Method to view the highscores of an individual player
*@param name, Used to specify the players Highscores you wish to view
*@returns void: but outputs to std out the Game names along with the player name and all their highscores
*
*@details Uses the vector created in constructor to get all required info
**/
    void view_player(std::string name);

/**
*@brief Method to view the entire LeaderBoard table, Highscores of all players
*@param None
*@returns void: but outputs all players and their respected highscore for each game
*
*@details Uses the vector created constured to output required info
**/
    void view_highscores();
  private:
    std::vector<std::string> highscores;
};
#endif
