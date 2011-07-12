#pragma once

#include <string>

using std::string;

class IBoard 
{
 public:
    virtual void get_canvas() = 0;
    virtual void load_group(string group) = 0;
    virtual void set_text(string part, string text) = 0;
    // schduele_refresh
};
