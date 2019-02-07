all: menu

menu: 
	g++ -o menu ./BaseCard/Card.cpp ./BaseCard/Card.h ./BaseCard/Deck.h ./BaseCard/Deck.cpp ./BaseCard/cardGame.cpp ./BaseCard/cardGame.h ./BaseCard/cardGameFactory.cpp ./BaseCard/cardGameFactory.h ./BaseDice/dice.cpp ./BaseDice/dice.h ./BaseDice/diceGame.cpp ./BaseDice/diceGame.h ./BaseDice/diceFactory.cpp ./BaseDice/diceFactory.h ./BaseMenu/Menu.cpp ./BaseMenu/Menu.h ./BasePlayer/Player.cpp ./BasePlayer/Player.h ./LeaderBoard/LeaderBoard.cpp ./LeaderBoard/LeaderBoard.h ./Pig/pig.cpp ./Pig/pig.h ./War/War.cpp ./War/War.h
clean:
	rm -f menu