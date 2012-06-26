#include "message.h"

bool operator<(const Message& lhs, const Message& rhs) {
    return lhs.getPriority() < rhs.getPriority();
}
