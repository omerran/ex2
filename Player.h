//
// Created by itayk on 04/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5

class Player {

    const char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:

    Player(const char* name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    void levelUp();
    int getLevel() const;
    void buff(int force);
    void heal(int HP);
    int damage(int HP);
    bool isKnockedOut() const;
    void addCoins(int coins);
    bool pay(int coins);
    int getAttackStrength() const;

    void printInfo() const;

};

#endif //EX2_PLAYER_H
