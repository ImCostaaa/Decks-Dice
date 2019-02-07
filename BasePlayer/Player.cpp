
/*
 * Thomas Morphew, 250921958
 * Players. Players need to be able to:
 * Create an account.
 * Sign in to their account.
 * Change password?
 * See their highscore.
 * Pass credentials to a game.
 * Have this stored in file(s)
 */
#include "Player.h"

using namespace std;

/*
 * A Pseudo player. 
 * Doesn't record high scores but allows you to play games
 */
Player::Player(){
    //These properties are pseudo player properties.
    username = "";
    password = "";
    balance = DEFAULT_BALANCE;
    pseudo = true;
    
    //vector<card*> currentHand = NULL; //Should be vector
    /*
    Dice[] currentRoll = NULL; //Should be vector
    */
    double currentGameScore = 0;
}

/*
 * The constructor. This function returns either a pseudo player or 
 * a player with data loaded in from memory.
 */
Player::Player(std::string uname, std::string pword){
    /*
     * INCOMPLETE FUNCTION. Needs to be able to handle login search up?
     * Needs to be able to handle usernames and passwords which are substrings
     * of other usernames and passwords
     */
    //Initialize instance variables in case data lookup fails
    username = "";
    password = "";
    balance = DEFAULT_BALANCE;
    pseudo = true;
    
    //vector<card*> currentHand = NULL;
    /*
    Dice[] currentRoll = NULL;
    */
    double currentGameScore = 0;

    //create variables to read in data
    ifstream userdata (USER_DATA);
    string line;
    bool inLoginSection = false;
    
    //Scan file for uname and password combo, if found, retrieve balance. Else create sudo player.
    if(userdata.is_open()){

        //while you are are not in the section of the game, getline until you find it
        while(!inLoginSection && getline(userdata,line)){
            if(line.find(LOGIN_SECTION) != string::npos){
                inLoginSection = true;
            }
        }
        //Login section was found
        if(inLoginSection){
            bool endOfSection = false;
            while(!endOfSection && getline(userdata,line)){
                //If you find a valid account, update variables accordingly
                if(line.find(uname) != string::npos && line.find(pword) != string::npos){
                    int pos = line.find(',');
                    int pos2 = line.find(',', pos+1);
                    //Extract the saved username and password
                    string savedUsername = line.substr(0, pos);
                    string savedPassword = line.substr(pos+1,pos2-(pos+1));
                    
                    //If the username is correct
                    if(uname.compare(savedUsername) ==0){
                        //And if the password is correct
                        if(pword.compare(savedPassword) ==0){
                            //Then it is valid login, assign vars
                            balance = stod(line.substr(pos2 + 1,string::npos));
                            username = uname;
                            password = pword;
                            pseudo = false;
                        }
                    }
                }
                if(line.find(",") == string::npos){ // new section.
                    endOfSection = true;
                    //no username was found, exit early, return pseudo profile (default values)
                }
            }
        }
        else{
            cout << "Login section not found" << endl;
            //Returns pseudo profile (default values)
        }
        userdata.close();
    }
    else{
        cout << "Error openening userdata.txt" << endl;
    }
    //Success, return Player object with correct instance variables
}

/*
 * Retrieve the username from the Player
 */
std::string Player::getUsername(){
    return username;
}

/*
 * If the username is not going to overwrite someone else's username then
 * set the instance variable for the Player's username and write to USER_DATA file
 */
void Player::setUsername(std::string uname){
    //Pseudo players do not save data
    if(this->isPseudo()){
        username = uname;
        return;
    }

    //File search/write variables
    ifstream userdata (USER_DATA);
    ofstream tempOutput;
    tempOutput.open(TEMP_DATA, std::ofstream::out | std::ofstream::trunc);
    string line;
    bool inLoginSection = false;
    bool unameIsUsed = false;

    //Scan the file for overwriting username
    if(userdata.is_open()){
        //Maybe have this fast stop?
        while(!unameIsUsed && getline(userdata,line)){
            //If the username you want to change to is used by someone else, don't change it.
            if(line.find(uname) != string::npos){
                int position = line.find(",");
                string savedUsername = line.substr(0,position);
                if(uname.compare(savedUsername)==0){
                    unameIsUsed = true;
                }
            }
        }
    }

    //Then go ahead and write to file if the name is not in use
    if(!unameIsUsed){
        //Reset file pointer to beginning
        userdata.clear();
        userdata.seekg(0, ios::beg);
        if(userdata.is_open()){
            if(tempOutput.is_open()){
                //Find the username in USER_DATA file and update every entry of it
                while(getline(userdata,line)){
                    //If you find the username, update it
                    if(line.find(username) != string::npos){
                        int position = line.find(",");
                        string savedUsername = line.substr(0, position);
                        
                        //If the username is correct
                        if(username.compare(savedUsername) ==0){

                            int pos = line.find(",");
                            string tempLine = line.substr(pos, string::npos); //Include comma
                            tempLine = uname + tempLine;
                            line = tempLine;
                            //Finally, update instance variable
                        }
                    }
                    //If you don't find the username, don't update it.
                    tempOutput << line << endl;
                }

                //Once all usernames in the file have been updated, update object's instance variable
                username = uname;
                userdata.close();
                tempOutput.close();
                
                //overwrite file
                if(rename(TEMP_DATA,USER_DATA)){
                    perror("Error renaming file\n");
                }
                
            }
            else{
                cout << "Error opening temporary output file" << endl;
            }
        }
        else{
            cout << "Error opening userdata.txt" << endl;
        }
    } //If the uname is entered is already in use, then do not update the file
    return;
}

/*
 * Returns the Player's password
 */
std::string Player::getPassword(){
    return password;
}

/*
 * Sets the Player's password and writes it to file
 */
void Player::setPassword(std::string pword){
    if(this->isPseudo()){
        return;
    }

    ifstream userdata (USER_DATA);
    ofstream tempOutput;
    tempOutput.open(TEMP_DATA, std::ofstream::out | std::ofstream::trunc);
    string line;
    bool inLoginSection = false;
    bool updatedPassword = false;

    if(userdata.is_open()){
        if(tempOutput.is_open()){
            //while you are are not in the Login section of the file
            while(!inLoginSection && getline(userdata,line)){
                if(line.find(LOGIN_SECTION) != string::npos){
                    inLoginSection = true;
                }
                tempOutput << line << endl;
            }

            //Login was found
            if(inLoginSection){
                //Find the username in the Login section
                while(getline(userdata,line)){
                    //If you find the username, update it
                    if(!updatedPassword && line.find(username) != string::npos){

                        int position = line.find(",");
                        string savedUsername = line.substr(0, position);
                        
                        //If the username is correct
                        if(username.compare(savedUsername) ==0){
                            
                            int pos = line.find(",");
                            int pos2 = line.find(",", pos+1);
                            string unamePart = line.substr(0, pos+1); //Include comma
                            string balPart = line.substr(pos2,string::npos); //Include comma
                            string tempLine = unamePart + pword + balPart;
                            line = tempLine;
                            //Finally, update instance variable
                            password = pword;
                            updatedPassword = true;
                        }
                    }
                    //If you don't find the username, don't update it.
                    tempOutput << line << endl;
                }
            }
            else{
                cout << "Login section not found" << endl;
            }
            userdata.close();
            tempOutput.close();
            
            if(rename(TEMP_DATA,USER_DATA)){
                perror("Error renaming file\n");
            }
            
        }
        else{
            cout << "Error opening temporary output file" << endl;
        }
    }
    else{
        cout << "Error opening userdata.txt" << endl;
    }

    return;
}

double Player::getBalance(){
    return balance;
}

void Player::setBalance(double bal){
    /*
     * INCOMPLETE FUNCTION, NEEDS TO SET BALANCE FOR 
     * SPECIFIC PLAYER
     */
    if(this->isPseudo()){
        balance = bal;
        return;
    }

    ifstream userdata (USER_DATA);
    ofstream tempOutput;
    tempOutput.open(TEMP_DATA, std::ofstream::out | std::ofstream::trunc);
    string line;
    bool inLoginSection = false;
    bool updatedBal = false;

    if(userdata.is_open()){
        if(tempOutput.is_open()){
            //while you are are not in the Login section of the file
            while(!inLoginSection && getline(userdata,line)){
                if(line.find(LOGIN_SECTION) != string::npos){
                    inLoginSection = true;
                }
                tempOutput << line << endl;
            }

            //Login was found
            if(inLoginSection){
                //Find the username in the game section
                while(getline(userdata,line)){
                    //If you find the username, update it
                    if(!updatedBal && line.find(username) != string::npos){

                        int position = line.find(",");
                        string savedUsername = line.substr(0, position);
                        
                        //If the username is correct
                        if(username.compare(savedUsername) ==0){
                            
                            int pos = line.find(",");
                            pos = line.find(",", pos+1);
                            string tempLine = line.substr(0,pos+1);
                            tempLine = tempLine + std::to_string(bal);
                            line = tempLine;
                            //Finally, update instance variable
                            balance = bal;
                            updatedBal = true;
                        }
                    }
                    //If you don't find the username, don't update it.
                    tempOutput << line << endl;
                }
            }
            else{
                cout << "Login section not found" << endl;
            }
            userdata.close();
            tempOutput.close();
            
            if(rename(TEMP_DATA,USER_DATA)){
                perror("Error renaming file\n");
            }
            
        }
        else{
            cout << "Error opening temporary output file" << endl;
        }
    }
    else{
        cout << "Error opening userdata.txt" << endl;
    }

    return;
}

double Player::getHighscore(std::string game){
    /*
     * INCOMPLETE FUNCTION, NEEDS TO FIND HIGHSCORE FOR
     * SPECIFIC GAME OR SOMETHING
     */
    if(this->isPseudo()){
        return 0;
    }

    double highscore = 0;
    ifstream userdata (USER_DATA);
    string line;
    bool inGameSection = false;

    if(userdata.is_open()){
        
        //while you are are not in the section of the game
        while(!inGameSection && getline(userdata,line)){
            if(line.find(game) != string::npos){
                inGameSection = true;
            }
        }
        //Game was found
        if(inGameSection){
            bool endOfSection = false;
            while(!endOfSection && getline(userdata,line)){
                if(line.find(username) != string::npos){

                    int position = line.find(",");
                    string savedUsername = line.substr(0, position);
                        
                    //If the username is correct
                    if(username.compare(savedUsername) ==0){
                        int pos = line.find(",");
                        highscore = stod(line.substr(pos + 1,string::npos));
                    }
                }
                if(line.find(",") == string::npos){ // new section.
                    endOfSection = true;
                    //no username was found, return 0;
                }
            }
        }
        else{
            cout << "Game not found" << endl;
        }
        userdata.close();
    }
    else{
        cout << "Error openening userdata.txt" << endl;
    }
    

    return highscore;
}

void Player::setHighscore(std::string game, double score){
    /*
     * INCOMPLETE FUNCTION, NEEDS TO SET HIGHSCORE FOR 
     * SPECIFIC GAME OR SOMETHING
     */
    //If pseudo, don't set highscore.
    if(this->isPseudo()){
        return;
    }

    ifstream userdata (USER_DATA);
    ofstream tempOutput;
    tempOutput.open(TEMP_DATA, std::ofstream::out | std::ofstream::trunc);
    string line;
    bool inGameSection = false;
    bool updatedScore = false;

    if(userdata.is_open()){
        if(tempOutput.is_open()){
            //while you are are not in the section of the game
            while(!inGameSection && getline(userdata,line)){
                if(line.find(game) != string::npos){
                    inGameSection = true;
                }
                tempOutput << line << endl;
            }

            //Game was found
            if(inGameSection){
                //Find the username in the game section
                while(getline(userdata,line)){
                    //If you find the username, update it
                    if(!updatedScore){
                        if(line.find(username) != string::npos){

                            int position = line.find(",");
                            string savedUsername = line.substr(0, position);
                            
                            //If the username is correct
                            if(username.compare(savedUsername) ==0){

                                int pos = line.find(",");
                                string tempLine = line.substr(0,pos+1);
                                tempLine = tempLine + std::to_string(score);
                                line = tempLine;
                                updatedScore = true;
                            }
                        }
                        //If you don't find the username, make a new entry under this game and update it
                        if(line.find(",") == string::npos){
                            //no username was found, so make a new entry for this user
                            tempOutput << username + "," + std::to_string(score) << endl;
                            updatedScore = true;
                        }
                    }
                    tempOutput << line << endl;
                }
                if(!updatedScore){
                    tempOutput << username + "," + std::to_string(score) << endl;
                    updatedScore = true;
                }
            }
            //Game was not found, make a new entry for the game
            else{
                tempOutput << endl;
                tempOutput << game << endl;
                tempOutput << username + "," + std::to_string(score) << endl;
                while(getline(userdata,line)){
                    tempOutput << line << endl;
                }
            }
            userdata.close();
            tempOutput.close();
            
            if(rename(TEMP_DATA,USER_DATA)){
                perror("Error renaming file\n");
            }
            
        }
        else{
            cout << "Error opening temporary output file" << endl;
        }
    }
    else{
        cout << "Error opening userdata.txt" << endl;
    }

    return;
}


std::vector<card*> Player::getCurrentHand(){
    return currentHand;
}

void Player::setCurrentHand(std::vector<card*> hand){
    currentHand = hand;
}
/*
Dice[] Player::getCurrentRoll(){
    return currentRoll;
}

void Player::setCurrentRoll(Dice[] dice){
    currentRoll = dice;
    return;
}

std::string Player::to_string(){
    //print username?
    return "";

}
*/

double Player::getCurrentGameScore(){
    return currentGameScore;
}

void Player::setCurrentGameScore(double score){
    currentGameScore = score;
    return;
}

bool Player::isPseudo(){
    if(pseudo){
        return true;
    }
    else{
        return false;
    }
}

