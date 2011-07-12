#include "date.h"

#include <hdatepp.h>
using namespace hdate;

void Date::render(IBoard *board)
{
    Hdate h;

    board->load_group("date");
    board->set_text("date_text", h.get_format_date (0));
}
