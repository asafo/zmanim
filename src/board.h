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
	
 private:
    Evas_Object *create_splash_group(Evas *canvas, const char *text, 
				     const int screenWidth, const int screenHeight);
    
    Ecore_Evas *window;
    Evas *canvas;
    Evas_Object *edje;
    const char *text;
};
