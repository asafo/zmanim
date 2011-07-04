#include <iostream>
#include <hdatepp.h>

#include "board.h"
#include "controllers/auto_controller.h"

using namespace std;
using namespace hdate;

int main(int argc, char *argv[])
{
    Hdate h;

    cout<<h.get_month_string(1)<<endl;
       cout << "Today is :\n";
	cout << h.get_gday () << "," << h.get_gmonth () << "," << h.get_gyear () << "\n";
	
	// print hebrew date: 0 - israely holidays, 0 - long format
	cout << h.get_format_date (0);
	cout << "\n";

    Board board(1024,768);
    IController *ctl = new AutoController(&board);
    board.display();

    return 0;
}
