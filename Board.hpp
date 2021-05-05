
#pragma once
#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Board
    {
    private:
        std::map<City, Color> color;
       std:: map<City, int> a_level;

        // map<string, map<string, int>> myMap;

    public:
        Board();
        int &operator[](City city);
        bool is_clean();
        void remove_cures();
        friend std::ostream &operator<<(std::ostream &os, Board &b);
    };
}