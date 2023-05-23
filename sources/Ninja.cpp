#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const std::string &name, int hitPoints, const Point &location, int speed)
        : Character(name, location, hitPoints), speed_(speed) {}

    void Ninja::move(const Character *enemy)
    {
        double distance = getLocation().distance(enemy->getLocation());
        if (distance > speed_)
        {
            double ratio = speed_ / distance;
            double dx = enemy->getLocation().getX() - getLocation().getX();
            double dy = enemy->getLocation().getY() - getLocation().getY();
            double newX = getLocation().getX() + dx * ratio;
            double newY = getLocation().getY() + dy * ratio;
            setLocation(Point(newX, newY));
        }
        else{
            setLocation(Point(enemy->getLocation()));

        }
    }

    void Ninja::slash(Character *enemy)
    {
        if (enemy == this)
            throw std::runtime_error("Cannot attack oneself. (Ninja::slash)");

        else if (!isAlive())
            throw std::runtime_error("Cannot attack with a dead character. (Ninja::slash)");

        else if (enemy->isAlive())
        {
            double distance = getLocation().distance(enemy->getLocation());
            if (distance < 1.0)
                enemy->hit(40);

        }
        else
            return;

    }

}
