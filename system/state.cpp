#include "state.h"

#include "message.h"
#include "statemachine.h"

State::State() : stateMachine(NULL) {

}

State::~State() {

}

void State::handle(Message *message) {
    std::cout << "State::handle(" << message->getId() << ")" << std::endl;
}

void State::setStateMachine(AbstractStateMachine *aStateMachine) {
    stateMachine = aStateMachine;
}

void State::changeState(State *state) {
    stateMachine->changeState(state);
}

