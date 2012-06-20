/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#ifndef __STATEPOSSESSOR_H__
#define __STATEPOSSESSOR_H__

#include <iostream>

class State;
class Message;

class StatePossessor {
public:
    StatePossessor();
public:
    template <class S> void setState() {
        if (state) {
            delete state;
        }
        state = new S();
        state->setup();
    }
    void handle(Message *message);
private:
    State *state;
};

#endif // __STATEPOSSESSOR_H__
