#include <iostream>
#include <hdatepp.h>

#include "board.h"
#include "modules/date.h"

using namespace std;
using namespace hdate;

int main(int argc, char *argv[])
{
    Hdate h;

    Board board(1024, 768, "basic.edj");
    board.add_module(new Date());
    board.display();

    /*    cout<<h.get_month_string(1)<<endl;
       cout << "Today is :\n";
	cout << h.get_gday () << "," << h.get_gmonth () << "," << h.get_gyear () << "\n";
	
	// print hebrew date: 0 - israely holidays, 0 - long format
	cout << h.get_format_date (0);
	cout << "\n";*/


    return 0;
}
