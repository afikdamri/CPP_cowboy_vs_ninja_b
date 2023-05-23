#include "Team.hpp"
#include <stdexcept>
#include <limits>
using namespace std;

namespace ariel
{
    Team::Team(Character *leader) : leader_(leader)
    {
        if (leader->isInTeam())
            throw runtime_error("Character is already in a team. (Team::Team)");

        fighters_.push_back(leader);
        leader->setInTeam();
        leader_ = leader;
    }

    void Team::add(Character *fighter)
    {
        if (!fighter->isAlive())
            throw runtime_error("dead Character. (Team::add)");

        if (fighter->isInTeam())
            throw runtime_error("Character is already in a team. (Team::add)");

        if (fighters_.size() >= MAX_FIGHTERS)
            throw runtime_error("Team is already at maximum capacity. (Team::add)");

        for (Character *existingFighter : fighters_)
        {
            if (existingFighter == fighter)
                throw runtime_error("Character is already in the team. (Team::add)");
        }

        fighter->setInTeam();
        fighters_.push_back(fighter);
    }

    int Team::stillAlive() const
    {
        int count = 0;
        for (Character *liveingFighter : fighters_)
        {
            if (liveingFighter->isAlive())
                count++;
            if (!liveingFighter->isInTeam())
                liveingFighter->setInTeam();
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

    void Team::chooseNewLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = numeric_limits<double>::max();

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
        if (newLeader == nullptr)
            cout << "All the team die. (Team::chooseNewLeader)" << endl;
        leader_ = newLeader;
    }

    Character *Team::findCharacter(const Character *enemyLeader, const vector<Character *> &characters) const
    {
        double minDistance = numeric_limits<double>::max();
        Character *closestCharacter = nullptr;

        for (Character *enemy : characters)
        {
            if (enemy->isAlive() && enemy != enemyLeader) // Exclude the current character from consideration
            {
                double distance = enemyLeader->getLocation().distance(enemy->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = enemy;
                }
            }
        }
        return closestCharacter;
    }

    std::vector<Character*> &Team::getFighters()
    {
        return this->fighters_;
    }

    void Team::cowboysAttack(Character * fighter,Character *victim)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy*>(fighter);
        if (!cowboy->isAlive() || !victim->isAlive())
            return;

        if (cowboy->hasboolets())
            cowboy->shoot(victim);

        else
            cowboy->reload();
    }


    void Team::ninjasAttack(Character *fighter, Character *victim)
    {
        Ninja *ninja = dynamic_cast<Ninja*>(fighter);
        double distance = ninja->getLocation().distance(victim->getLocation());
        if (!ninja->isAlive() || !victim->isAlive())
            return;

        if (distance <= 1.0)
            ninja->slash(victim);

        else
            ninja->move(victim);
    }

    void Team::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
            throw invalid_argument("null enemyTeam pointer. (Team::attack)");

        if (stillAlive() == 0)
            return;

        if (enemyTeam->stillAlive() == 0)
            //throw runtime_error("enemyTeam id dead. (Team::attack)");
            return;

        if (!leader_->isAlive())
            chooseNewLeader();

        Character *victim = findCharacter(leader_, enemyTeam->getFighters());
        if (victim != nullptr && victim->isAlive())
        {
            for (Character *fighter : fighters_)
            {
                if (fighter->getType() == 'c')
                    cowboysAttack(fighter, victim);

                if (fighter->getType() == 'n')
                    ninjasAttack(fighter, victim);

                if (fighter->getType() == 'u')
                    break;                       
            }
        }
    }
}