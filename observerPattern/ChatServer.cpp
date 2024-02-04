#include "ChatServer.h"
#include <algorithm>

void ChatServer::registerSubscriber(const string& subject, const Subscriber* subscriber) {
    subscribers[subject].push_back(subscriber);
}

void ChatServer::unregisterSubscriber(const string& subject, const Subscriber* subscriber) {
    auto it = subscribers.find(subject);
    if (it != subscribers.end()) {
        auto& subscriberList = it->second;
        subscriberList.erase(remove(subscriberList.begin(), subscriberList.end(), subscriber), subscriberList.end());
    }
}

void ChatServer::sendMessage(const User* user, const string& subject, const string& message) {
    auto it = subscribers.find(subject);
    if (it != subscribers.end()) {
        const string userMessage = user->getName() + ": " + message;
        for (const auto& subscriber : it->second) {
            subscriber->handleMessage(userMessage);
        }
    }
}
