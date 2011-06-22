#include "../controller.h"
#include "../board.h"

class AutoController : public IController
{
 public:
    AutoController(Board *board);
    void onDisplay();
    void timer_expired();
 private:    
    Board *_board;
};
