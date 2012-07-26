#ifndef __MESSAGEROUTER_H__
#define __MESSAGEROUTER_H__

#include "message.h"
#include "statemachine.h"

#include <unordered_map>

class MessageRouter {
public:
    MessageRouter();
public:
    template <class M> void link(StateMachine<DispatchModeAsync> *aStateMachine) {
        if (!aStateMachine) {
            std::cout << "MessageRouter::link(): aStateMachine is NULL" << std::endl;
            return;
        }
        stateMachines[typeid(M*).name()] = aStateMachine;
    }
    void send(Message *aMessage);
private:
    std::unordered_map<std::string, StateMachine<DispatchModeAsync>*> stateMachines;
};

#endif // __MESSAGEROUTER_H__
