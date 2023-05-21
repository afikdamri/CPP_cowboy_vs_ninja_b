#include "YoungNinja.hpp"
using namespace std;
namespace ariel
{
    YoungNinja::YoungNinja(const std::string &name, const Point &location)
            : Ninja(name, DEFAULT_DAMAGE, location, DEFAULT_SPPED){};

    std::string YoungNinja::print() const
    {
        std::string info = "Character: N (Young Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(getHitPoints()) + ", Location: ";
        info = info + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return info;
    }
}