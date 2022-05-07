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
    //case Battle card
    if(this->m_effect==CardType::Battle){
        if(player.getAttackStrength()<this->m_stats.force){
            printBattleResult(false);
            player.damage(this->m_stats.hpLossOnDefeat);
        }
        else{
            printBattleResult(true);
            player.addCoins(this->m_stats.loot);
            player.levelUp();
        }
        return;
    }

    //case Heal card
    if(this->m_effect==CardType::Heal){
        if(player.pay(this->m_stats.cost)){
            player.heal(this->m_stats.heal);
        }
        return;
    }

    //case Buff card
    if(this->m_effect==CardType::Buff){
        if(player.pay(this->m_stats.cost)){
            player.buff(this->m_stats.buff);
        }
        return;
    }

    //case Treasure card
    if(this->m_effect==CardType::Treasure){
        player.addCoins(this->m_stats.loot);
    }
}

void Card::printInfo() const{
    if(this->m_effect==CardType::Battle){
        printBattleCardInfo(this->m_stats);
        return;
    }
    else{
        if(this->m_effect==CardType::Buff){
            printBuffCardInfo(this->m_stats);
            return;
        }
        else{
            if(this->m_effect==CardType::Heal){
                printHealCardInfo(this->m_stats);
                return;
            }
            else{
                printTreasureCardInfo(this->m_stats);
                return;
            }
        }
    }
}


