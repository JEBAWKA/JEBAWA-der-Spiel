#ifndef HEX_MAP_H
#define HEX_MAP_H

#include <unordered_map>
#include "coord.h"

struct KeyHasher
{
    const int c = 1000; // wartosc wieksza niz bok mapy i c^3 < max unsigned long size
    std::size_t operator()(const Key& k) const
    {
        return static_cast<std::size_t>(x + (y*c) + (z*c*c));
    }
};

class Hex_map
{
    std::unordered_map<Coord, Hex, KeyHasher> map;

public:
    Hex_map();
};

#endif // HEX_MAP_H
