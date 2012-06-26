#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include "message.h"
#include <queue>

using namespace std;

class MessageQueue {
public:
    MessageQueue();
public:
    Message *pop();
    void push(Message *message);
private:
    priority_queue<Message *,
                   vector<Message *>,
                   less<vector<Message *>::value_type> > queue;
};

#endif // MESSAGEQUEUE_H
