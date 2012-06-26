#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <iostream>

#include "thread.h"
#include "messagequeue.h"

class State;
class Message;

class StateMachine : public Thread {
public:
    StateMachine();
    ~StateMachine();
public:
    void changeState(State *aState);
    void handle(Message *aMessage);
public:
    void run();
private:
    State *state;
    MessageQueue messageQueue;
};

#endif // __STATEMACHINE_H__
