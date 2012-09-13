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
    MessageRouter router;
    StateMachine<DispatchModeAsync> fsm(new MyState);

    router.link<MyMessage>(&fsm);
    router.send(new MyMessage());

    int i;
    cin >> i;
    return 0;
}

