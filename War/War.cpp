#include "War.h"

using namespace std;

War::War(vector<Player*> players){
    playerList = players;
    playingDeck = new deck();
}

War::~War(){
    delete playingDeck;
}

void War::play(){
    int listSize = playerList.size();
    int player1Score = 0;
    int player2score = 0;
    int playerScore = 0;
    if(listSize == 1){ //One player
        int playagain = 1; // value to see if user wants to play again
        while(playagain != 0){
            vector<card*> aiHand;
            vector <card*> playerHand = playerList[0] -> getCurrentHand();
            aiHand.clear();
            playerHand.clear();
            playingDeck -> shuffle();
            int size = playingDeck ->getDeckSize();
            for(int i = 0; i < size/2; i++){ //Remove all cards from the deck and add half to each players hands
                aiHand.push_back(playingDeck -> draw());
                playerHand.push_back(playingDeck -> draw());
            }
            delete playingDeck; // Make a new deck in case user wants to play again
            playingDeck = new deck();
            //player card is the card player flips, playerwar1 is the card flipped face down, playerwar2 is the card flipper face up 
            card *playerCard,*aiCard,*aiWar1,*aiWar2,*playerWar1,*playerWar2;
            int userinput = 1;
            while(userinput != 0){ //run until user enters 0
                playerList[0] -> setCurrentHand(playerHand);
                playerHand = playerList[0] -> getCurrentHand();
                int p = playerHand.size();
                int a = aiHand.size();
                if(p != 52 && a != 52){ //Player or ai wins when their hand has 52 cards
                    cout << "Enter 1 to draw a card 0 to quit" << endl;
                    cin >> userinput;
                    if(userinput == 1){ //if user doesnt quit
                        playerCard = playerHand.front(); //save player front card
                        playerHand.erase(playerHand.begin()); //remove player front card
                        aiCard = aiHand.front(); //save ai front card
                        aiHand.erase(aiHand.begin()); //remove player front card
                        cout << "You drew the " << playerCard ->getValueName() << " of " << playerCard ->getSuitName() << "s" << endl;
                        cout << "AI drew the " << aiCard ->getValueName() << " of " << aiCard ->getSuitName() << "s" << endl; 
                        if(playerCard -> getValue() > aiCard -> getValue()){ // If player card is greater
                            playerHand.push_back(playerCard); //add cards to players hand
                            playerHand.push_back(aiCard);
                            cout << "Player won, " << playerHand.size() << " cards in hand." << endl;
                        }
                        else if(playerCard -> getValue() < aiCard -> getValue()){ //if ai card is greater
                            aiHand.push_back(playerCard); //add cards to ai hand
                            aiHand.push_back(aiCard);
                            cout << "Ai won, " << aiHand.size() << " cards in hand." << endl;
                        }
                        else{ // War is started
                            while(1){ // run until war is ended
                                //draws two cards from each players hand
                                playerWar1 = playerHand.front();
                                playerHand.erase(playerHand.begin());
                                playerWar2 = playerHand.front();
                                playerHand.erase(playerHand.begin());
                                aiWar1 = aiHand.front();
                                aiHand.erase(aiHand.begin());
                                aiWar2 = aiHand.front();
                                aiHand.erase(aiHand.begin());

                                cout << "You drew the " << playerWar2 ->getValueName() << " of " << playerWar2 ->getSuitName() << "s" << endl;
                                cout << "AI drew the " << aiWar2 ->getValueName() << " of " << aiWar2 ->getSuitName() << "s" << endl; 
                                if(aiWar2 -> getValue() < playerWar2 -> getValue()){ //compares the "faceup" card
                                    playerHand.push_back(playerCard);
                                    playerHand.push_back(playerWar1);
                                    playerHand.push_back(playerWar2);
                                    aiHand.push_back(aiCard);
                                    aiHand.push_back(aiWar2);
                                    aiHand.push_back(aiWar1);
                                    cout << "Player won, " << playerHand.size() << " cards in hand." << endl;
                                    break;
                                }
                                else if(aiWar2 -> getValue() > playerWar2 -> getValue()){//compares the "faceup" card
                                    playerHand.push_back(playerCard);
                                    playerHand.push_back(playerWar1);
                                    playerHand.push_back(playerWar2);
                                    aiHand.push_back(aiCard);
                                    aiHand.push_back(aiWar2);
                                    aiHand.push_back(aiWar1);
                                    cout << "Ai won, " << aiHand.size() << " cards in hand." << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if(p == 52 || a == 52){ //if a player has won
                    break;
                }
            }
            if(playerHand.size() == 52){ //player one wins
                playerScore++;
                cout << "You win! press 0 to exit, or 1 to play again" << endl;
                double prevScore = playerList[0] -> getHighscore("War");
                if(prevScore < playerScore){
                    playerList[0] -> setHighscore("War",playerScore);
                }
                cin >> playagain;
            }
            else{ //ai wins
                cout << "AI won! press 0 to exit, or 1 to play again" << endl;
                cin >> playagain;
            }
        }
    }
    //same code except for newly commented parts
    else if(listSize == 2){
        int playagain = 1;
        while(playagain != 0){
            vector<card*> playerHand = playerList[0] -> getCurrentHand();
            vector <card*> player2Hand = playerList[1] -> getCurrentHand();
            playerHand.clear();
            player2Hand.clear();
            playingDeck -> shuffle();
            int size = playingDeck ->getDeckSize();
            for(int i = 0; i < size/2; i++){
                playerHand.push_back(playingDeck -> draw());
                player2Hand.push_back(playingDeck -> draw());
            }
            delete playingDeck;
            playingDeck = new deck();
            card *playerCard,*player2Card,*player2War1,*player2War2,*playerWar1,*playerWar2;
            int player1userinput = 1;
            int player2userinput = 1;
            while(player1userinput != 0 && player2userinput != 0){
                playerList[0] -> setCurrentHand(playerHand);
                playerHand = playerList[0] -> getCurrentHand();
                playerList[1] -> setCurrentHand(player2Hand);
                player2Hand = playerList[1] -> getCurrentHand();
                int p = playerHand.size();
                int p2 = player2Hand.size();
                if(p != 52 && p2 != 52){
                    cout << "Player 1, Enter 1 to draw a card 0 to quit" << endl;
                    cin >> player1userinput;
                    cout << "Player 2, Enter 1 to draw a card 0 to quit" << endl; //get second user input.
                    cin >> player2userinput;
                    if(player1userinput == 1 && player2userinput == 1){
                        playerCard = playerHand.front();
                        playerHand.erase(playerHand.begin());
                        player2Card = player2Hand.front();
                        player2Hand.erase(player2Hand.begin());
                        cout << "Player drew the " << playerCard ->getValueName() << " of " << playerCard ->getSuitName() << "s" << endl;
                        cout << "Player 2 drew the " << player2Card ->getValueName() << " of " << player2Card ->getSuitName() << "s" << endl; 
                        if(playerCard -> getValue() > player2Card -> getValue()){
                            playerHand.push_back(playerCard);
                            playerHand.push_back(player2Card);
                            cout << "Player 1 won, " << playerHand.size() << " cards in hand." << endl;
                        }
                        else if(playerCard -> getValue() < player2Card -> getValue()){
                            player2Hand.push_back(playerCard);
                            player2Hand.push_back(player2Card);
                            cout << "Player 2 won, " << player2Hand.size() << " cards in hand." << endl;
                        }
                        else{
                            while(1){
                                playerWar1 = playerHand.front();
                                playerHand.erase(playerHand.begin());
                                playerWar2 = playerHand.front();
                                playerHand.erase(playerHand.begin());
                                player2War1 = player2Hand.front();
                                player2Hand.erase(player2Hand.begin());
                                player2War2 = player2Hand.front();
                                player2Hand.erase(player2Hand.begin());
                                cout << "Player 1 drew the " << playerWar2 ->getValueName() << " of " << playerWar2 ->getSuitName() << "s" << endl;
                                cout << "Player 2 drew the " << player2War2 ->getValueName() << " of " << player2War2 ->getSuitName() << "s" << endl; 
                                if(player2War2 -> getValue() < playerWar2 -> getValue()){
                                    playerHand.push_back(playerCard);
                                    playerHand.push_back(playerWar1);
                                    playerHand.push_back(playerWar2);
                                    player2Hand.push_back(player2Card);
                                    player2Hand.push_back(player2War2);
                                    player2Hand.push_back(player2War1);
                                    cout << "Player 1 won, " << playerHand.size() << " cards in hand." << endl;
                                    break;
                                }
                                else if(player2War2 -> getValue() > playerWar2 -> getValue()){
                                    playerHand.push_back(playerCard);
                                    playerHand.push_back(playerWar1);
                                    playerHand.push_back(playerWar2);
                                    player2Hand.push_back(player2Card);
                                    player2Hand.push_back(player2War2);
                                    player2Hand.push_back(player2War1);
                                    cout << "Player 2 won, " << player2Hand.size() << " cards in hand." << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if(p == 52 || p2 == 52){
                    break;
                }
            }
            if(playerHand.size() == 52 && player1userinput != 0){ //if player 1 won and did not quit
                player1Score++;
                cout << "Player 1 wins! press 0 to exit, or 1 to play again" << endl;
                double prevScore = playerList[0] -> getHighscore("War");
                if(prevScore < player1Score){
                    playerList[0] -> setHighscore("War",player1Score);
                }
                cin >> playagain;
            }
            else if(player2Hand.size() == 52 && player2userinput != 0){ // if player 2 won and did not quit
                player2score++;
                cout << "Player 2 wins! press 0 to exit, or 1 to play again" << endl;
                double prevScore = playerList[1] -> getHighscore("War");
                if(prevScore < player2score){
                    playerList[1] -> setHighscore("War",player2score);
                }
                cin >> playagain;
            }
            else if(player1userinput == 0 && player2userinput != 0){ // if player 1 quit
                player2score++;
                cout << "Player 2 wins! press 0 to exit, or 1 to play again" << endl;
                cout << player2score << endl;
                double prevScore = playerList[1] -> getHighscore("War");
                if(prevScore < player2score){
                    playerList[1] -> setHighscore("War",player2score);
                }
                cin >> playagain;
            }
            else if(player1userinput != 0 && player2userinput == 0){ // if player 2 quit
                player1Score++;
                cout << "Player 1 wins! press 0 to exit, or 1 to play again" << endl;
                cout << player1Score << endl;
                double prevScore = playerList[0] -> getHighscore("War");
                if(prevScore < player1Score){
                    playerList[0] -> setHighscore("War",player1Score);
                }
                cin >> playagain;
            }
            else{ //if both quit
                cout << "No winner! press 0 to exit, or 1 to play again" << endl;
                cin >> playagain;
            }
        }
    }
}