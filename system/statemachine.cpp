#include "statemachine.h"

#include "state.h"

StateMachine::StateMachine()
: state(NULL), messageQueue() {
}

StateMachine::~StateMachine() {
    join();
}

void StateMachine::handle(Message *aMessage) {
    messageQueue.push(aMessage);
}

void StateMachine::changeState(State *aState) {
    if (state) {
        delete state;
    }
    state = aState;
    state->setStateMachine(this);
}

void StateMachine::run() {
    while (alive) {
        Message *message = messageQueue.pop();
        if (state) {
            state->handle(message);
        } else {
            std::cout << "Error: Can't start StateMachine when state is NULL" << std::endl;
        }
    }
}
