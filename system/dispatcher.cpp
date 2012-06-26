#include "dispatcher.h"

#include "state.h"
#include "statemachine.h"
#include <time.h>

void Dispatcher::setStateMachine(StateMachine *aStateMachine) {
    stateMachine = aStateMachine;
}


void SyncDispatcher::dispatch(Message *message) {
    stateMachine->getState()->handle(message);
    delete message;
}

void SyncDispatcher::terminate() {

}


void AsyncDispatcher::dispatch(Message *message) {
    if (!alive) {
        start();
    }
    messageQueue.push(message);
}

void AsyncDispatcher::run() {
    while (alive) {
        Message *message = messageQueue.pop();
        State *state = stateMachine->getState();
        if (state) {
            state->handle(message);
            delete message;
        } else {
            std::cout << "Error: Can't handle message when state is NULL" << std::endl;
        }
    }
}

void AsyncDispatcher::terminate() {
    while (messageQueue.size()) {
        sleep(0.2);
    }
    if (alive) {
        alive = false;
        join();
    }
}
