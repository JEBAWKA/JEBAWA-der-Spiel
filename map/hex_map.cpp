#include "hex_map.h"

#include <cmath>
#include <map>

std::map<DIRECTION, Coord> direction_movement = {
    {DIRECTION::N,  Coord( 0, -1)},
    {DIRECTION::NE, Coord(+1,  0)},
    {DIRECTION::SE, Coord(+1, +1)},
    {DIRECTION::S,  Coord( 0, +1)},
    {DIRECTION::SW, Coord(-1, +1)},
    {DIRECTION::NW, Coord(-1,  0)}
};

Hex_map::Hex_map() {}

void Hex_map::set_size(int x, int y)
{
    auto row = std::vector<std::pair<bool, std::shared_ptr<Hex>>>(x, std::make_pair(false, nullptr));
    this->map.resize(y, row);
}

Hex_map::Hex_map(int x, int y) : size_x(x), size_y(y)
{
    this->set_size(x,y);
}

int Hex_map::distance(Coord first, Coord second) // podstawowa
{
    // twierdzenie pitagorasa a^2+b^2 = c^2
    double a = (static_cast<double>(second.x) - static_cast<double>(first.x));
    double b = (static_cast<double>(second.y) - static_cast<double>(first.y));
    return round(sqrt( a*a + b*b ));
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
    return hex + direction;
}

Coord Hex_map::find_neighbour(Hex hex, DIRECTION direction)
{
    return find_neighbour(hex.get_coord(), direction_movement[direction]);
}

Coord Hex_map::find_neighbour(std::shared_ptr<Hex> hex, DIRECTION direction)
{
    return find_neighbour(hex->get_coord(), direction_movement[direction]);
}

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(Coord hex, Coord direction) // podstawowa
{
    auto neigbour_coord = find_neighbour(hex, direction);
    return map[neigbour_coord.x][neigbour_coord.y].second;
}

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(Hex hex, DIRECTION direction)
{
    return find_neighbour_ptr(hex.get_coord(), direction_movement[direction]);
}

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(std::shared_ptr<Hex> hex, DIRECTION direction)
{
    return find_neighbour_ptr(hex->get_coord(), direction_movement[direction]);
}

Hex Hex_map::get_hex_copy(Coord coord) // lepiej nie uzywac
{
    return *map[coord.x][coord.y].second;
}

std::shared_ptr<Hex> Hex_map::add_hex(Hex hex) //podstawowa, zwraca wskaznik na dodanego heksa
{
    auto coord = hex.get_coord();
    hexes.push_back(hex); // dodaje na koniec nowy hex o podanych koordynatach
    map[coord.x][coord.y].first = true; // ustawia flage na istniejacego hexa
    map[coord.x][coord.y].second = std::make_shared<Hex>(hexes.back()); // przypisuje pointer na nowego hexa
    return map[coord.x][coord.y].second; // zwraca shared_ptr na nowego hexa
}

std::shared_ptr<Hex> Hex_map::add_hex(Coord coord)
{
    return add_hex(Hex(coord)); // dodaje nowo stworzonego hexa o podanych koordynatach
}

bool Hex_map::remove_hex(Hex hex) // podstawowa, zwraca czy udalo sie usunac
{
    auto coord = hex.get_coord();
    if(map[coord.x][coord.y].first == false)
    {
        return false; // nie mozna usunac nieistniejacego obiektu
    }
    hexes.remove(hex); // usuwa wlasciwy obiekt z listy
    map[coord.x][coord.y].first = false; // ustawia flage na puste pole
    map[coord.x][coord.y].second.reset(); // resetuje wskaznik
    map[coord.x][coord.y].second = nullptr; // i ustawia na nullptr
    return true;
}

bool Hex_map::remove_hex(std::shared_ptr<Hex> hex)
{
    return remove_hex(*hex); // dereferencja
}

bool Hex_map::remove_hex(Coord coord)
{
    return remove_hex(get_hex_copy(coord));
}

std::vector<std::shared_ptr<Hex>> Hex_map::get_neighbours(Coord hex) // podstawowa
{
    std::vector<std::shared_ptr<Hex>> neighbours = {};
    std::vector<Coord> directions = {};
    for(auto p : direction_movement)
    {
        directions.push_back(p.second);
    }

    for(auto dir : directions)
    {
        if(hex_exists(hex + dir))
        {
            neighbours.push_back( get_hex_ptr(hex + dir) );
        }
    }
    return neighbours;
}

std::vector<std::shared_ptr<Hex>> Hex_map::get_neighbours(Hex hex)
{
    return get_neighbours(hex.get_coord());
}

std::vector<std::shared_ptr<Hex>> Hex_map::get_neighbours(std::shared_ptr<Hex> hex)
{
    return get_neighbours(hex->get_coord());
}

bool Hex_map::is_coord_within_map(Coord coord) // czy dane koordynaty naleza do planszy
{
    return (coord.x >= 0 && coord.y >= 0 &&        // koordynaty nie moga byc ujemne
            coord.x < size_x && coord.y < size_y); // koordynaty nie moga byc wieksze ani rowne
    // wielkosci planszy
}

bool Hex_map::hex_exists(Coord coord) // czy hex o podanych koordynatach istnieje
{
    return map[coord.x][coord.y].first; // zwraca flage informujaca czy hex istnieje
}

std::shared_ptr<Hex> Hex_map::get_hex_ptr(Coord coord)
{
    return get_pair_ref(coord).second; // zwraca wskaznik
}

std::pair<bool, std::shared_ptr<Hex>>& Hex_map::get_pair_ref(Coord coord)
{
    return map[coord.y][coord.x];
}
