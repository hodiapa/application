#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <iostream>

#include "thread.h"
#include "dispatcher.h"

class State;
class Message;
class Dispatcher;

class StateMachine {
public:
    StateMachine(Dispatcher *aDispatcher);
    ~StateMachine();
public:
    void setDispatcher(Dispatcher *aDispatcher);
    State *getState();
    void changeState(State *aState);
    void handle(Message *aMessage);
    void terminate();
private:
    State *state;
    Dispatcher *dispatcher;
};

#endif // __STATEMACHINE_H__
