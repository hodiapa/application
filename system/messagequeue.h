#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include "condition.h"
#include "message.h"
#include <queue>

using namespace std;

class MessageQueue {
public:
    MessageQueue();
public:
    Message *pop();
    void push(Message *message);
    unsigned int size();
private:
    priority_queue<Message *,
                   vector<Message *>,
                   MessageComparator> queue;
    Condition condition;
};

#endif // MESSAGEQUEUE_H
