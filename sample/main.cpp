/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "system/state.h"
#include "system/message.h"
#include "system/thread.h"
#include "system/statemachine.h"

#include <iostream>
#include <string>
#include "samplestates.h"


int main(int argc, char **argv) {
    StateMachine fsm;
    fsm.changeState(new StateVoid);
    Message *m;
    m = new MessageRrmDoCellSetup();
    fsm.handle(m);
    m = new MessageRrmStart();
    fsm.handle(m);
    m = new MessageRrmDoCellSetup();
    fsm.handle(m);

    return 0;
}
