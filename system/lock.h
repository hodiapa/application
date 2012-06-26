#ifndef __LOCK_H__
#define __LOCK_H__

#include <pthread.h>

class Lock {
public:
    Lock();
    ~Lock();
public:
    void lock();
    void unlock();
protected:
    pthread_mutex_t mutex;
};

#endif // __LOCK_H__
