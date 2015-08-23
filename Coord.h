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
};

#endif // COORD_H
