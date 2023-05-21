#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    private:
        static constexpr int DEFAULT_SPPED = 8; 
        static constexpr int DEFAULT_DAMAGE = 150;
    public:
        OldNinja(const std::string &name, const Point &location);

        std::string print() const;
    };
}

#endif
