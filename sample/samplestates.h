#ifndef __SAMPLE_STATES_H__
#define __SAMPLE_STATES_H__

#include "system/state.h"

STATE(StateVoid) {
    virtual void setup();
    void handleRrmStart(Message *m);
};

STATE(StateRrm) {
    virtual void setup();
    void handleRrmDoCellSetup(Message *m);
    void handleRrmStop(Message *m);
};

SUB_STATE(StateRrmCellIsUp, StateRrm) {
    virtual void setup();
    void handleRrmDoCellTeardown(Message *m);
};

#endif // __SAMPLE_STATES_H__
