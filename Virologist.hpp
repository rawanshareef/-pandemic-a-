#pragma once
#include <iostream>
#include "Board.hpp"
#include <iostream>
#include "Player.hpp"

namespace pandemic
{
    class Virologist:public Player//because "player.take_card" it accesses to the fun of the Player class 
    {
        public:
    Virologist(Board the_board, City the_city):Player(the_board, the_city){};
    

    };
}