#ifndef HEX_H
#define HEX_H

#include <list>
#include "coord.h"

enum class : char TERRAIN_TYPE
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
    Hex(Coord coord) : coord(coord) {} // konstruktor
    void add_tag(TERRAIN_TYPE tag)
    {
        tags.push_front(tag);
        tags.unique();
    }
    void remove_tag(TERRAIN_TYPE tag)
    {
        tags.remove(tag);
    }
    Coord get_coord()
    {
        return this->coord;
    }
    /*void add_building(Building bld)
    {
        buildings.push_front(bld);
        buildings.unique();
    }
    void remove_building(Building bld)
    {
        buildings.remove(bld);
    }
    void add_event(Event event)
    {
        active_events.push_front(event);
        active_events.unique();
    }
    void remove_event(Event event)
    {
        active_events.remove(event);
    }*/
};

#endif // HEX_H
