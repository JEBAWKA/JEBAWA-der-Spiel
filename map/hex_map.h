#ifndef HEX_MAP_H
#define HEX_MAP_H

#include <unordered_map>
#include <array>
#include "coord.h"
#include "hex.h"

enum class DIRECTION : char
{
    N,
    NE,
    SE,
    S,
    SW,
    NW
};

std::array<Coord, 6> direction_movement = {
    Coord(0, +1, -1), // N
    Coord(+1, 0, -1), // NE
    Coord(+1, -1, 0), // SE
    Coord(0, -1, +1), // S
    Coord(-1, 0, +1), // SW
    Coord(-1, +1, 0)  // NW
};

struct KeyHasher
{
    const int c = 1000; // wartosc wieksza niz bok mapy i c^3 < max unsigned long size
    std::size_t operator()(const Coord& k) const
    {
        return static_cast<std::size_t>(k.x + (k.y*c) + (k.z*c*c));
    }
};

class Hex_map
{
    std::unordered_map<Coord, Hex, KeyHasher> map;

public:
    Hex_map();
    Coord find_neighbour(Hex hex, DIRECTION direction);
    Hex& get_hex_neighbour(Hex hex, DIRECTION direction); // throws exceptions
    int distance(Hex& first, Hex& second);
    int distance(Coord first, Coord second);
};

#endif // HEX_MAP_H
