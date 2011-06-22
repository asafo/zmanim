#include <unistd.h>
#include <signal.h>

#include "auto_controller.h"

AutoController *__instance;

AutoController::AutoController(Board *board) : _board(board) 
{
    _board->set_controller(this);
    __instance = this;
}

void AutoController::timer_expired()
{
    printf("timer_expired\n");
    _board->message("Text");
}

void timer_handler (int signum)
{
    __instance->timer_expired();
    alarm(2);
}

void AutoController::onDisplay()
{
    _board->message("...ליחתמ");
    struct sigaction sa;
    memset (&sa, 0, sizeof (sa));
    sa.sa_handler = &timer_handler;
    sigaction (SIGALRM, &sa, NULL);
    alarm(2);
}
