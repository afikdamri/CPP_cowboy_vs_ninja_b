#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const std::string &name, const Point &location)
        : Character(name, location, DEFAULT_LIVE), bullets_(DEFAULT_BULLETS) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
            throw std::runtime_error("Cannot shoot oneself. (Cowboy::shoot)");

        if (!isAlive())
            throw std::runtime_error("Cannot attack with a dead character. (Cowboy::shoot)");

        if (enemy->isAlive())
        {
            if (bullets_ > 0)
            {
                enemy->hit(10);
                bullets_--;
            }
        }
        else
        {
           throw std::runtime_error("Cannot attack a dead enemy. (Cowboy::shoot)");
        }
    }

    bool Cowboy::hasboolets() const
    {
        return bullets_ > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw std::runtime_error("Cannot reload with a dead character");
        }
        bullets_ = 6;
    }

    std::string Cowboy::print() const
    {
        std::string info = "Character: C (Cowboy), Name: " + getName() + ", Hit Points: " + std::to_string(getHitPoints()) + ", Location: ";
        info = info + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return info;
    }
}