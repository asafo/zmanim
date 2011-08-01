#include <iostream>
#include <hdatepp.h>

#include <locale.h>

#include "board.h"
#include "modules/date.h"
#include "modules/daytimes.h"

using namespace std;
using namespace hdate;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "he_IL.utf-8");
    Hdate h;

    Board board(1024, 768, "basic.edj");
    board.add_module(new Date());
    board.add_module(new DayTimes());
    board.display();

    return 0;
}
