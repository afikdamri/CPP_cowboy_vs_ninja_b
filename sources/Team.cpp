#include "Team.hpp"
#include <stdexcept>
#include <limits>

namespace ariel
{
    Character *Team::findCharacter(const Character *character, const std::vector<Character *> &characters) const
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

    void Team::chooseNewLeader()
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

    Team::Team(Character *leader) : leader_(leader)
    {
        for (Character *teamFighter : fighters_)
        {
            if (teamFighter == leader)
            {
                throw std::runtime_error("Character is already in a team.");
            }
        }

        fighters_.push_back(leader);
    }

    void Team::add(Character *fighter)
    {
        if (fighter->isInTeam())
        {
            throw std::runtime_error("Character is already in a team.");
        }

        if (fighters_.size() >= MAX_FIGHTERS)
        {
            throw std::runtime_error("Team is already at maximum capacity.");
        }

        fighter->setInTeam(); // Set the flag indicating the character is in a team
        fighters_.push_back(fighter);
    }

    void Team::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            throw std::invalid_argument("null enemyTeam pointer!");
        }
        if (stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            return; // End the attack if there are no living members in either group
        }

        if (!leader_->isAlive())
        {
            chooseNewLeader();
        }

        Character *victim = findCharacter(leader_, enemyTeam->fighters_);
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

                    // Update hitPoints_ of victim and handle death
                    int prevHitPoints = victim->getHitPoints();
                    fighter->hit(10); // Adjust the amount as needed

                    if (prevHitPoints > 0 && victim->getHitPoints() <= 0)
                    {
                        victim->hit(0); // Set hitPoints_ to 0 if the victim died
                    }
                }
            }

            if (!victim->isAlive())
            {
                victim = findCharacter(leader_, enemyTeam->fighters_);
            }
            else
            {
                break;
            }
        }
    }

    int Team::stillAlive() const
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

    void Team::print() const
    {
        for (Character *fighter : fighters_)
        {
            fighter->print();
        }
    }

    Team::~Team()
    {
        for (Character *fighter : fighters_)
        {
            delete fighter;
        }
    }
}
