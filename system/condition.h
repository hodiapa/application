#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "lock.h"

#include <pthread.h>

class Condition : public Lock {
public:
    Condition();
    ~Condition();
public:
    void wait();
    void notify();
private:
    pthread_cond_t condition;
};

#endif // __CONDITION_H__
