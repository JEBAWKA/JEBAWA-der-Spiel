#ifndef COORD_H
#define COORD_H

struct Coord // koordynaty hexa
{
    short x, y, z;
    Coord() {} // lepiej uzywac konstruktora przypisujacego od razu wartosci
    Coord(short x_, short y_, short z_) : x(x_), y(y_), z(z_) {}

    bool operator==(const Coord &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }
    Coord operator+(const Coord &other) const
    {
        return Coord(x + other.x, y + other.y, z + other.z);
    }
    Coord& operator+=(const Coord &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    Coord operator-(const Coord &other) const
    {
        return Coord(x - other.x, y - other.y, z - other.z);
    }
    Coord& operator-=(const Coord &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
};

#endif // COORD_H
