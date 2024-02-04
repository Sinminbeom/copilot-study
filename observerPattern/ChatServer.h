#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Subscriber.h"
#include "User.h"

using namespace std;

class ChatServer {
private:
    unordered_map<string, vector<const Subscriber*>> subscribers;

public:
    void registerSubscriber(const string& subject, const Subscriber* subscriber);
    void unregisterSubscriber(const string& subject, const Subscriber* subscriber);
    void sendMessage(const User* user, const string& subject, const string& message);
};

#endif // CHATSERVER_H
