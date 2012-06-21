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
    void setState(State *aState);
    void handle(Message *aMessage);
private:
    State *state;
};

#endif // __STATEPOSSESSOR_H__
