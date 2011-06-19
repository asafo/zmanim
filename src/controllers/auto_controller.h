#include "../controller.h"
#include "../board.h"

class AutoController : public IController
{
 public:
    AutoController(Board *board);
    void onDisplay();
 private:
    Board *_board;
};
