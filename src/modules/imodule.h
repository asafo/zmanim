#pragma once

#include "iboard.h"

class IModule
{
 public:
    virtual void render(IBoard *board) = 0;
};
