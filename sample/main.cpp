#include "system/state.h"
#include "system/message.h"
#include "system/thread.h"
#include "system/statemachine.h"
#include "system/messagerouter.h"

#include <iostream>
#include <string>
#include "samplestates.h"


int main(int argc, char **argv) {
    MessageRouter router;
    StateMachine<DispatchModeAsync> rrmFsm(new StateVoid);

    router.link<MessageRrmDoCellSetup>(&rrmFsm);
    router.link<MessageRrmStart>(&rrmFsm);

    router.send(new MessageRrmDoCellSetup);
    router.send(new MessageRrmStart);
    router.send(new MessageRrmDoCellSetup);

    rrmFsm.terminate();
    return 0;
}
