#include <Eina.h>
#include <Evas.h>
#include <Ecore.h>
#pragma once

#include <Ecore_Evas.h>
#include <Edje.h>

#include "controller.h"

class Board
{
 public:
    Board (const int width, const int height);
    
    void display();
    void message(const char *text);
    void set_controller(IController *controller) { _controller = controller; };
 private:
    void init_e();
    void init_edje_file(const char *filename);
    
    Ecore_Evas *_window;
    Evas *_canvas;
    Evas_Object *_edje;
    int _width, _height;
    IController *_controller;
};
