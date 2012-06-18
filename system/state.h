#ifndef __STATE_H__
#define __STATE_H__

#include <unordered_map>
#include <typeinfo>

class Message;

#define STATE_IMPL_START(STATE) \
class STATE : public State { \
private: \
    std::unordered_map<std::string, void(STATE::*)(Message *)> handlers; \
public: \
    template <class M> \
    void linkMessageToHandler(void (STATE::*handler)(Message *)) { \
        std::cout << "Linking message type " << typeid(M*).name() << " to handler " << typeid(handler).name() << std::endl; \
        handlers[typeid(M*).name()] = handler; \
    } \
    void handle(Message *message) { \
        void (STATE::*handler)(Message *) = handlers[message->getId()]; \
        if (!handler) { \
            std::cout << typeid(STATE).name() << " could not handle message " << message->getId() << std::endl; \
            return; \
        } \
        (this->*handler)(message); \
    }

#define STATE_IMPL_END \
};

#define LINK_MESSAGE_TO_HANDLER(MESSAGE, HANDLER) \
    linkMessageToHandler<MESSAGE>(&HANDLER);

class State {
};

#endif
