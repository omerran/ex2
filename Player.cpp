//
// Created by itayk on 04/05/2022.
//
#include "Player.h"

Player::Player(char* name, int maxHP = 100, int force = 5){

    if(maxHP < 0){
        maxHP = 100;
    }
    if(force < 0){
        force = 5;
    }

    m_name = name;
    m_level = 1;
    m_force = force;
    m_maxHP = maxHP;
    HP =  maxHP;
    m_coins = 0;
}

Player::levelUP(){
    if (m_level >= 10){
        return
    }
    m_level += 1;
}

Player::getLevel(){
    return m_level;
}

Player::buff(int force){
    if(force < 0){
        force = 0;
    }

    m_force += force;
}

Player::heal(int HP){
    if(HP < 0){
        HP = 0;
    }

    if(m_HP + HP > m_maxHP) {
        return;
    }
    m_HP += HP;
}

Player::damage(int HP){
    if(HP < 0){
        HP = 0;
    }

    if(m_HP - HP <= 0) {
        m_HP = 0;
        return;
    }
    m_HP -= HP;
}

Player::isKnockedOut(){
    if(m_HP == 0) {
        return true;
    }
    return false;
}

Player::addCoins(int coins){
    if(coins < 0){
        coins = 0;
    }

    m_coins += coins;
}

// אם זה שלילי יש דפקה (כי מוציא TRUE) - לא ברור למה התכוונו
Player::pay(int coins){
    if(coins < 0){
        coins = 0;
    }

    if (m_coins - coins < 0){
        return false;
    }
    m_coins -= coins;
    return true;
}

Player::getAttackStrength(){
    return m_level + m_force;
}

Player::printPlayerInfo(const char* name, int level, int force, int hp, int coins){
    std::cout << "Player Details : " << "\n";
    std::cout << "Name: " << m_name << "\n";
    std::cout << "Level: " << m_level << "\n";
    std::cout << "Force: " << m_force << "\n";
    std::cout << "HP: " << m_HP << "\n";
    std::cout << "Coins: " << m_coins << "\n";
    std::cout << "------------------------";

}