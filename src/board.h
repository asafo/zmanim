#include <Eina.h>
#include <Evas.h>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Edje.h>

class Board
{
 public:
    Board (const int width, const int height);
    
    void display();
    void message(const char *text);
	
 private:
    void init_e();
    void init_edje_file(const char *filename);
    
    Ecore_Evas *_window;
    Evas *_canvas;
    Evas_Object *_edje;
    int _width, _height;
};
