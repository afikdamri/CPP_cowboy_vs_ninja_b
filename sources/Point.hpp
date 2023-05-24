namespace ariel
{
    class Point
    {
    private:
        double posX_;
        double posY_;

    public:
        Point(double posX, double posY);

        double distance(const Point &point) const;
        double getX() const;
        double getY() const;
        void print() const;
        static Point moveTowards(const Point &point1, const Point &point2, double maxDistanceDelta);
    };
}
