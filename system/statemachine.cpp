#include "statemachine.h"

#include "state.h"

StateMachine::StateMachine() : state(NULL) {
}

void StateMachine::handle(Message *aMessage) {
    if (state) {
        state->handle(aMessage);
    }
}

void StateMachine::changeState(State *aState) {
    if (state) {
        delete state;
    }
    state = aState;
    state->setStateMachine(this);
    state->setup();
}
