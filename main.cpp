/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "system/state.h"
#include "system/message.h"
#include "system/thread.h"
#include "system/statepossessor.h"

#include <iostream>
#include <string>

MESSAGE(MessageRrm)
    MessageRrm() : Message(0) { }
MESSAGE_END

EXTENDED_MESSAGE(MessageRrmStart, MessageRrm)
MESSAGE_END

EXTENDED_MESSAGE(MessageRrmDoCellSetup, MessageRrm)
MESSAGE_END

EXTENDED_MESSAGE(MessageRrmDoCellTeardown, MessageRrm)
MESSAGE_END

EXTENDED_MESSAGE(MessageRrmStop, MessageRrm)
MESSAGE_END

class StateVoid;
class StateRrm;
class StateRrmCellIsUp;

STATE(StateVoid)
    virtual void setup() {
        LINK(MessageRrmStart, StateVoid::handleRrmStart);
    }
    void handleRrmStart(Message *m) {
        std::cout << "handleRrmStart()" << std::endl;
        std::cout << "RRM Started" << std::endl;
        setState<StateRrm>();
    }
STATE_END

STATE(StateRrm)
    virtual void setup() {
        LINK(MessageRrmDoCellSetup, StateRrm::handleRrmDoCellSetup);
        LINK(MessageRrmStop, StateRrm::handleRrmStop);
    }
    void handleRrmDoCellSetup(Message *m) {
        std::cout << "handleRrmDoCellSetup()" << std::endl;
        std::cout << "Cell Setup is successful" << std::endl;
        setState<StateRrmCellIsUp>();
    }
    void handleRrmStop(Message *m) {
        std::cout << "handleRrmStop()" << std::endl;
        std::cout << "RRM is stopped" << std::endl;
        setState<StateVoid>();
    }
STATE_END

EXTENDED_STATE(StateRrmCellIsUp, StateRrm)
    virtual void setup() {
        LINK(MessageRrmDoCellTeardown, StateRrmCellIsUp::handleRrmDoCellTeardown);
    }
    void handleRrmDoCellTeardown(Message *m) {
        std::cout << "handleC()" << std::endl;
        std::cout << "Cell is torn down" << std::endl;
    }
STATE_END

class Module : public StatePossessor {
public:
    Module() {
        setState<StateVoid>();
    }
};

int main(int argc, char **argv) {
    Module module;
    Message *m = new MessageRrmStart();
    module.handle(m);

    return 0;
}


class MyThread : public Thread {
protected:
    virtual void run() {
        for (int i = 0; i < 4; i++) {
            std::cout << i << std::endl;
        }
    }
};

int _main(int argc, char **argv) {
    MyThread t;

    t.start();
    t.join();
    return 0;
}

