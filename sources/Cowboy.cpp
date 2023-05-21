#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const std::string &name, const Point &location)
            : Character(name, location, DEFAULT_LIVE), bullets_(DEFAULT_BULLETS){}

    void Cowboy::shoot(Character *enemy)
    {
        if (isAlive() && bullets_ > 0)
        {
            enemy->hit(10);
            bullets_--;
        }
    }

    bool Cowboy::hasboolets() const
    {
        return bullets_ > 0;
    }

    void Cowboy::reload()
    {
        bullets_ = 6;
    }

    std::string Cowboy::print() const
    {
        std::string info = "Character: C (Cowboy), Name: " + getName() + ", Hit Points: " + std::to_string(getHitPoints()) + ", Location: ";
        info = info + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return info;
    }
}