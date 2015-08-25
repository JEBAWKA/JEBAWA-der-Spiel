#include "hex_map.h"

    Hex_map::Hex_map(){};
    void Hex_map::set_size(int x,int y)
    {
        map.resize(y,std::vector(x,make_pair(false,nullptr)));
    }
    Hex_map::Hex_map(int x,int y)
    {
        Hex_map.set_size(x,y);
    }
    int distance(Coord first, Coord second); // podstawowa

    int distance(Hex first, Hex second);
    int distance(std::shared_ptr<hex> first, std::shared_ptr<hex> second);
    Coord find_neighbour(Hex hex, Coord direction); // podstawowa
    Coord find_neighbour(std::shared_ptr<Hex> hex, Coord direction);
    std::shared_ptr<hex> find_neighbour_ptr(Hex hex, Coord direction); // podstawowa
    std::shared_ptr<hex> find_neighbour_ptr(std::shared_ptr<Hex> hex, Coord direction);
    std::vector<std::shared_ptr<Hex>> get_neigbbours(Hex hex);
