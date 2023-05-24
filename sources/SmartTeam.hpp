#ifndef SmartTeam_HPP
#define SmartTeam_HPP

#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"

namespace ariel
{
    class SmartTeam 
    {
    private:
        static const int MAX_FIGHTERS = 10;
        std::vector<Character*> fighters_;
        Character *leader_;

        Character *findCharacter(const Character *character, const std::vector<Character*> &characters) const;
        void chooseNewLeader();

    public:
        SmartTeam(Character *leader);

        void add(Character *fighter);
        virtual void attack(SmartTeam *enemySmartTeam);
        void print() const;
        int stillAlive() const;

        ~SmartTeam();
        SmartTeam(const SmartTeam&) = delete; // Delete copy constructor
        SmartTeam& operator=(const SmartTeam&) = delete; // Delete copy assignment operator
        SmartTeam(SmartTeam&&) = delete; // Delete move constructor
        SmartTeam& operator=(SmartTeam&&) = delete; // Delete move assignment operator
    };
}

#endif
