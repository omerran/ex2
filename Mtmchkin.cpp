//
// Created by itayk on 04/05/2022.
//
#include "Mtmchkin.h"

Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) {
    this->m_gameStatus = midGame;
    this->m_cardNumber = numOfCards;
    this->m_cardsArray = calloc(numOfCards, sizeof(card));
    for (int i = 0; i < numOfCards; ++i) {
        m_cardsArray[i] = cardsArray[i];
    }
    this->m_playerName = calloc(strlen(playerName) + 1, sizeof(char));
    strcpy(m_playerName, playerName);
}

bool isOver(){

}

GameStatus getGameStatus() const{
    return m_gameStatus;
}


void playNextCard(){
    Card currentCard = m_cardsArray[cardsIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(this*);
    Player.printInfo();
    if (m_cardsIndex < m_cardsNumber-1){
        m_cardsIndex++;
    }
    else{
        m_cardsIndex = 0;
    }
}
