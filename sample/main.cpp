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
    StateMachine fsm(new AsyncDispatcher);
    fsm.changeState(new StateVoid);
    fsm.handle(new MessageRrmDoCellSetup());
    fsm.handle(new MessageRrmStart());
    fsm.handle(new MessageRrmDoCellSetup());
    fsm.terminate();
    return 0;
}
