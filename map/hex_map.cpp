#include "hex_map.h"

Hex_map::Hex_map()
{

}

int Hex_map::distance(Hex &first,Hex &second)
{
    Coord f = first.get_coord();
    Coord s = second.get_coord();
        return (abs(f.x - s.x) + abs(f.y - s.y) + abs(f.z - s.z)) / 2;
}
