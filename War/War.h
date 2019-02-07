#ifndef WAR_H
#define WAR_H

#include "../BaseCard/cardGame.h"
#include "../BaseCard/cardGameFactory.h"
/**
 * @brief War class contains all game logic for the card game war
 * @details War class contains all game logic for the card game war, uses base card game class as a template
 * @author Jacob Ross 250892852 
 **/
class War : public cardGame{
    public:
        War(std::vector<Player*> players);
        ~War();
        void play();
    private:
        deck *playingDeck;
        std::vector<Player*> playerList;
};

#endif