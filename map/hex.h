#ifndef HEX_H
#define HEX_H

#include <list>
#include "coord.h"

enum class TERRAIN_TYPE : char
{
    LAKE = 0,
    FOREST = 1,
    RIVER = 2,
    SWAMP = 3,
    ROAD = 4,
    VILLIGE = 5,
    TOWN = 6,
    GRASS = 7,
    MOUNTAIN = 8,
    HILL = 9,
    SNOW = 10,
    DESERT = 11
    //and so on...
};

class Hex
{
    Coord coord; // koordynaty hexa
    std::list<TERRAIN_TYPE> tags;
    //std::list<Building> buildings;
    //std::list<Event>   active_events;
    //Dodac Eventy i budynki.

public:
    // konstruktory
    Hex() {}
    Hex(Coord coord) : coord(coord) {}
    Hex(int x, int y, int z) : coord(Coord(x, y, z)) {}
    // destruktor
    ~Hex() {}

    void add_tag(TERRAIN_TYPE tag);
    void remove_tag(TERRAIN_TYPE tag);
    Coord get_coord();
    /*
    void add_building(Building bld);
    void remove_building(Building bld);
    void add_event(Event event);
    void remove_event(Event event);
    */
};

#endif // HEX_H
