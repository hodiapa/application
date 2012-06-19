/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread {
public:
    Thread();
public:
    bool start();
    bool join();
    virtual void run() = 0;
protected:
    static void *exec(void *thread);
private:
    pthread_t id;
    Thread(const Thread &rhs);
    Thread &operator=(const Thread &rhs);
};

#endif // __THREAD_H__
