#ifndef HEX_MAP_H
#define HEX_MAP_H

#include <unordered_map>
#include <memory>
#include <utility>
#include <vector>
#include "coord.h"
#include "hex.h"

class Hex_map
{
    int size_x, size_y;
    std::vector<std::vector<std::pair<bool, std::shared_ptr<Hex>>>> map;
    std::list <Hex> hexes;
    Hex get_hex_copy(Coord coord); // lepiej nie uzywac

    // 2 niebezpieczne metody - nie wiadomo czy hex istnieje
    // dlatego uzytkownik nie moze sam ich wywolac
    Coord find_neighbour(Coord hex, Coord direction); // podstawowa
    std::shared_ptr<Hex> find_neighbour_ptr(Coord hex, Coord direction); // podstawowa

    bool is_coord_within_map(Coord coord); // czy dane koordynaty naleza do planszy
    bool hex_exists(Coord coord); // czy hex o podanych koordynatach istnieje
public:
    void set_size(int x, int y);
    Hex_map();
    Hex_map(int x, int y);
    std::shared_ptr<Hex> add_hex(Coord where); //Zwraca wskaznik na dodanego heksa.
    bool remove_hex(Coord where); //Zwraca czy udalo sie usunac;
    int distance(Coord first, Coord second); // podstawowa
    int distance(Hex first, Hex second);
    int distance(std::shared_ptr<Hex> first, std::shared_ptr<Hex> second);
    Coord find_neighbour(Hex hex, Coord direction);
    Coord find_neighbour(std::shared_ptr<Hex> hex, Coord direction);
    std::shared_ptr<Hex> find_neighbour_ptr(Hex hex, Coord direction);
    std::shared_ptr<Hex> find_neighbour_ptr(std::shared_ptr<Hex> hex, Coord direction);

    // tych lepiej nie uzywac
    std::vector<std::shared_ptr<Hex>> get_neighbours(Coord hex); // podstawowa
    std::vector<std::shared_ptr<Hex>> get_neighbours(Hex hex);
    std::vector<std::shared_ptr<Hex>> get_neighbours(std::shared_ptr<Hex> hex);

    std::shared_ptr<Hex> get_hex_ptr(Coord coord);
};

#endif // HEX_MAP_H
