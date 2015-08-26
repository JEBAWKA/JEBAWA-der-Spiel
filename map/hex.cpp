#include "hex.h"

void Hex::add_tag(TERRAIN_TYPE tag)
{
    tags.push_front(tag);
    tags.unique();
}

void Hex::remove_tag(TERRAIN_TYPE tag)
{
    tags.remove(tag);
}

Coord Hex::get_coord() const
{
    return this->coord;
}

/*
void Hex::add_building(Building bld)
{
    buildings.push_front(bld);
    buildings.unique();
}

void Hex::remove_building(Building bld)
{
    buildings.remove(bld);
}

void Hex::add_event(Event event)
{
    active_events.push_front(event);
    active_events.unique();
}

void Hex::remove_event(Event event)
{
    active_events.remove(event);
}
*/
