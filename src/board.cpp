#include "board.h"

Board::Board (const int width, const int height, string theme) : _width(width), _height(height), _theme(theme)
{
    init_e();

    _window = ecore_evas_new(NULL, 0, 0, width, height, NULL);	
    if (!_window) {
	EINA_LOG_CRIT("could not create window.");	    
	    //	    throw new 
    }
    ecore_evas_borderless_set(_window, 1);
   
    _canvas = ecore_evas_get(_window);   
    
    _edje = edje_object_add(_canvas);
    if (!_edje)
	{
	    EINA_LOG_CRIT("could not create edje object!");
	    // return NULL;
	}
    //    edje = create_splash_group(canvas, text, width, height);
    ///    if (!edje)
	// throw new 
    init_edje_file(_theme, "main");
}

/*Board::~Board()
{
   evas_object_del(edje);
   ecore_evas_free(window);
   }*/

void Board::display()
{    
    ecore_evas_show(_window);
    //    _controller->onDisplay();
    ecore_main_loop_begin();

    evas_object_del(_edje);
    ecore_evas_free(_window);	
}

void Board::message(char const* text)
{    
    if (text)
	    {
		if (!edje_object_part_text_set(_edje, "message", text))
		    {
			EINA_LOG_WARN("could not set the text. "
				      "Maybe part 'message' does not exist?");
		    }
	    }     
}


void Board::init_e()
{
    eina_init();
    evas_init();
    ecore_init();
    ecore_evas_init();
    edje_init();
}

void Board::init_edje_file(std::string file, std::string group)
{
    if (!edje_object_file_set(_edje, file.c_str(), group.c_str()))
	{
	    Edje_Load_Error err = edje_object_load_error_get(_edje);
		const char *errmsg = edje_load_error_str(err);
		EINA_LOG_ERR("could not load '%s' from %s .edj: %s", group.c_str(), file.c_str(),
			     errmsg);
		
		evas_object_del(_edje);
		return;
	    }

    //	evas_object_move(_edje, 50, 50);
	evas_object_resize(_edje, _width, _height);
	evas_object_show(_edje);
}

void Board::add_module(IModule *module)
{
    _modules.push_back(module);
    module->render(this);
}


void Board::set_text(string part, string text)
{    
    if (!edje_object_part_text_set(_edje, part.c_str(), text.c_str()))
	{
	    EINA_LOG_WARN("could not set the text. "
			  "Maybe part 'message' does not exist?");
	}     
}



