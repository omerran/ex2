//
// Created by itayk on 04/05/2022.
//
#include "Mtmchkin.h"
#include <string>

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    this->m_gameStatus =  GameStatus::MidGame;
    this->m_cardsNumber = numOfCards;
    this->m_cardsArray = calloc(numOfCards, sizeof(Card));
    for (int i = 0; i < numOfCards; ++i) {
        m_cardsArray[i] = cardsArray[i];
    }
    this->m_playerName = playerName;
    m_ourPlayer = Player(m_playerName);
}

bool Mtmchkin::isOver(){
    Player ourPlayer= m_ourPlayer;
        if (ourPlayer.getLevel() == 10){
            this->m_gameStatus =  GameStatus::Win;
            return true;
        }
        if(this->m_HP == 0){
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
