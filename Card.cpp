//
// Created by User on 04/05/2022.
//
#include "Card.h"
#include "Player.h"
#include <iostream>
#include "utilities.h"
//
Card::Card(CardType type, const CardStats& stats){
    this->m_effect=type;
    this->m_stats=stats;
}

void Card::applyEncounter(Player& player) const{

    CardStats currentStats=this->m_stats;

    //case Battle card
    if(this->m_effect==CardType::Battle){
        if(getAttackStrength(player)<currentStats.force){
            std::cout << "Ouch the player loses";
            player.damage(currentStats.hpLossOnDefeat);
        }
        else{
            std::cout << "The player defeated the monster and won the loot! Hooray !";
            player.addCoins(currentStats.loot);
            player.levelUp();
        }
        return;
    }

    //case Heal card
    if(this->m_effect==CardType::Heal){
        if(player.pay(currentStats.cost)){
            player.heal(currentStats.heal);
        }
        return;
    }

    //case Buff card
    if(this->m_effect==CardType::Buff){
        if(player.pay(currentStats.cost)){
            player.heal(currentStats.buff);
        }
        return;
    }

    //case Treasure card
    if(this->m_effect==CardType::Treasure){
        player.addCoins(currentStats.loot);
    }
    return;
}

void Card::printInfo() const{
    if(this->m_effect==CardType::Battle){
        printBattleCardInfo(this);
        return;
    }
    else{
        if(this->m_effect==CardType::Buff){
            printBuffCardInfo(this);
            return;
        }
        else{
            if(this->m_effect==CardType::Heal){
                printHealCardInfo(this);
                return;
            }
            else{
                printTreasureCardInfo(this);
                return;
            }
        }
    }
}


