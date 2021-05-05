#pragma once
#include"City.hpp"
#include "Board.hpp"
#include <iostream>
#include<string>
#include "Player.hpp"
using namespace std;
namespace pandemic
{
    class OperationsExpert:public Player//because "player.take_card" it accesses to the fun of the Player class 
    {
        public:
       OperationsExpert(Board &new_board,City new_city);
    };
}

