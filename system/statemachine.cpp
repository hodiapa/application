#include "statemachine.h"

#include "state.h"


StateMachine::StateMachine(Dispatcher *aDispatcher)
    : state(NULL), dispatcher(NULL) {
    setDispatcher(aDispatcher);
}

StateMachine::~StateMachine() {
    delete dispatcher;
}

void StateMachine::setDispatcher(Dispatcher *aDispatcher) {
    dispatcher = aDispatcher;
    dispatcher->setStateMachine(this);
}

void StateMachine::handle(Message *aMessage) {
    dispatcher->dispatch(aMessage);
}

State *StateMachine::getState() {
    return state;
}

void StateMachine::changeState(State *aState) {
    if (state) {
        delete state;
    }
    state = aState;
    state->setStateMachine(this);
}

void StateMachine::terminate() {
    dispatcher->terminate();
}
