
#include "Menu.h"
using namespace std;
Menu::Menu()
{
	//
    string exitstring = "";
    while (exitstring.compare("Exit") != 0)
      {
      string currentChoice= "";
	  /* edited 11/22/2018 to make the first display of the Menu a little fancier with an intro menu title and improved spacing on all outputs*/
	      cout << "\n+---------+\n|MAIN MENU|\n+---------+\n";
		  cout << "\nPlease Enter one of the following;\n";
		  cout << " -- Login -- \n";
		  cout << " -- Register -- \n";
		  cout << " -- Leaderboard -- \n";
		  cout << " -- Exit -- \n";
		  cin >> currentChoice;
      if(currentChoice.compare("Exit")==0)
		{
		// exit program as the user has entered exit.
		exit(0);
		}
      else if (currentChoice.compare("Login")==0)
      {
		  // user wants to login allow entering of username and password
         string username = "";
         string password = "";
         bool failedlogin = true;
         while(failedlogin)
         {	
	    cout << "\nPlease enter your Username then your password to log in:\n";
            cin >> username;
            cin >> password;
			// check if valid
            Player* loggingIn = login(username,password);
            //if pseudo profile returned failed login
			failedlogin = loggingIn->isPseudo();
            if (!failedlogin)
            {
			   // valid login push player onto playerlist and set as loggedinuser
               playerList.push_back(loggingIn);
               loggedinuser = loggingIn;
            }
         }
         bool inputcheck = true;
         // once logged in enter what type of game you would like to play and allow user to enter their choice
         while(inputcheck)
         {
            string gametype="";
            cout << "\nPlease enter what type of game you would like to play, view leaderboard, Exit\n";
            cout << " -- Deck -- \n";
            cout << " -- Dice -- \n";
            cout << " -- Leaderboard -- \n";
            cout << " -- Exit -- \n";
            cin >> gametype;
            if (gametype.compare("Exit")==0)
            {
				// if user wants to exit while logged in allow them too here
                exit(0);
            }
            else if (gametype.compare("Deck")==0)
            {
                cardGameFactory* factory = new cardGameFactory(); 
               //list deck games to choose from
               string gamechoice="";
               bool inputcheck2 = true;
               while (inputcheck2)
               {
                  cout << "\nPlease enter what type of game you would like to play:\n";
                     cout << " -- Blackjack --\n ";
                     cout << " -- War --\n ";
                  cin >> gamechoice;
                  
					// if the user chose War go through neccessary information gathering to play
                    if (gamechoice.compare("War")==0)
                    {
                    int numplayers;
                    cout << "\nEnter number of players 1 or 2 only.\n";
                    cin >> numplayers;
                    if (numplayers == 2)
                    {
                    string uname;
                    string pass;
                    cout << "\nEnter username and password for second player if registered enter guest for guest\n";
                    cin >> uname;
                    cin >> pass;
                    Player* secondplayer = new Player(uname,pass);
                    playerList.push_back(secondplayer);
                    }
                     //start deckgame
                     cardGame* game = (factory->createCardGame(gamechoice,getUserList()));
                     game->play();
                     delete game;
                     playerList.pop_back();
                    inputcheck2= false;
                    
                    }
					else
					{
						cout << "\nInvalid game type OR Game not implemented due to time constraints\n";
					}
               }
            delete factory;
            }
            else if (gametype.compare("Leaderboard")==0)
            {
            viewLeaderboard();
            }
            else  if (gametype.compare("Dice")==0)
            {
                diceFactory* factory = new diceFactory(); 
               string gamechoice2="";
               bool inputcheck3 = true;
               while (inputcheck3)
               {
                  //list dice games to choose from
                  cout << "\nPlease enter what game you would like to play\n";
                     cout << " -- Craps --\n ";
                     cout << " -- Pig -- \n";
                  cin >> gamechoice2;
                  //start dicegame
				  // edited to only accept pig as other not implemented
                  if(gamechoice2.compare("Pig")==0)
                  {
                    int numplayers;
                    cout << "\nEnter number of players.\n";
                    cin >> numplayers;
                    if (numplayers >1)
                    {
                    for (int i =0; i <numplayers-1; i++)
                    {
                    string uname;
                    string pass;
                    cout << "\nEnter username and password for next player if registered enter gibberish for guest\n";
                    cin >> uname;
                    cin >> pass;
                    Player* nextplayer = new Player(uname,pass);
                    playerList.push_back(nextplayer);
                    }
                    }
                     //start deckgame
                     diceGame* game = (factory->createDiceGame(gamechoice2,getUserList()));
                     game->play();
                     delete game;
                     for (int i =0; i <numplayers-1; i++)
                     {
                     playerList.pop_back();
                     }                   
                    inputcheck3= false;
                    delete factory;
                  }
				  else
                  {
                     cout << "\nInvalid game type OR Game not implemented due to time constraints\n";
                  }
               }
            }
	    }
	    }
			// if the user wants to register
            else if (currentChoice.compare("Register")==0)
            {
               string username;
               string password;
               cout << "\nPlease enter a Username then a password of your choice to register\n";
               cin >> username;
               cin >> password;
               registerUser(username,password);
            }
            else if (currentChoice.compare("Leaderboard")==0)
            {
            viewLeaderboard();
            }
            else
            {
               cout << "\nInvalid Option. \n";
            }
       }
   }
vector<Player*> Menu::getUserList()
{
    return playerList;
}
void Menu::registerUser(string uname, string pword)
{
    ifstream userdata (USER_DATA);
    ofstream tempOutput;
    tempOutput.open(TEMP_DATA, std::ofstream::out | std::ofstream::trunc);
    string line;
    bool inLoginSection = false;
    bool unameIsUsed = false;
	bool commacheck = true;
	/* added 11/22/2018 this checks if the username or password of the user registering does not include commas as out parsing goes on commas*/
	while (commacheck)
	{
		if (uname.find(",") != std::string::npos || pword.find(",") != std::string::npos)
		{
			cout << "\nUsername/Password can't contain commas please reenter your username then password: \n";
			cin >> uname;
			cin >> pword;
		}
		else
		{
			commacheck = false;
		}
	}
	// check if username is used
    if(userdata.is_open()){
        while(!unameIsUsed && getline(userdata,line)){
            //If the username you want to change to is used by someone else, don't change it.
            if(line.find(uname) != string::npos){
                unameIsUsed = true;
            }
        }
    }
	// if username in use
    if(unameIsUsed){
        cout << "\nUsername in use\n" << endl;
    }
	// if not used register user appropriately
    if(!unameIsUsed){
        userdata.clear();
        userdata.seekg(0, ios::beg);
        if(userdata.is_open()){
            if(tempOutput.is_open()){
                //while you are are not in the section of the game
                while(!inLoginSection && getline(userdata,line)){
                    if(line.find(LOGIN_SECTION) != string::npos){
                        inLoginSection = true;
                    }
                    tempOutput << line << endl;
                }
                //Login section was found
                if(inLoginSection){
                    bool endOfSection = false;
                    while(!endOfSection && getline(userdata,line)){
                        if(line.find(",") == string::npos){ // new section.
                            endOfSection = true;
                            string newUser = "";
                            newUser = uname + "," + pword +","+ std::to_string(DEFAULT_BALANCE);
                            tempOutput << newUser << endl;
                        }
                        tempOutput << line << endl;
                    }
                    while (getline(userdata,line))
                    {
                        tempOutput << line << endl;
                    }
                    userdata.close();
                    tempOutput.close();
                
                    if(rename(TEMP_DATA,USER_DATA)){
                        perror("\nError renaming file\n");
                    }
                }
                else{
                    cout << "\nLogin section not found\n" << endl;
                   
                }
            }
            else{
                cout << "\nError opening temporary output file\n" << endl;
            }
        }
        else{
            cout << "\nError opening userdata.txt\n" << endl;
        }
    }
}
void Menu::viewLeaderboard()
{
	// if user chose view leaderboard it goes here
bool check = true;
string choice;
while(check)
    {
	// figure out which portion of leaderboard the user would like toview
    cout << "\nPlease enter what portion of leaderboard you would like to view: Entire OR Player\n";
    cin >> choice;
	// entire leaderboard pass to appropriate leaderboard function
    if (choice.compare("Entire")==0)
        {
        LeaderBoard viewboard = LeaderBoard();
        viewboard.view_highscores();
        check = false;
        }
	// just one player get username and then pass to leaderboard function
    else if (choice.compare("Player")==0)
        {
        string name;
        cout << "\nPlease enter player name to be looked up:\n";
        cin >> name;
        LeaderBoard viewboard = LeaderBoard();
        viewboard.view_player(name);
        check = false;
        }
    }
}
// return current loggedinuser
Player* Menu::getLoggedInUser()
{
return loggedinuser;
}
// login function creates new player to be logged in then uses the ispseudo from player class to verify login in the constructor
Player* Menu::login(string username,string password)
{
Player *loggedin = new Player(username, password);
return loggedin;
}
// main which calls constructor which runs whole program
int main()
{
Menu();
return 0;
}

