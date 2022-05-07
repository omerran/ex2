//
// Created by itayk on 04/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <stdbool.h>
#include <std::cout>

class Player {

    char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:

    Player(char* name, int maxHP = 100, int force = 5);
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    void levelUp();
    int getLevel();
    void buff(int force);
    void heal(int HP);
    void damage(int HP);
    bool isKnockedOut();
    void addCoins(int coins);
    bool pay(int coins);
    int getAttackStrength();

    void printInfo();

}

#endif //EX2_PLAYER_H
