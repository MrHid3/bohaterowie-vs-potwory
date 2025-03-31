#ifndef HERO_H
#define HERO_H
#pragma once
#include <ranges>
#include <cmath>

#include "Character.h"
#include "Monster.h"

class Monster;

class Hero : Character {
private:
    std::string name;
    double maxHealth;
    double health;
    double strength;
    double armor;
    double agility;
    double level;
    double kills;

public:
    Hero() {
        srand(time(0));
        this->name = "Lorem von Ipsum";
        this->maxHealth = rand() % 10;
        this->health = maxHealth;
        this->strength = rand() % 10;
        this->armor = rand() % 10;
        this->agility = rand() % 10;
        this->level = 0;
    }

    Hero(std::string name, double max_health, double strength, double armor, double agility) {
        this->name = name;
        this->maxHealth = max_health;
        this->health = max_health;
        this->strength = strength;
        this->armor = armor;
        this->agility = agility;
        this->level = 0;
    }

    bool fight(Monster* two) {
        bool which = 0;
        while (this->isAlive() && two->isAlive()) {
            if (which)
                this->attack(*two);
            else
                this->monsterAttack(*two);
            which = !which;
        }
        return this->isAlive();
    }

    double getHealth() {
        return this->health;
    }

    void print() {
        std::cout << "Name: " + this->name + "\n";
        std::cout << "Health: " + std::to_string((int)this->health) + "\n";
        std::cout << "Strength: " + std::to_string((int)this->strength) + "\n";
        std::cout << "Armor: " + std::to_string((int)this->armor) + "\n";
        std::cout << "Agility: " + std::to_string((int)this->agility) + "\n";
        std::cout << "Level: " + std::to_string((int)this->level) + "\n";
    }

    bool isAlive() {
        return this->health > 0;
    }

    void attack(Monster target) {
        target.takeDamage(std::ceil(
                this->strength *
                (this->health >= std::ceil(this->maxHealth*0.75)? 1.2: 1)));
    }

    void monsterAttack(Monster attacker){
        this->takeDamage(std::ceil(
                attacker.getStrength() *
                ((attacker.getHealth() < attacker.getMaxHealth() / 2)? 1.2: 1)));
    }

    void takeDamage(double damage){
        srand(time(0));
        if (rand() % 15 > this->agility)
            this->health -= damage - armor;
    }

    void levelup(){
        this->level =+ 1;
        this->maxHealth = this->maxHealth + 1;
        this->health = std::floor(this->maxHealth * 0.75);
        this->strength = this->strength + 1;
        this->armor = this->armor + 1;
        this->agility = this->agility + 1;
    }
};
#endif //HERO_H
