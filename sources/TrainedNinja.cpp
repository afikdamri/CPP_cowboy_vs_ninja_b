#include "TrainedNinja.hpp"

namespace ariel
{
    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
            :Ninja(name, DEFAULT_DAMAGE,location, DEFAULT_SPPED){};

    std::string TrainedNinja::print() const
    {
        std::string info = "Character: N (Trained Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(getHitPoints()) + ", Location: ";
        info = info + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return info;
    }
}