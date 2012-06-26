#ifndef __SAMPLE_STATES_H__
#define __SAMPLE_STATES_H__

#include "system/state.h"

MESSAGE(MessageRrm, 0) { };
SUB_MESSAGE(MessageRrmStart, MessageRrm, 0) { };

STATE(StateVoid) {
    virtual void setup();
    void handleRrmStart(Message *m);
};

SUB_MESSAGE(MessageRrmDoCellSetup, MessageRrm, 0) { };
SUB_MESSAGE(MessageRrmStop, MessageRrm, 0) { };

STATE(StateRrm) {
    virtual void setup();
    void handleRrmDoCellSetup(Message *m);
    void handleRrmStop(Message *m);
};

SUB_MESSAGE(MessageRrmDoCellTeardown, MessageRrm, 0) { };

SUB_STATE(StateRrmCellIsUp, StateRrm) {
    virtual void setup();
    void handleRrmDoCellTeardown(Message *m);
};

#endif // __SAMPLE_STATES_H__
