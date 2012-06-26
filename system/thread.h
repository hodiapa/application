#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread {
public:
    Thread();
public:
    bool start();
    bool join();
protected:
    virtual void run() = 0;
    static void *exec(void *thread);
protected:
    bool alive;
private:
    pthread_t threadId;
    Thread(const Thread &rhs);
    Thread &operator=(const Thread &rhs);
};

#endif // __THREAD_H__
