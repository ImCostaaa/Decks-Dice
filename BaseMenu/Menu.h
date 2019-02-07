
#ifndef MENU_H
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "../BasePlayer/Player.h"
#include "../LeaderBoard/LeaderBoard.h"
#include "../BaseDice/diceFactory.h"
#include "../BaseCard/cardGameFactory.h"
/**
 * @brief Menu Class represents the text based main menu which allows navigation of our program 
 * @details Menu class provides options off the bat to either login, register, check the leaderboard or exit
 * If register is chosen it adds this user to our userdata.txt ascii database, Login references the userdata and checks if the uname
 * and pword are valid. leaderboard allows for the display of the entire leaderboard or an individuals highscores. 
 * Exit command will exit our program whenever the option is available. 
 * The menu allows for navigation and implementation and all our other features.
 * @author Matthew Costa 250921778
 **/
class Menu
{
public:
/**
 * @brief Menu constructor which acts as the main for our program running everything through this.
 * @returns n/a
 * @params n/a
 * @details Menu constructor that continues to run until the user enters Exit, It continuously loops to different sections
 * depending on input to allow for the experience of a text based menu. Has multiple verification checks on input and
 * acts as a text based menu for our entire program.
 **/
Menu();
/**
 * @brief Registers the user into the userdata.txt database.
 * @returns void
 * @params the username and password of the user that is trying to register
 * @details Uses the paramaters given to register the user by adding them to the userdata.txt file. Method checks
 * for an existing profile with these credentials and if it finds one informs the user of a failed register. 
 * Method also checks if the params include a comma and informs the user that the registry cant happen with commas.

 **/
void registerUser(std::string uname, std::string pword);
/**
 * @brief allows user to view the leaderboard section.
 * @returns void
 * @params n/a
 * @details Allows user to view the leaderboard with one of two options. Either the user can choose to view 
 * one players leaderboard values or the entire leaderboard. Depending on the choice two different methods
 * from the leaderboard class are called.
 **/
void viewLeaderboard();
/**
 * @brief Allows user that is already registered to login.
 * @returns Pointer to the player that is logged in
 * @params the username and password of the user that is trying to login
 * @details Uses the paramaters given to check if the user is able to login. If valid username and password
 * the user is logged in and added to the playerlist. Otherwise it informs the user of invalid credentials. Makes
 * use of the player class to verify by calling ispseudo to see if the player returned was a valid user or a pseudo
 * profile returned. If valid stores this player as the loggedinuser
 **/
Player* login(std::string username, std::string password);
/**
 * @brief Returns a pointer to the currently logged in user.
 * @returns Pointer to logged in player
 * @params n/a
 * @details Returns the user that is saved as the logged in user. It returns the player as a player pointer
 * that is stored when a user logs in using the login function.
 **/
Player* getLoggedInUser();
/**
 * @brief returns the userlist of players currently playing/loggedin.
 * @returns vector of player pointers
 * @params n/a
 * @details Returns a vector which contains all the players currently logged in or playing the game. This
 * could contain pseudo profiles if a guest is playing the game instead of two logged in players.
 **/
std::vector<Player*> getUserList();
private:
std::vector<Player*> playerList;
Player* loggedinuser;
};
#endif
