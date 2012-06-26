#include "samplestates.h"

#include "system/message.h"

StateVoid::StateVoid() {
    LINK(MessageRrmStart, StateVoid::handleRrmStart);
}
void StateVoid::handleRrmStart(Message *m) {
    std::cout << "handleRrmStart()" << std::endl;
    std::cout << "StateVoid::RRM Started" << std::endl;
    changeState(new StateRrm);
}

StateRrm::StateRrm() {
    LINK(MessageRrmDoCellSetup, StateRrm::handleRrmDoCellSetup);
    LINK(MessageRrmStop, StateRrm::handleRrmStop);
}
void StateRrm::handleRrmDoCellSetup(Message *m) {
    std::cout << "handleRrmDoCellSetup()" << std::endl;
    std::cout << "Cell Setup is successful" << std::endl;
    changeState(new StateRrmCellIsUp);
}
void StateRrm::handleRrmStop(Message *m) {
    std::cout << "handleRrmStop()" << std::endl;
    std::cout << "RRM is stopped" << std::endl;
    changeState(new StateVoid);
}

StateRrmCellIsUp::StateRrmCellIsUp() {
    LINK(MessageRrmDoCellTeardown, StateRrmCellIsUp::handleRrmDoCellTeardown);
}
void StateRrmCellIsUp::handleRrmDoCellTeardown(Message *m) {
    std::cout << "handleRrmDoCellTeardown()" << std::endl;
    std::cout << "Cell is torn down" << std::endl;
    changeState(new StateRrm);
}
