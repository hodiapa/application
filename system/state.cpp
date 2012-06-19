/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "state.h"

#include "message.h"

void State::handle(Message *message) {
    std::cout << "State::handle(" << message->getId() << ")" << std::endl;
}
