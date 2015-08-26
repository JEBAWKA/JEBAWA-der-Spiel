#include "hex_map.h"

#include <cmath>

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

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(Coord hex, Coord direction) // podstawowa
{
    auto neigbour_coord = find_neighbour(hex, direction);
    return map[neigbour_coord.x][neigbour_coord.y].second;
}

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(Hex hex, Coord direction)
{
    return find_neighbour_ptr(hex.get_coord(), direction);
}

std::shared_ptr<Hex> Hex_map::find_neighbour_ptr(std::shared_ptr<Hex> hex, Coord direction)
{
    return find_neighbour_ptr(hex->get_coord(), direction);
}

Hex Hex_map::get_hex_copy(Coord coord) // lepiej nie uzywac
{
    return *map[coord.x][coord.y].second;
}

std::shared_ptr<Hex> Hex_map::add_hex(Coord coord)
{
   hexes.push_back( Hex(coord) ); // dodaje na koniec nowy hex o podanych koordynatach
   map[coord.x][coord.y].first = true; // ustawia flage na istniejacego hexa
   map[coord.x][coord.y].second = std::make_shared<Hex>(hexes.back()); // przypisuje pointer na nowego hexa
   return map[coord.x][coord.y].second; // zwraca shared_ptr na nowego hexa
}

bool Hex_map::remove_hex(Coord coord)
{
    if(map[coord.x][coord.y].first == false)
    {
        return false; // nie mozna usunac nieistniejacego obiektu
    }
    hexes.remove(get_hex_copy(coord)); // usuwa wlasciwy obiekt z listy
    map[coord.x][coord.y].first = false; // ustawia flage na puste pole
    map[coord.x][coord.y].second.reset(); // resetuje wskaznik
    map[coord.x][coord.y].second = nullptr; // i ustawia na nullptr
    return true;
}

std::vector<std::shared_ptr<Hex>> Hex_map::get_neighbours(Coord hex) // podstawowa
{
    // TODO napisz to
    std::vector<std::shared_ptr<Hex> neigbours = {};
    return neigbours;
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
                                                   // od wielkosci planszy
}

bool Hex_map::hex_exists(Coord coord) // czy hex o podanych koordynatach istnieje
{
    return map[coord.x][coord.y].first; // zwraca flage informujaca czy hex istnieje
}
