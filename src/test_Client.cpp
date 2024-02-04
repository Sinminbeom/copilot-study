#include <gtest/gtest.h>
#include "ChatServer.h"
#include "User.h"
#include "Subscriber.h"

TEST(ClientTest, SendMessageTest) {
    ChatServer chatServer;
    
    User* sangwon = new User("sangwon");
    User* myeongseong = new User("myeongseong");
    User* namgon = new User("namgon");
    User* jinhwan = new User("jinhwan");
    User* yongwoo = new User("yongwoo");
    User* minbeom = new User("minbeom");
    User* yeoeun = new User("yeoeun");

    chatServer.registerSubscriber("AI4", sangwon);
    chatServer.registerSubscriber("AI4", myeongseong);
    chatServer.registerSubscriber("AI4", namgon);
    chatServer.registerSubscriber("AI4", jinhwan);
    chatServer.registerSubscriber("AI4", yongwoo);
    chatServer.registerSubscriber("AI4", minbeom);

    chatServer.registerSubscriber("AI1", yeoeun);

    chatServer.registerSubscriber("TF", yeoeun);
    chatServer.registerSubscriber("TF", namgon);
    chatServer.registerSubscriber("TF", minbeom);

    chatServer.sendMessage(minbeom, "AI4", "회식메뉴가 항상 고민이야");
    chatServer.sendMessage(namgon, "TF", "어떤 내용을 넣어야 좋을까...?");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}