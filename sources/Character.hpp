#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

namespace ariel
{
    class Character
    {
    private:
        std::string name_;
        int hitPoints_;
        Point location_;
        int inTeam_;

    public:
        Character(const std::string &name, const Point &location, int hitPoints);

        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int amount);
        std::string getName() const;
        Point getLocation() const;
        void setLocation(const Point &newLocation);
        int getHitPoints() const;
        void print() const;
        int isInTeam() const;
        void setInTeam();
        char getType() const;

        virtual ~Character() {}
        Character(const Character &) = delete;            // Delete copy constructor
        Character &operator=(const Character &) = delete; // Delete copy assignment operator
        Character(Character &&) = delete;                 // Delete move constructor
        Character &operator=(Character &&) = delete;      // Delete move assignment operator
    };
}
#endif
