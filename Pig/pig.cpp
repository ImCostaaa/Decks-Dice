#include "pig.h"

using namespace std;

pig::pig(vector<Player*> players)
{
    playerList = players;
    d = new dice();
}

pig::~pig()
{
    delete d;
}

void pig::play()
{
    input = "";

    int numOfPlayers = playerList.size();
    cout << "\n+---------------+\n|Welcome to PIG!|\n+---------------+\n" << endl;
    cout << "\nThere are " << numOfPlayers << " player(s).\n----------------------\n" << endl;

    for (int i = 0; i < numOfPlayers; i++)
    {
        playerList[i] -> setCurrentGameScore(0);
    }
    
    for (int n = 0; n < numOfPlayers; n++)  //Game logic
    {
        plyr = playerList[n] -> getUsername();
        score = 0;
        currentRoll = 0;
        playing = true;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << plyr << " IT'S YOUR TURN!";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
        while (playing) 
        {
            cout << plyr << ", your current score is: " << score << endl;
            cout << "Would you like to roll? (y/n)\n";
            cin >> input;
            cout << endl << endl;
            if (input.compare("y") == 0 || input.compare("yes") == 0) {
                currentRoll = d -> roll(6, 1);
                cout << "You have rolled a " << currentRoll << "." << endl;
                if (currentRoll == 1) {
                    score = 0;
                    cout << "\n" << plyr << " finished with a score of " << score;
                    cout << "\nThanks for playing." << endl;
                    playerList[n] -> setCurrentGameScore(0);
                    playing = false;
                }
                else
                {
                    score = score + currentRoll;
                }

            }
            else if (input.compare("n") == 0 || input.compare("no") == 0)
            {
                cout << plyr << " you finished with a score of " << score << endl;
                playerList[n] -> setCurrentGameScore(score);
                playing = false;
            }
            else
            {
                cout << "Not a recognized command. Please try again." << endl;
            }
        
            cout << "\n~~~~~~~~~~~~~~~~~~~~\n\n";
        }//end while
    }//end for

    for (int n = 0; n < numOfPlayers; n++)  //print scores
    {
        plyr = playerList[n] -> getUsername();
        score = playerList[n] -> getCurrentGameScore();
        cout << plyr << " had " << score <<  " point(s)";
        if (score > playerList[n] -> getHighscore("PIG"))
        {
            playerList[n] -> setHighscore("PIG", score);
            cout << "\t New Highscore!";
        }
        cout << endl;
    }

    cout << "Thanks for playing!\n";
}