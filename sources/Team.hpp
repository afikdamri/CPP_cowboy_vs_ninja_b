#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "SmartTeam.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"

namespace ariel
{
    class Team
    {
    private:
        static const int MAX_FIGHTERS = 10;
        Character *leader_;
        std::vector<Character*> fighters_;
        
    public:
        Team() : leader_(nullptr){};
        Team(Character *leader);
        
        std::vector<Character*> &getFighters();
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;

        void cowboysAttack(Character *fighter,Character *victim);
        void ninjasAttack(Character *fighter,Character *victim);

        Character *findCharacter(const Character *character, const std::vector<Character*> &characters) const;
        void chooseNewLeader();

        ~Team();
        Team(const Team&) = delete; // Delete copy constructor
        Team& operator=(const Team&) = delete; // Delete copy assignment operator
        Team(Team&&) = delete; // Delete move constructor
        Team& operator=(Team&&) = delete; // Delete move assignment operator
    };
}

#endif
