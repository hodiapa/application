#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include <typeinfo>

class Message {
public:
    virtual std::string getId() = 0;
    virtual int getPriority() const = 0;
};

bool operator<(const Message& lhs, const Message& rhs);

template <class M, int PR=0, class P=Message>
class ConcreteMessage : public P {
public:
    virtual std::string getId() { return typeid(M*).name(); }
    virtual int getPriority() const { return PR; }
};

#define SUB_MESSAGE(_MESSAGE, _PARENT_MESSAGE, _PRIORITY) \
    class _MESSAGE : public ConcreteMessage<_MESSAGE, _PRIORITY, _PARENT_MESSAGE>

#define MESSAGE(_MESSAGE, _PRIORITY) \
    class _MESSAGE : public ConcreteMessage<_MESSAGE, _PRIORITY>

#endif // __MESSAGE_H__
