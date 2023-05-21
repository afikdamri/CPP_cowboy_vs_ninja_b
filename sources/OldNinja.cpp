#include "OldNinja.hpp"
#include "Character.hpp"

namespace ariel
{
    OldNinja::OldNinja(const std::string &name, const Point &location)
            : Ninja(name, DEFAULT_DAMAGE, location, DEFAULT_SPPED){}


    std::string OldNinja::print() const
    {
        std::string info = "Character: N (Old Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(getHitPoints()) + ", Location: ";
        info = info + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return info;
    }
}
