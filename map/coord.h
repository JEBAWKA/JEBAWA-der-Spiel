#ifndef COORD_H
#define COORD_H

#include <array>

struct Coord // koordynaty hexa
{
    short x, y;
    Coord() {} // lepiej uzywac konstruktora przypisujacego od razu wartosci
    Coord(short x_, short y_) : x(x_), y(y_) {}

    bool operator==(const Coord &other) const
    {
        return (x == other.x && y == other.y);
    }
    Coord operator+(const Coord &other) const
    {
        return Coord(x + other.x, y + other.y);
    }
    Coord& operator+=(const Coord &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Coord operator-(const Coord &other) const
    {
        return Coord(x - other.x, y - other.y);
    }
    Coord& operator-=(const Coord &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

#endif // COORD_H
