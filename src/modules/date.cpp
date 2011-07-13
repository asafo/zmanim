#include "date.h"

#include <libintl.h>

#include <string>
#include <iostream>
#include <hdatepp.h>
using namespace hdate;
using namespace std;

void Date::render(IBoard *board)
{
    Hdate h;
    h.set_hdate(12,12,5771);
    h.set_israel();
    cout<<gettext("hello")<<endl;
    wstring date(h.get_format_date(0));
    cout<<h.get_format_date(0)<<endl;
    board->load_group("date");
    board->set_text("date_text", date);
}

