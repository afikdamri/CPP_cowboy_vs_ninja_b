#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{

    Point::Point(double posX, double posY) : posX_(posX), posY_(posY) {}

    double Point::getX() const { return posX_; }

    double Point::getY() const { return posY_; }

    double Point::distance(const Point &point) const
    {
        double distance = pow(posX_ - point.posX_, 2) + pow(posY_ - point.posY_ , 2);
        //std::cout << distance << "========" <<endl;
        distance = sqrt(distance);
        return distance;
    }

    void Point::print() const
    {
        cout << "(" << posX_ << "," << posY_ << ")" << endl;
    }

    Point Point::moveTowards(const Point &point1, const Point &point2, double distanceDelta)
    {
        if(distanceDelta < 0){
            throw std::invalid_argument("distance most be positiv number");
        }
        double deltaX = point2.posX_ - point1.posX_;
        double deltaY = point2.posY_ - point1.posY_;

        double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
        if (magnitude <= distanceDelta || magnitude == 0.0)
        {
            return point2;
        }

        double normalizedX = deltaX / magnitude;
        double normalizedY = deltaY / magnitude;

        double newX = point1.posX_ + normalizedX * distanceDelta;
        double newY = point1.posY_ + normalizedY * distanceDelta;

        return Point(newX, newY);
    }
}