/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#include "thread.h"

Thread::Thread() {
}

bool Thread::start() {
    return !pthread_create(&id, NULL, &Thread::exec, this);
}

bool Thread::join() {
    return bool(pthread_join(id, NULL));
}

void *Thread::exec(void *thread) {
    reinterpret_cast<Thread *>(thread)->run();
    return NULL;
}
