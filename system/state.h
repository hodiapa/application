/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#ifndef __STATE_H__
#define __STATE_H__

#include "statepossessor.h"

#include "message.h"

#include <unordered_map>
#include <typeinfo>
#include <iostream>

class State {
public:
    State() : statePossessor(NULL) { }
public:
    void setStatePossesser(StatePossessor *aStatePossessor);
    virtual void setState(State *state);
public:
    virtual void setup() = 0;
    virtual void handle(Message *message) = 0;
private:
    StatePossessor *statePossessor;
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
