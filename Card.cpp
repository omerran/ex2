//
// Created by User on 04/05/2022.
//
#include "Card.h"
#include "Player.h"
#include <iostream>
#include "utilities.h"
using std::cout;
using std::endl;
//
Card::Card(CardType type, const CardStats& stats){
    this->m_effect=type;
    this->m_stats=stats;
}

void Card::applyEncounter(Player& player) const{

    CardStats currentStats=this->m_stats;

    //case Battle card
    if(this->m_effect==CardType::Battle){
        if(player.getAttackStrength()<currentStats.force){
            std::cout << "Ouch the player loses" << endl;
            std::cout << "------------------------\n";
            player.damage(currentStats.hpLossOnDefeat);
        }
        else{
            std::cout << "The player defeated the monster and won the loot! Hooray !" << endl;
            std::cout << "------------------------\n";
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
            player.buff(currentStats.buff);
        }
        return;
    }

    //case Treasure card
    if(this->m_effect==CardType::Treasure){
        player.addCoins(currentStats.loot);
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


