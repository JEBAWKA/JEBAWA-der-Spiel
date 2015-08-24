#include "hex_map.h"

Hex_map::Hex_map()
{

}

Coord Hex_map::find_neighbour(Hex hex, DIRECTION direction)
{
    return hex.get_coord() + direction_movement[static_cast<int>(direction)]; // zakaz niejawnej konwersji
}

Hex& Hex_map::get_hex_neighbour(Hex hex, DIRECTION direction) // throws exceptions
{
    return map.at(find_neighbour(hex, direction));
}

int Hex_map::distance(Coord f, Coord s)
{
    return (abs(f.x - s.x) + abs(f.y - s.y) + abs(f.z - s.z)) / 2;
}

int Hex_map::distance(Hex& first, Hex& second)
{
    return this->distance(first.get_coord(), second.get_coord());
}
