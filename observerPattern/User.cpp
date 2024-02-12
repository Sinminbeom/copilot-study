#include "User.h"

User::User(const string& name) : name(name) {}

string User::getName() const {
    return name;
}

void User::handleMessage(const string& message) const {
    cout << message << endl;
}

// int main() {
//     User *user = new User("minbeom");
//     user->handleMessage("hello world");
//     return 0;
// }
