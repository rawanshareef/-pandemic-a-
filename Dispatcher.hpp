#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include "Board.hpp"
#include <iostream>
#include "Player.hpp"

namespace pandemic
{
    class Dispatcher:public Player//because "player.take_card" it accesses to the fun of the Player class 
    {
        public:
    Dispatcher(Board the_board, City the_city):Player(the_board, the_city){};
    

    };
}

