#include "system/state.h"
#include "system/message.h"

#include <iostream>
#include <string>

MESSAGE_IMPL_START(MessageA)
MESSAGE_IMPL_END

MESSAGE_IMPL_START(MessageB)
MESSAGE_IMPL_END

STATE_IMPL_START(MyState)
    MyState() {
        LINK_MESSAGE_TO_HANDLER(MessageA, MyState::handleA);
        LINK_MESSAGE_TO_HANDLER(MessageB, MyState::handleB);
    }

    void handleA(Message *m) { std::cout << "handleA()" << std::endl; }
    void handleB(Message *m) { std::cout << "handleB()" << std::endl; }
STATE_IMPL_END

int main(int argc, char **argv) {
    MyState state;
    Message *m = new MessageA();
    state.handle(m);
    m = new MessageB();
    state.handle(m);
}

