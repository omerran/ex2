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
    Mtmchkin::isOver(){
        if (this->m_level == 10){
            GameStatus = Win;
            return true;
        }
        if(this->m_HP = 0){
            GameStatus = Loss;
            return true;
        }
        return false;
    }
}

GameStatus getGameStatus() const{
    return this->m_gameStatus;
}


void playNextCard(){
    Card currentCard = this->m_cardsArray[this->cardsIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(this*);
    Player.printInfo();
    if (this->m_cardsIndex < this->m_cardsNumber-1){
        this->m_cardsIndex++;
    }
    else{
        this->m_cardsIndex = 0;
    }
}
