#include "samplestates.h"

#include "system/message.h"

class MessageRrmStart;
class MessageRrmDoCellSetup;
class MessageRrmStop;
class MessageRrmDoCellTeardown;

void StateVoid::setup() {
    LINK(MessageRrmStart, StateVoid::handleRrmStart);
}
void StateVoid::handleRrmStart(Message *m) {
    std::cout << "handleRrmStart()" << std::endl;
    std::cout << "StateVoid::RRM Started" << std::endl;
    setState(new StateRrm);
}

void StateRrm::setup() {
    LINK(MessageRrmDoCellSetup, StateRrm::handleRrmDoCellSetup);
    LINK(MessageRrmStop, StateRrm::handleRrmStop);
}
void StateRrm::handleRrmDoCellSetup(Message *m) {
    std::cout << "handleRrmDoCellSetup()" << std::endl;
    std::cout << "Cell Setup is successful" << std::endl;
    setState(new StateRrmCellIsUp);
}
void StateRrm::handleRrmStop(Message *m) {
    std::cout << "handleRrmStop()" << std::endl;
    std::cout << "RRM is stopped" << std::endl;
    setState(new StateVoid);
}

void StateRrmCellIsUp::setup() {
    LINK(MessageRrmDoCellTeardown, StateRrmCellIsUp::handleRrmDoCellTeardown);
}
void StateRrmCellIsUp::handleRrmDoCellTeardown(Message *m) {
    std::cout << "handleRrmDoCellTeardown()" << std::endl;
    std::cout << "Cell is torn down" << std::endl;
    setState(new StateRrm);
}
