#include "system/system.h"
#include <iostream>

using namespace std;

MESSAGE(MyMessage, 1) {

};

STATE(MyState) {
public:
    MyState() {
        LINK(MyMessage, MyState::handleMyMessage);
    }
    void handleMyMessage(Message *m) {
        cout << "handleMyMessage()" << endl;
    }
};

int main(int argc, char *argv[]) {
    MyState state;
    StateMachine<DispatchModeSync> fsm(&state);

    Message *m = new MyMessage();
    fsm.handle(m);

    return 0;
}

