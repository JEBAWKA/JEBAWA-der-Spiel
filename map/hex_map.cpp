#include "hex_map.h"

#include <cmath>

Hex_map::Hex_map() {}

void Hex_map::set_size(int x, int y)
{
    this->map.resize(y, std::vector<std::pair<bool, std::shared_ptr<Hex>>(x, std::make_pair(false, nullptr)));
}

Hex_map::Hex_map(int x, int y)
{
    this->set_size(x,y);
}

int Hex_map::distance(Coord first, Coord second) // podstawowa
{
    return sqrt((second.x-first.x)*(second.x-first.x)+(second.y-first.y)*(second.y-first.y)); // twierdzenie pitagorasa a^2+b^2 = c^2
}

int Hex_map::distance(Hex first, Hex second)
{
    return distance(first.get_coord(), second.get_coord());
}

int Hex_map::distance(std::shared_ptr<Hex> first, std::shared_ptr<Hex> second)
{
    return distance(first->get_coord(), second->get_coord());
}

Coord Hex_map::find_neighbour(Coord hex, Coord direction) // podstawowa
{
    return hex + direction; // direction jest typu coord? w sumie to bardzo wygodne
}

Coord Hex_map::find_neighbour(Hex hex, Coord direction)
{
    return find_neighbour(hex.get_coord(), direction);
}

Coord Hex_map::find_neighbour(std::shared_ptr<Hex> hex, Coord direction)
{
    return find_neighbour(hex->get_coord(), direction);
}

std::shared_ptr<hex> Hex_map::find_neighbour_ptr(Coord hex, Coord direction) // podstawowa
{
    auto neigbour_coord = find_neighbour(hex, direction);
    return map[neigbour_coord.x][neigbour_coord.y].second;
}

std::shared_ptr<hex> Hex_map::find_neighbour_ptr(Hex hex, Coord direction)
{
    return find_neighbour_ptr(hex.get_coord(), direction);
}

std::shared_ptr<hex> Hex_map::find_neighbour_ptr(std::shared_ptr<Hex> hex, Coord direction)
{
    return find_neighbour_ptr(hex->get_coord(), direction);
}

/*
std::vector<std::shared_ptr<Hex>> Hex_map::get_neighbours(Hex hex) // chyba niepotrzebna
{

}
*/

Hex Hex_map::get_hex_copy(Coord coord) // lepiej nie uzywac
{
    return *map[coord.x][coord.y].second;
}
