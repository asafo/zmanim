#include "board.h"

Board::Board (const int width, const int height)
{
    eina_init();
    evas_init();
    ecore_init();
    ecore_evas_init();
    edje_init();
    
    window = ecore_evas_new(NULL, 0, 0, width, height, NULL);	
    if (!window) {
	EINA_LOG_CRIT("could not create window.");	    
	    //	    throw new 
    }
    canvas = ecore_evas_get(window);   
    edje = create_splash_group(canvas, text, width, height);
    ///    if (!edje)
	// throw new 
}

void Board::display()
{    
    ecore_evas_show(window);
    ecore_main_loop_begin();

    evas_object_del(edje);
    ecore_evas_free(window);	
}

Evas_Object * Board::create_splash_group(Evas *canvas, const char *text, 
				 const int screenWidth, const int screenHeight)
{
    Evas_Object *edje;
    
    edje = edje_object_add(canvas);
    if (!edje)
	{
	    EINA_LOG_CRIT("could not create edje object!");
	    return NULL;
	}
    
    if (!edje_object_file_set(edje, "zmanim.edj", "main"))
	{
	    Edje_Load_Error err = edje_object_load_error_get(edje);
		const char *errmsg = edje_load_error_str(err);
		EINA_LOG_ERR("could not load 'my_group' from zmanim.edj: %s",
			     errmsg);
		
		evas_object_del(edje);
		return NULL;
	    }
    
    if (text)
	    {
		if (!edje_object_part_text_set(edje, "text", text))
		    {
			EINA_LOG_WARN("could not set the text. "
				      "Maybe part 'text' does not exist?");
		    }
	    }
    
	evas_object_move(edje, 0, 0);
	evas_object_resize(edje, screenWidth, screenHeight);
	evas_object_show(edje);
 	return edje;
}

