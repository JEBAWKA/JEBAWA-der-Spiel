#ifndef COORD_H
#define COORD_H

struct Coord // koordynaty hexa
{
    int x, y, z;
    Coord(int x, int y, int z) : x(x), y(y), z(z) {}

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
};

#endif // COORD_H
