/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#ifndef __STATE_H__
#define __STATE_H__

class Message;

#include "statepossessor.h"

#include <unordered_map>
#include <typeinfo>
#include <iostream>

class State {
public:
    State() : statePossessor(NULL) { }
public:
    void setStatePossesser(StatePossessor *statePossessor);
    template <class S> void setState() {
        statePossessor->setState<S>();
    }

public:
    virtual void setup() = 0;
    virtual void handle(Message *message);
private:
    StatePossessor *statePossessor;
};

#define EXTENDED_STATE(_STATE, _PARENT_STATE) \
class _STATE : public _PARENT_STATE { \
private: \
    std::unordered_map<std::string, void(_STATE::*)(Message *)> handlers; \
public: \
    template <class M> void linkMessageToHandler(void (_STATE::*handler)(Message *)) { \
        std::cout << "Linking message type " << typeid(M*).name() << " to handler " << typeid(handler).name() << std::endl; \
        handlers[typeid(M*).name()] = handler; \
    } \
    void handle(Message *message) { \
        void (_STATE::*handler)(Message *) = handlers[message->getId()]; \
        if (handler) { \
            (this->*handler)(message); \
        } else { \
            _PARENT_STATE::handle(message); \
        } \
    }

#define STATE(_STATE) \
    EXTENDED_STATE(_STATE, State)

#define STATE_END \
};

#define LINK(MESSAGE, HANDLER) \
    linkMessageToHandler<MESSAGE>(&HANDLER);

#endif
