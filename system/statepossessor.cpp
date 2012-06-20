/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "statepossessor.h"

#include "state.h"

StatePossessor::StatePossessor() : state(NULL) {
}

void StatePossessor::handle(Message *message) {
    if (state) {
        state->handle(message);
    }
}
