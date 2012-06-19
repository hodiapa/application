/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "system/state.h"
#include "system/message.h"
#include "system/thread.h"

#include <iostream>
#include <string>

MESSAGE(MessageA)
MESSAGE_END

MESSAGE(MessageB)
MESSAGE_END

MESSAGE(MessageC)
MESSAGE_END

STATE(StateX)
    StateX() {
        LINK(MessageA, StateX::handleA);
        LINK(MessageB, StateX::handleB);
    }
    void handleA(Message *m) { std::cout << "handleA()" << std::endl; }
    void handleB(Message *m) { std::cout << "handleB()" << std::endl; }
STATE_END

EXTENDED_STATE(StateXX, StateX)
    StateXX() {
        LINK(MessageC, StateXX::handleC);
    }
    void handleC(Message *m) {std::cout << "handleC()" << std::endl; }
STATE_END

class MyThread : public Thread {
protected:
    virtual void run() {
        for (int i = 0; i < 1000; i++) {
            std::cout << i << std::endl;
        }
    }
};

int main(int argc, char **argv) {
    StateXX state;
    Message *m = new MessageA();
    state.handle(m);
    m = new MessageB();
    state.handle(m);

    MyThread t;
    t.start();
    t.join();

    return 0;
}

