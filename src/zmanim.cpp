#include <iostream>

#include "board.h"


int main(int argc, char *argv[])
{
    
    Board board(1024,768);
    std::cerr<<"Calling display";
    board.display();

    return 0;
}
