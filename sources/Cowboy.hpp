#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets_;
        static constexpr int DEFAULT_BULLETS = 6;
        static constexpr int DEFAULT_LIVE = 110;
    public:
        Cowboy(const std::string &name, const Point &location);
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() const;
    };
}

#endif
