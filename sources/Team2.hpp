#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    private:
        static const int MAX_FIGHTERS = 10;
        std::vector<Character*> fighters_;
        Character *leader_;

    public:
        Team2() : leader_(nullptr){};
        Team2(Character *leader);
        
        std::vector<Character*> &getFighters();
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;

        void cowboysAttack(Character * fighter,Character *victim);
        void ninjasAttack(Character * fighter,Character *victim);

        Character *findCharacter(const Character *character, const std::vector<Character*> &characters) const;
        void chooseNewLeader();


        ~Team2();
        Team2(const Team2&) = delete; // Delete copy constructor
        Team2& operator=(const Team2&) = delete; // Delete copy assignment operator
        Team2(Team2&&) = delete; // Delete move constructor
        Team2& operator=(Team2&&) = delete; // Delete move assignment operator
    };
}

#endif
