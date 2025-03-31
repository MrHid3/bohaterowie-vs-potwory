#ifndef MONSTER_H
#define MONSTER_H
#pragma once
#include "Character.h"
#include <cmath>

class Monster : Character {
private:
    std::string name;
    double maxHealth = 1;
    double health;
    double strength;
    double armor;
    double agility;
    double level;
    double kills;
public:
    Monster() {
        srand(time(0));
        this->name = "Loremus Ipsumus";
        this->maxHealth = rand() % 10;
        this->health = maxHealth;
        this->strength = rand() % 10;
        this->armor = rand() % 10;
        this->agility = rand() % 10;
        this->level = 0;
    }

    Monster(std::string name) {
        srand(time(0));
        this->name = name;
        this->maxHealth = rand() % 10;
        this->health = maxHealth;
        this->strength = rand() % 10;
        this->armor = rand() % 10;
        this->agility = rand() % 10;
        this->level = 0;
    }

    Monster(std::string name, double health, double strength, double armor, double agility, double level) {
        this->name = name;
        this->health = health;
        this->strength = strength;
        this->armor = armor;
        this->agility = agility;
        this->level = level;
    }

    double getHealth() {
        return this->health;
    }

    double getStrength(){
        return this->strength;
    }

    double getMaxHealth(){
        return this->maxHealth;
    }

    std::string getName(){
        return this->name;
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

    void takeDamage(double damage){
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

#endif //MONSTER_H
