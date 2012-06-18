#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <typeinfo>

#define MESSAGE_IMPL_START(MESSAGE) \
class MESSAGE : public Message { \
public: \
    virtual std::string getId() { return typeid(MESSAGE*).name(); }

#define MESSAGE_IMPL_END \
};

class Message {
public:
    virtual std::string getId() = 0;
};

#endif // __MESSAGE_H__
