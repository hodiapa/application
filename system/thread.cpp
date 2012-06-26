#include "thread.h"

Thread::Thread() : alive(false) {
}

bool Thread::start() {
    alive = true;
    return !pthread_create(&threadId, NULL, &Thread::exec, this);
}

bool Thread::join() {
    if (alive) {
        return bool(pthread_join(threadId, NULL));
    }
    return true;
}

void *Thread::exec(void *thread) {
    reinterpret_cast<Thread *>(thread)->run();
    return NULL;
}
