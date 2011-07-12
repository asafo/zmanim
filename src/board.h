#pragma once

#include <string>
#include <vector>

#include <Eina.h>
#include <Evas.h>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>

#include "modules/iboard.h"
#include "modules/imodule.h"

using std::string;
using std::vector;

class Board : public IBoard
{
 public:
    Board (const int width, const int height, string theme);
    
    void display();
    void message(const char *text);
    void add_module(IModule *module);

    // module interface:
    void load_group(string group)     { init_edje_file(_theme, group); }
    void get_canvas() {};    
    void set_text(string part, string text);
    //    void set_controller(IController *controller) { _controller = controller; };
    //  void add_element(IBoardElement *element);
 private:
    void init_e();
    void init_edje_file(string file, string group);
    
    Ecore_Evas *_window;
    Evas *_canvas;
    Evas_Object *_edje;
    int _width, _height;
    vector<IModule*> _modules;
    string _theme;
};
