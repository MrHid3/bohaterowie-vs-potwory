#include <iostream>
#include <vector>

#include "arena.h"
#include "Character.h"

#include "Hero.h"
#include "Monster.h"

bool isIn(std::string skib, std::string idi){
    if (idi.length() != 1) return false;
    for (int i = 0; i < skib.length(); i++)
        if (tolower(skib[i]) == tolower(idi[0]))
            return true;
    return false;
}

int main() {
    srand(time(0));
    bool restart = true;
    std::string input;
    while (restart){
        std::cout << "Create your hero" << "\n";
        std::cout << "1. Manually" << "\n";
        std::cout << "2. Randomly" << "\n";
        std::cin >> input;
        if (isIn("12", input))
            restart = false;
    }
    restart = true;
    int maxHealth, strength, armor, agility;
    std::string name;
    Hero hero;
    if (input == "1"){
        while (restart){
            std::cout << "Max health (0-9): ";
            std::cin >> input;
            if (isIn("1234567890", input)){
                maxHealth = stoi(input);
                restart = false;
            }
        }
        restart = true;
        while (restart){
            std::cout << "Strength (0-9): ";
            std::cin >> input;
            if (isIn("1234567890", input)){
                strength = stoi(input);
                restart = false;
            }
        }
        restart = true;
        while (restart){
            std::cout << "Armor (0-9): ";
            std::cin >> input;
            if (isIn("1234567890", input)){
                armor = stoi(input);
                restart = false;
            }
        }
        restart = true;
        while (restart){
            std::cout << "Agility (0-9): ";
            std::cin >> input;
            if (isIn("1234567890", input)){
                agility = stoi(input);
                restart = false;
            }
        }
        restart = true;
        std::cout << "Name: ";
        std::cin >> name;
        hero = Hero(name, maxHealth, strength, armor, agility);
    }else{
        hero = Hero();
    }
    hero.print();
    std::vector<Monster*> monsters = {new Monster("Werewolf"), new Monster("Minotaur"), new Monster("Vampyre"), new Monster("Hydra")};
    Arena arena = Arena(monsters, &hero);
    bool result = arena.doZeThing();
    if (result)
        std::cout << "Your hero wins!\n";
    else
        std::cout << "Your hero loses!\n";
    return 0;
}