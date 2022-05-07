//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    void playNextCard();

    bool isOver();

    GameStatus getGameStatus() const;


private:
    int m_cardsIndex;
    Card* m_cardsArray;
    int m_cardsNumber;
    GameStatus m_gameStatus;
    Player m_ourPlayer;
};


#endif //EX2_GAME_H
