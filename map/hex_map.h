#ifndef HEX_MAP_H
#define HEX_MAP_H
#define N Coord(
#include <unordered_map>
#include <memory>
#include <utility>
#include "coord.h"
#include "hex.h"

class Hex_map
{
    std::vector<std::vector<std::pair<bool,std::shared_ptr<Hex> > >  map;
    std::list <Hex> hexes;
public:
    void set_size(int x,int y);
    Hex_map();
    Hex_map(int x,int y);
    std::shared_ptr<Hex> add_hex(Coord where); //Zwraca wskaznik na dodanego heksa.
    bool remove_hex(Coord where); //Zwraca czy udalo sie usunac;
    int distance(Coord first, Coord second); // podstawowa
    int distance(Hex first, Hex second);
    int distance(std::shared_ptr<hex> first, std::shared_ptr<hex> second);
    Coord find_neighbour(Hex hex, Coord direction); // podstawowa
    Coord find_neighbour(std::shared_ptr<Hex> hex, Coord direction);
    std::shared_ptr<Hex> find_neighbour_ptr(Hex hex, Coord direction); // podstawowa
    std::shared_ptr<Hex> find_neighbour_ptr(std::shared_ptr<Hex> hex, Coord direction);
};

#endif // HEX_MAP_H
