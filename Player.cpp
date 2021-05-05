#include "Player.hpp"
using namespace std;
namespace pandemic
{
            Player::Player(){

            }

    Player &Player::drive(City The_firstCity)
    {
        return *this;
    }
    Player &Player::fly_direct(City city_now)
    {
        return *this;
    }
    Player &Player::fly_charter(City randomCity)
    {
        return *this;
    }
    Player &Player::fly_shuttle(City another_city)
    {
        return *this;
    }
    Player &Player::build()
    {
        return *this;
    }
    Player &Player::discover_cure(Color The_color)
    {
        return *this;
    }

    Player &Player::treat(City city_now)
    {
        return *this;
    }

    string Player::role()
    {
        return " ";
    }
    Player &Player::take_card(City x)
    {
        return *this;
    }

}