#ifndef __SAMPLE_STATES_H__
#define __SAMPLE_STATES_H__

#include "system/state.h"


STATE(StateVoid)
    void handleRrmStart(Message *m);
STATE_END

STATE(StateRrm)
    void handleRrmDoCellSetup(Message *m);
    void handleRrmStop(Message *m);
STATE_END

SUB_STATE(StateRrmCellIsUp, StateRrm)
    void handleRrmDoCellTeardown(Message *m);
STATE_END

#endif // __SAMPLE_STATES_H__
