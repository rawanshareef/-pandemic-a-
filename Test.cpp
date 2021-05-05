#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace pandemic;
TEST_CASE(" Test1")
{
    Board board;
    CHECK(board.is_clean() == true);
    board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    CHECK(board.is_clean());

    CHECK_NE(board[City::Kinshasa], board[City::MexicoCity]);
    CHECK_EQ(board[City::HoChiMinhCity], board[City::Chicago]);
    CHECK_NE(board[City::Kinshasa], board[City::HoChiMinhCity]);
    CHECK_EQ(board[City::HoChiMinhCity], board[City::HoChiMinhCity]);
    board[City::SanFrancisco] = 2; // put 2 blue disease cubes in SanFrancisco.
    CHECK_EQ(board[City::Kinshasa], board[City::SanFrancisco]);
    CHECK_NE(board[City::HoChiMinhCity], board[City::SanFrancisco]);
    board[City::Istanbul] = 1; // put 1 black disease cubes in Istanbul
    CHECK_EQ(board[City::Istanbul], board[City::HoChiMinhCity]);
    CHECK_EQ(board[City::Istanbul], board[City::Chicago]);
    CHECK_NE(board[City::Istanbul], board[City::Kinshasa]);
    CHECK_NE(board[City::Istanbul], board[City::MexicoCity]);
}
TEST_CASE("Test2")
{
    Board board;
    CHECK_FALSE(board.is_clean() == 0);
    CHECK(board.is_clean() != 0);
    CHECK_EQ(board[City::Istanbul], board[City::HoChiMinhCity]); //(0,0)
    CHECK_EQ(board[City::Istanbul], board[City::Chicago]);
    CHECK_EQ(board[City::Istanbul], board[City::Kinshasa]);
    CHECK_EQ(board[City::Istanbul], board[City::MexicoCity]);
    board[City::Kinshasa] = 3; // put 3 yellow disease cubes in Kinshasa.
    CHECK_NE(board[City::Kinshasa], board[City::HoChiMinhCity]);
    GeneSplicer player1{board, City::BuenosAires};

    player1.take_card(City::Istanbul)
        .take_card(City::Santiago)
        .take_card(City::Lagos)
        .take_card(City::London)
        .take_card(City::Khartoum);
    CHECK_NOTHROW(player1.discover_cure(Color::Black));

    GeneSplicer player2{board, City::Miami};
    player2.take_card(City::Miami)
        .take_card(City::Santiago)
        .take_card(City::Lagos)
        .take_card(City::London)
        .take_card(City::Khartoum);
    CHECK_NOTHROW(player2.discover_cure(Color::Yellow));

    GeneSplicer player3{board, City::NewYork};

    player3.take_card(City::Miami)
        .take_card(City::Santiago)
        .take_card(City::Lagos)
        .take_card(City::London)
        .take_card(City::Khartoum);

    CHECK_NOTHROW(player2.discover_cure(Color::Black));
}
TEST_CASE("Test 3")
{
    Board board;

    CHECK(board.is_clean());
    board[City::Atlanta] = 5;
    board[City::Paris] = 1;
    board[City::HoChiMinhCity] = 1;
    board[City::London] = 3;

    Researcher player1{board, City::Paris};
    player1.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);
    CHECK(player1.role() == string("Researcher"));
    player1.build();
    CHECK(board[City::London] == 3);
    CHECK(board[City::Paris] == 1);
}
