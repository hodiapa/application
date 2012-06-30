#include "statemachine.h"

#include "state.h"

AbstractStateMachine::AbstractStateMachine(State *initialState)
    : state(NULL) {
    if (initialState) {
        changeState(initialState);
    }
}

AbstractStateMachine::~AbstractStateMachine() {
}

State *AbstractStateMachine::getState() {
    return state;
}

void AbstractStateMachine::changeState(State *aState) {
    if (state) {
        delete state;
    }
    state = aState;
    state->setStateMachine(this);
}


StateMachine<DispatchModeSync>::StateMachine(State *initialState)
    : AbstractStateMachine(initialState) {

}

StateMachine<DispatchModeSync>::~StateMachine() {

}

void StateMachine<DispatchModeSync>::handle(Message *aMessage) {
    getState()->handle(aMessage);
    delete aMessage;
}


StateMachine<DispatchModeAsync>::StateMachine(State *initialState)
    : AbstractStateMachine(initialState) {

}

StateMachine<DispatchModeAsync>::~StateMachine() {

}

void StateMachine<DispatchModeAsync>::handle(Message *aMessage) {
    if (!alive) {
        start();
    }
    messageQueue.push(aMessage);
}


void StateMachine<DispatchModeAsync>::terminate() {
    while (messageQueue.size()) {
        sleep(0.2);
    }
    if (alive) {
        alive = false;
        join();
    }
}

void StateMachine<DispatchModeAsync>::run() {
    while (alive) {
        Message *message = messageQueue.pop();
        std::cout << "messageQueue.pop() -> " << message->getId() << std::endl;
        State *state = getState();
        if (state) {
            state->handle(message);
            delete message;
        } else {
            std::cout << "Error: Can't handle message when state is NULL" << std::endl;
        }
    }
}
