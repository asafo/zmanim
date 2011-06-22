#include <iostream>

#include "board.h"
#include "controllers/auto_controller.h"


int main(int argc, char *argv[])
{
    
    Board board(1024,768);
    IController *ctl = new AutoController(&board);
    board.display();

    return 0;
}
