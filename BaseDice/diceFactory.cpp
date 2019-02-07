#include "diceFactory.h" 

using namespace std;

//CS3307 - Group 5
//Date:         8 November, 2018
//Description:  Creates a dice game based on input

diceFactory::diceFactory()
{
    //empty constructor
}

diceGame * diceFactory::createDiceGame(string name, vector<Player*> players)
{
    if (name == "Pig")
    {
        return new pig(players);
    }
    else if (name == "Craps")
    {
        //return new Craps(players);
    }
}

