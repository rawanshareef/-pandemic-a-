#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Board.hpp"

namespace pandemic
{
    class Player
    {
    private:
        City The_firstCity;
        int numOfCards;
        Board board;

    public:
            Player();
        Player(Board &board2, City The_city)
: board(board2), The_firstCity(The_city){}
        Player &drive(City The_firstCity);
        Player &fly_direct(City city_now);
        Player &fly_charter(City randomCity);
        Player &fly_shuttle(City another_city);
        Player &build();
        Player &discover_cure(Color The_color);
        Player &treat(City city_now);
        std::string role();
        Player &take_card(City x);
    };

}
