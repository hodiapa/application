#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <iostream>

#include "thread.h"
#include "messagequeue.h"

class State;
class Message;

class AbstractStateMachine {
public:
    AbstractStateMachine(State *initialState = NULL);
    ~AbstractStateMachine();
public:
    virtual State *getState();
    virtual void changeState(State *aState);
    virtual void handle(Message *aMessage) = 0;
    virtual void terminate() = 0;
private:
    State *state;
};

typedef enum {
    DispatchModeSync = 0,
    DispatchModeAsync
} DispatchMode;

template <DispatchMode D>
class StateMachine {
};

template<>
class StateMachine<DispatchModeSync>
        : public AbstractStateMachine {
public:
    StateMachine(State *initialState=NULL);
    ~StateMachine();
public:
    virtual void handle(Message *aMessage);
    virtual void terminate() {}
};

template<>
class StateMachine<DispatchModeAsync>
        : public AbstractStateMachine, public Thread {
public:
    StateMachine(State *initialState=NULL);
    ~StateMachine();
public:
    virtual void handle(Message *aMessage);
    virtual void terminate();
protected:
    virtual void run();
private:
    State *state;
    MessageQueue messageQueue;
};

#endif // __STATEMACHINE_H__
