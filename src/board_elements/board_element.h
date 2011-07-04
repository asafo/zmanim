#pragma once

#include "board_element_iface.h"

#include <string>

class BoardElement : public IBoardElement
{
 private:
    std::string _edje_filename;
};
