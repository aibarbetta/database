#include "MessageQueue.h"

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string>
#include <cstring>
#include <cerrno>
#include <system_error>


MessageQueue::MessageQueue(key_t key) {
    if ((id = msgget(key, 0777| IPC_CREAT)) < 0) {
        std::string message = std::string("Error in msgget(): ") + std::string(strerror(errno));
        throw std::system_error(errno, std::system_category(), message);
    };
}

void MessageQueue::destroy() {
    msgctl(id, IPC_RMID, NULL);
}

int MessageQueue::push(EntryData* data) {
    int sent = msgsnd(id, data, sizeof(EntryData) - sizeof(long), 0);
    if (sent < 0) {
        std::string message = std::string("Error in msgsnd(): ") + std::string(strerror(errno));
        throw std::system_error(errno, std::system_category(), message); 
    }
    return sent;
}

EntryData MessageQueue::pop() {
    EntryData data;
    ssize_t received = msgrcv(id, &data, sizeof(EntryData) - sizeof(long), 0, 0);
    if (received < 0) {
        std::string message = std::string("Error in msgrcv(): ") + std::string(strerror(errno));
        throw std::system_error(errno, std::system_category(), message); 
    }
    return data;
}