#include "ChatServer.h"
#include "User.h"
#include "Subscriber.h"
#include <iostream>
#include <vector>

int main() {
    ChatServer chatServer;
    User *user1 = new User("minbeom");
    User *user2 = new User("subin");

    chatServer.registerSubscriber("AI4팀", user1);
    chatServer.registerSubscriber("AI4팀", user2);

    chatServer.registerSubscriber("AI1팀", user2);

    chatServer.sendMessage(user1, "AI4팀", "회식장소 추천해줘");
    chatServer.sendMessage(user2, "AI1팀", "오늘은 뭐먹지?");

    return 0;
}
