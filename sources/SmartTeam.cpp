#include "SmartTeam.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

namespace ariel
{
    Character *SmartTeam::findCharacter(const Character *character, const std::vector<Character *> &characters) const
    {
        double minDistance = std::numeric_limits<double>::max();
        Character *closestCharacter = nullptr;

        for (Character *enemy : characters)
        {
            if (enemy->isAlive())
            {
                double distance = character->getLocation().distance(enemy->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = enemy;
                }
            }
        }

        return closestCharacter;
    }

    void SmartTeam::chooseNewLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *fighter : fighters_)
        {
            if (fighter->isAlive())
            {
                double distance = leader_->getLocation().distance(fighter->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    newLeader = fighter;
                }
            }
        }

        leader_ = newLeader;
    }

    SmartTeam::SmartTeam(Character *leader) : leader_(leader)
    {
        fighters_.push_back(leader);
    }

    void SmartTeam::add(Character *fighter)
    {
        if (fighters_.size() < MAX_FIGHTERS)
        {
            fighters_.push_back(fighter);
        }
    }

    void SmartTeam::attack(SmartTeam *enemySmartTeam)
    {
        if (!leader_->isAlive())
        {
            chooseNewLeader();
        }

        Character *victim = findCharacter(leader_, enemySmartTeam->fighters_);
        while (victim)
        {
            for (Character *fighter : fighters_)
            {
                if (fighter->isAlive())
                {
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                    if (cowboy && cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else if (cowboy)
                    {
                        cowboy->reload();
                    }

                    Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                    if (ninja && ninja->getLocation().distance(victim->getLocation()) <= 1.0)
                    {
                        ninja->slash(victim);
                    }
                    else if (ninja)
                    {
                        ninja->move(victim);
                    }
                }
            }

            if (!victim->isAlive())
            {
                victim = findCharacter(leader_, enemySmartTeam->fighters_);
            }
            else
            {
                break;
            }
        }
    }

    int SmartTeam::stillAlive() const
    {
        int count = 0;
        for (Character *fighter : fighters_)
        {
            if (fighter->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void SmartTeam::print() const
    {
        for (Character *fighter : fighters_)
        {
            fighter->print();
        }
    }

    SmartTeam::~SmartTeam()
    {
        for (Character *fighter : fighters_)
        {
            delete fighter;
        }
    }
}
