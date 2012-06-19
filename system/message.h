/*
 * Author: Bengi Mizrahi
 * Date: June 18, 2012
 */

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <typeinfo>

class Message {
public:
    virtual std::string getId() = 0;
};

#define EXTENDED_MESSAGE(_MESSAGE, _PARENT_MESSAGE) \
class _MESSAGE : public _PARENT_MESSAGE { \
public: \
    virtual std::string getId() { return typeid(_MESSAGE*).name(); }

#define MESSAGE(_MESSAGE) \
    EXTENDED_MESSAGE(_MESSAGE, Message)

#define MESSAGE_END \
};

#endif // __MESSAGE_H__
