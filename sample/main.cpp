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

MESSAGE(MessageRrm, 0) {
};

SUB_MESSAGE(MessageRrmStart, MessageRrm, 0) {
};

SUB_MESSAGE(MessageRrmDoCellSetup, MessageRrm, 0) {
};

SUB_MESSAGE(MessageRrmDoCellTeardown, MessageRrm, 0) {
};

SUB_MESSAGE(MessageRrmStop, MessageRrm, 0) {
};

#include "samplestates.h"

class Module : public StatePossessor {
public:
    Module() {
        setState(new StateVoid);
    }
};

int main(int argc, char **argv) {
    Module module;
    Message *m;
    m = new MessageRrmDoCellSetup();
    module.handle(m);
    m = new MessageRrmStart();
    module.handle(m);
    m = new MessageRrmDoCellSetup();
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

