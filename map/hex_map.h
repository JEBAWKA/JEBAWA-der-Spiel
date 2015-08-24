#ifndef HEX_MAP_H
#define HEX_MAP_H

#include <unordered_map>
#include "coord.h"
#include "hex.h"

enum class DIRECTION : char
{
    // lepiej usunac przypisywanie numerkow i zostawic to kompilatorowi
    N  = 0,
    NE = 1,
    SE = 2,
    S  = 3,
    SW = 4,
    NW = 5
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
};

#endif // HEX_MAP_H
