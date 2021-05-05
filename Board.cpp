#include "Board.hpp"
//#define NumCity 48 
using namespace std;
namespace pandemic
{
Board::Board() {
}
        int &Board::operator[](City city){
            return a_level[city];
        }
        bool  Board::is_clean(){
            return true;
        }
        void Board::remove_cures(){

        }
         ostream &operator<<(ostream &os, Board &b){
             return os<<"pandamic";
         }






}


