#include "samplestates.h"

#include "system/message.h"

EXTENDED_STATE_IMPL(StateVoid, State)
void StateVoid::setup() {
    LINK(MessageRrmStart, StateVoid::handleRrmStart);
}
void StateVoid::handleRrmStart(Message *m) {
    std::cout << "handleRrmStart()" << std::endl;
    std::cout << "RRM Started" << std::endl;
    setState(new StateRrm);
}

EXTENDED_STATE_IMPL(StateRrm, State)
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

EXTENDED_STATE_IMPL(StateRrmCellIsUp, StateRrm)
void StateRrmCellIsUp::setup() {
    LINK(MessageRrmDoCellTeardown, StateRrmCellIsUp::handleRrmDoCellTeardown);
}
void StateRrmCellIsUp::handleRrmDoCellTeardown(Message *m) {
    std::cout << "handleC()" << std::endl;
    std::cout << "Cell is torn down" << std::endl;
}
