//
// Created by itayk on 04/05/2022.
//
#include "Player.h"
#include <iostream>



Player::Player(const char* name, int maxHP, int force){

    this->m_name = name;
    this->m_level = 1;
    this->m_force = force;
    this->m_maxHP = maxHP;
    this->m_HP =  maxHP;
    this->m_coins = 0;

    if(maxHP < 0){
        this->m_maxHP =  DEFAULT_MAX_HP;
    }
    if(force < 0){
        this->m_force = DEFAULT_FORCE;
    }


}

void Player::levelUp(){
    if (m_level >= 10){
        return;
    }
    m_level += 1;
}

int Player::getLevel(){
    return m_level;
}

void Player::buff(int force){
    if(force < 0){
        force = 0;
    }

    m_force += force;
}

void Player::heal(int HP){
    if(HP < 0){
        HP = 0;
    }

    if(m_HP + HP > m_maxHP) {
        return;
    }
    m_HP += HP;
}

int Player::damage(int HP){
    if(HP < 0){
        HP = 0;
    }

    if(m_HP - HP <= 0) {
        m_HP = 0;
        return m_HP;
    }
    m_HP -= HP;
    return m_HP;
}

bool Player::isKnockedOut(){
    if(m_HP == 0) {
        return true;
    }
    return false;
}

void Player::addCoins(int coins){
    if(coins < 0){
        coins = 0;
    }

    m_coins += coins;
}

// אם זה שלילי יש דפקה (כי מוציא TRUE) - לא ברור למה התכוונו
bool Player::pay(int coins){
    if(coins < 0){
        coins = 0;
    }

    if (m_coins - coins < 0){
        return false;
    }
    m_coins -= coins;
    return true;
}

int Player::getAttackStrength(){
    return m_level + m_force;
}

void Player::printInfo(){
    std::cout << "Player Details:" << "\n";
    std::cout << "Name: " << m_name << "\n";
    std::cout << "Level: " << m_level << "\n";
    std::cout << "Force: " << m_force << "\n";
    std::cout << "HP: " << m_HP << "\n";
    std::cout << "Coins: " << m_coins << "\n";
    std::cout << "------------------------\n";
}