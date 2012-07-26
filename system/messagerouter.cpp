#include "messagerouter.h"

#include "statemachine.h"

MessageRouter::MessageRouter() {
}

void MessageRouter::send(Message *aMessage) {
    StateMachine<DispatchModeAsync> *stateMachine = stateMachines[aMessage->getId()];
    if (!stateMachine) {
        std::cout << "MessageRouter::send(): no stateMachine linked to " << typeid(aMessage).name() << std::endl;
        return;
    }
    stateMachine->handle(aMessage);
}
