#ifndef COORD_H
#define COORD_H

struct Coord // koordynaty hexa
{
    int x, y, z;
    Key(int x, int y, int z) : x(x), y(y), z(z) {} // konstruktor

    bool operator==(const Key &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }
};

#endif // COORD_H
