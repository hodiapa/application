#include "messagequeue.h"

MessageQueue::MessageQueue() : queue(), condition() {
}

Message *MessageQueue::pop() {
    condition.lock();
        while (!queue.size()) {
            condition.wait();
        }
        Message *message = queue.top();
        queue.pop();
    condition.unlock();
    return message;
}

void MessageQueue::push(Message *message) {
    condition.lock();
        queue.push(message);
        condition.notify();
    condition.unlock();
}
