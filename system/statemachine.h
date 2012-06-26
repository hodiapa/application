#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <iostream>

class State;
class Message;

class StateMachine {
public:
    StateMachine();
public:
    void changeState(State *aState);
    void handle(Message *aMessage);
private:
    State *state;
};

#endif // __STATEMACHINE_H__
