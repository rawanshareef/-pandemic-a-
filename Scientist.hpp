#pragma once
#include <iostream>
#pragma once
#include <iostream>
#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include "Board.hpp"
#include <iostream>
#include "Player.hpp"

namespace pandemic
{
    class Scientist:public Player//because "player.take_card" it accesses to the fun of the Player class 
    {
        private:
        int x;
        public:
    Scientist(Board the_board, City the_city,int num):Player(the_board, the_city),x(num){};
    

    };
}