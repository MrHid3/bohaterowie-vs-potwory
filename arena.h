#ifndef ARENA_H
#define ARENA_H
#include <vector>
#include "Character.h"
#include "Hero.h"
#include "Monster.h"


class Arena {
    public:
    std::vector<Monster*> fighters;
    // struct results {
        // std::vector<std::vector<Character*>> matches;
        // std::vector<Character*> winner;
        // std::vector<int> winnerHp;
    // };
    // results results;
    Hero* hero;


    Arena(std::vector<Monster*> fighters, Hero* hero) {
        this->fighters = fighters;
        this->hero = hero;
        // results;
    }

    bool doZeThing() {
        bool win = true;
        while (win && !this->fighters.empty()) {
            // this->results.matches.push_back({fighters[fighters.size() - 1], this->hero});
            // Character* winner = Character::fight(fighters[fighters.size() - 1], this->hero);
            win = this->hero->fight(fighters[fighters.size() - 1]);
            if (win) {
                std::cout << "your hero won with " << fighters[fighters.size() - 1]->getName() << "\n";
                fighters.pop_back();
            }else{
                std::cout << "your hero lost with " << fighters[fighters.size() - 1]->getName() << "\n";
                return 0;
            }
            // this->results.winner.push_back(winner);
            // this->results.winnerHp.push_back(winner->getHealth());
        }
        return 1;
    }
};

#endif //ARENA_H
