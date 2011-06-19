#include "auto_controller.h"

AutoController::AutoController(Board *board) : _board(board) {}

void AutoController::onDisplay()
{
    _board->message("Starting..");
}
