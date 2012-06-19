#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include "thread.h"

#include "message.h"
#include <queue>

class MessageQueue {
public:
    MessageQueue();
public:
    Message *pop();
    void push(Message *message);
private:
    std::priority_queue<Message *,
                        std::vector<Message *>,
                        MessageComparator> queue;
};

#endif // MESSAGEQUEUE_H
