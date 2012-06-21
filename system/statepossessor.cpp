/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "statepossessor.h"

#include "state.h"

StatePossessor::StatePossessor() : state(NULL) {
}

void StatePossessor::handle(Message *aMessage) {
    if (state) {
        state->handle(aMessage);
    }
}

void StatePossessor::setState(State *aState) {
    if (state) {
        delete state;
    }
    state = aState;
    state->setup();
}