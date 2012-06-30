#ifndef __STATE_H__
#define __STATE_H__

#include "message.h"

#include <unordered_map>
#include <typeinfo>
#include <iostream>

class AbstractStateMachine;

class State {
public:
    State();
    virtual ~State();
private:
    void setStateMachine(AbstractStateMachine *aStateMachine);
protected:
    virtual void changeState(State *state);
public:
    virtual void handle(Message *message) = 0;
private:
    AbstractStateMachine *stateMachine;

    friend class AbstractStateMachine;
};

template <class S, class P=State>
class StateWithMessageHandler : public P {
protected:
    template <class M> void linkMessageToHandler(void (S::*handler)(Message *)) {
        std::cout << "Linking message type " << typeid(S*).name() <<
            " to handler " << typeid(handler).name() << std::endl;
        handlers[typeid(M*).name()] = handler;
    }
    virtual void handle(Message *message) {
        void (S::*handler)(Message *) = handlers[message->getId()];
        if (handler) {
            (dynamic_cast<S*>(this)->*handler)(message);
        } else {
            P::handle(message);
        }
    }
private:
    std::unordered_map<std::string, void(S::*)(Message *)> handlers;
};

#define SUB_STATE(_STATE, _PARENT_STATE) \
    class _STATE : public StateWithMessageHandler<_STATE, _PARENT_STATE>

#define STATE(_STATE) \
    class _STATE : public StateWithMessageHandler<_STATE>

#define LINK(MESSAGE, HANDLER) \
    linkMessageToHandler<MESSAGE>(&HANDLER);

#endif
