#ifndef PLAYER_H
#define PLAYER_H
#define USER_DATA "./BasePlayer/userdata.txt"
#define TEMP_DATA "./BasePlayer/tempOut.txt"
#define LOGIN_SECTION "LOGIN"
#define DEFAULT_BALANCE 500
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "./../BaseCard/Card.h"

/**
 * @author Thomas Morphew 250921958
 * @brief Provides a class representation of everything a player has in and associated with a game.
 * 
 * The Player class represents someone playing the game.
 * All Players will have a username, password, and a balance that they can bring between gambling games.
 * An instance of this class has quick access data stored in its instance variables. Changing these values
 * will also write them to a file for recording purposes.
 * A Player in a card game may have a "hand" of cards to keep track of what cards are available.
 * Players can be both "real" or "pseudo" (which effectively means temporary). This duality of the class
 * lets it represent AI's that games may need to run or double as a temporary profile for a trial player.
 **/
class Player{
    public:
        /**
         * @brief Empty constructor which makes a temporary profile with default values for variables.
         * @returns a pseudo profile with default values for instance variables.
         * 
         * @details An empty constructor which makes a temporary profile with default values for variables.
         * This can be used as a temporary player, ideal for AI in games.
         **/
        Player();
        /**
         * @brief Constructor which Checks records for a user and logs them in.
         * @param uname is the username of a player's record
         * @param pword is the password of a player's record
         * @returns a player's profile with their saved data loaded into the object if login successful, otherwise it returns a temporary profile.
         * 
         * @details Primary constructor for Player class, it performs a login with the associated memory file and then fills 
         * the class's instance variables with the correct values from the file. If the login is unsuccessful, then a pseudo
         * profile is returned instead.
         **/
        Player(std::string uname, std::string pword);
        /**
         * @brief Getter method for the Player's username
         * @returns the username for the Player object
         * 
         * @details Getter method for the Player's username. Useful for displaying in games.
         **/
        std::string getUsername();
        /**
         * @brief Setter method for the Player's username
         * @param uname is the new username for the record
         * @returns void
         * 
         * @details Sets the username for the object and also saves it to the record file if it is not in use.
         **/
        void setUsername(std::string uname);
        /**
         * @brief Getter method for the Player's password
         * @returns the password for the Player object
         * 
         * @details Getter method for the Player's password. Useful for logging in (security).
         **/
        std::string getPassword();
        /**
         * @brief Setter method for the Player's password
         * @param pword is the new password for the record
         * @returns void
         * 
         * @details Sets the password for the object and also saves it to the record file.
         **/
        void setPassword(std::string pword);
        /**
         * @brief Getter method for the Player's balance
         * @returns the balance for the Player object
         * 
         * @details Getter method for the Player's balance. Useful for keeping track of money between games.
         **/
        double getBalance();
        /**
         * @brief Setter method for the Player's balance
         * @param bal is the new balance for the record
         * @returns void
         * 
         * @details Sets the balance for the object and also saves it to the record file.
         **/
        void setBalance(double bal);
        /**
         * @brief Getter method for the Player's highscore
         * @param game is the name of the game in the record file
         * @returns the highscore for the Player for the game given by the parameter
         * 
         * @details Gets the highscore of the Player for the game given by the parameter. Accesses the
         * record file directly, may perform slowly for large files.
         **/
        double getHighscore(std::string game);
        /**
         * @brief Setter method for the Player's highscore for the given game
         * @param game is the name of the game in the record file
         * @param score is the new score of the game to save to the record file
         * @returns void
         * 
         * @details Sets the highscore of the Player for the game given by the parameter. Saves the new
         * highscore to record file.
         **/
        void setHighscore(std::string game, double score);
        /**
         * @brief Getter method for the Player's current game score
         * @returns the current score for the Player in the game they are playing
         * 
         * @details Gets the current score of the Player for the game they are currently playing in.
         **/
        double getCurrentGameScore();
        /**
         * @brief Setter method for the Player's current game score
         * @param score is the new score of the current game to save to the record file
         * @returns void
         * 
         * @details Sets the current score of the Player for the game they are current playing in.
         **/        
        void setCurrentGameScore(double score);
        /**
         * @brief Checks if the user object is a temp or is a pseudo profile.
         * @returns a bool, true if the Player is a pseudo profile or false otherwise.
         * 
         * @details Checks if the player is a pseudo (temporary) player. Pseudo players are temporary
         * and do not save to the record file.
         **/
        bool isPseudo();
        /**
         * @brief Getter method for the Player's current hand in the game they are playing
         * @returns the current hand of cards for the Player in the game they are playing
         * 
         * @details Gets the current hand of cards the Player has for the game they are currently playing in.
         **/
        std::vector<card*> getCurrentHand();
        /**
         * @brief Setter method for the Player's current hand
         * @param hand is the new hand of the current game the player is in.
         * @returns void
         * 
         * @details Sets the current hand of cards the Player has for the game they are current playing in.
         **/    
        void setCurrentHand(std::vector<card*> hand);
        /*
        Dice[] getCurrentRoll();
        void setCurrentRoll(Dice[] dice);
        std::string to_string();
        */
    private:
        std::string username;
        std::string password;
        double balance; 
        bool pseudo;
        std::vector<card*> currentHand;
        /*
        Dice[] currentRoll;
        */
        double currentGameScore;
};

#endif
