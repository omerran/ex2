//
// Created by itayk on 04/05/2022.
//
#include "Mtmchkin.h"
#include <string>

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards): m_ourPlayer(playerName) {
    this->m_gameStatus =  GameStatus::MidGame;
    this->m_cardsNumber = numOfCards;
    this->m_cardsIndex = 0;
    this->m_cardsArray = new Card[numOfCards]();
    for (int i = 0; i < numOfCards; ++i) {
        this->m_cardsArray[i] = cardsArray[i];
    }
}

bool Mtmchkin::isOver(){
    Player ourPlayer= m_ourPlayer;
        if (ourPlayer.getLevel() == 10){
            this->m_gameStatus =  GameStatus::Win;
            return true;
        }
        if(ourPlayer.isKnockedOut()){
            this->m_gameStatus =  GameStatus::Loss;
            return true;
        }
        return false;
}


GameStatus Mtmchkin::getGameStatus() const{
    return this->m_gameStatus;
}


void Mtmchkin::playNextCard(){
    Card currentCard = this->m_cardsArray[this->m_cardsIndex];
    currentCard.printInfo();
    currentCard.applyEncounter(this->m_ourPlayer);
    m_ourPlayer.printInfo();
    if (this->m_cardsIndex < this->m_cardsNumber-1){
        this->m_cardsIndex++;
    }
    else{
        this->m_cardsIndex = 0;
    }
}
