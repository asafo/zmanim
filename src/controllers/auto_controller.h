#include "../controller.h"
#include "../board.h"
#include "../board_elements/day_times/day_times.h"

class AutoController : public IController
{
 public:
    AutoController(Board *board);
    void onDisplay();
    void timer_expired();
 private:    
    Board *_board;
    DayTimes *_day_times;
};
