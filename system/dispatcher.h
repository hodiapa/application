#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__

#include "thread.h"
#include "messagequeue.h"

class StateMachine;
class Message;

class Dispatcher {
public:
    void setStateMachine(StateMachine *aStateMachine);
    virtual void dispatch(Message *message) = 0;
    virtual void terminate() = 0;
protected:
    StateMachine *stateMachine;
};

class SyncDispatcher : public Dispatcher {
public:
    virtual void dispatch(Message *message);
    virtual void terminate();
};

class AsyncDispatcher : public Dispatcher, public Thread {
public:
    virtual void dispatch(Message *message);
    virtual void terminate();
protected:
    void run();
private:
    MessageQueue messageQueue;
};

#endif // __DISPATCHER_H__
