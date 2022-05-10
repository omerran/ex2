//
// Created by itayk on 04/05/2022.
//
#include "Mtmchkin.h"
#include <string>

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards): m_ourPlayer(playerName) {
    this->m_cardsNumber = numOfCards;
    this->m_cardsIndex = 0;
    Card* tempArray = new Card[numOfCards]();
    for (int i = 0; i < numOfCards; ++i) {
        tempArray[i]=cardsArray[i];
    }
    this->m_cardsArray = tempArray;
    this->m_gameStatus = GameStatus::MidGame;
}

bool Mtmchkin::isOver() const{
        if (this->m_gameStatus == GameStatus::Win || this->m_gameStatus == GameStatus::Loss){
            return true;
        }
        return false;
}


GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}

void Mtmchkin::playNextCard(){
    this->m_cardsArray[this->m_cardsIndex].printInfo();
    this->m_cardsArray[this->m_cardsIndex].applyEncounter(this->m_ourPlayer);
    m_ourPlayer.printInfo();
    if(this->m_ourPlayer.isKnockedOut()){
        this->m_gameStatus=GameStatus::Loss;
        return;
    }
    if(this->m_ourPlayer.getLevel()==10){
        this->m_gameStatus=GameStatus::Win;
        return;
    }
    if (this->m_cardsIndex < this->m_cardsNumber-1){
        this->m_cardsIndex++;
    }
    else{
        this->m_cardsIndex = 0;
    }
}

Mtmchkin::~Mtmchkin(){
    delete[] this->m_cardsArray;
}

