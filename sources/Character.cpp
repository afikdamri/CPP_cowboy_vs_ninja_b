#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    Character::Character(const string &name, const Point &location, int hitPoints)
        : name_(name), hitPoints_(hitPoints), location_(location) { inTeam_ = 0; }

    bool Character::isAlive() const
    {
        return hitPoints_ > 0;
    }

    double Character::distance(const Character *otherCharacter) const
    {
        return location_.distance(otherCharacter->getLocation());
    }

    std::string Character::getName() const
    {
        return name_;
    }

    void Character::setLocation(const Point &newLocation)
    {
        location_ = newLocation;
    }

    int Character::getHitPoints() const
    {
        return hitPoints_;
    }

    Point Character::getLocation() const
    {
        return location_;
    }

    void Character::print() const
    {
        std::cout << "Name: " << name_ << std::endl;
        if (isAlive())
        {
            std::cout << "Hit Points: " << hitPoints_ << std::endl;
            std::cout << "Location: (" << location_.getX() << ", " << location_.getY() << ")" << std::endl;
        }
        else
        {
            std::cout << "Character is dead." << std::endl;
            std::cout << "Location: (" << location_.getX() << ", " << location_.getY() << ")" << std::endl;
        }
    }

    void Character::hit(int amount)
    {
        if (amount < 0)
            throw std::invalid_argument("Negative hit amount is not allowed.");

        hitPoints_ -= amount;
        // cout << amount <<endl;
        // cout<< hitPoints_<<endl;
        if (hitPoints_ < 0)
        {
            hitPoints_ = 0;
        }
    }

    int Character::isInTeam() const
    {
        return inTeam_;
    }

    void Character::setInTeam()
    {
        inTeam_ = 1;
    }

    char Character::getType() const
    {
        if (dynamic_cast<const Cowboy*>(this))
        {
            return 'c'; // Cowboy
        }
        else if (dynamic_cast<const Ninja*>(this))
        {
            return 'n'; // Ninja
        }
        else
        {
            return 'u'; // Unknown
        }
    }

}