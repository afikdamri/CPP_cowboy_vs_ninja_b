#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    private:
        static constexpr int DEFAULT_SPPED = 12; 
        static constexpr int DEFAULT_DAMAGE = 120;
    public:
        TrainedNinja(const std::string &name, const Point &location);
        std::string print() const;
    };
}

#endif
