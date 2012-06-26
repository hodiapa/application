#include "condition.h"

Condition::Condition() {
    pthread_cond_init(&condition, NULL);
}

Condition::~Condition() {
    pthread_cond_destroy(&condition);
}

void Condition::wait() {
    pthread_cond_wait(&condition, &mutex);
}

void Condition::notify() {
    pthread_cond_signal(&condition);
}
