#ifndef USER_H
#define USER_H

#include <iostream>
#include "Subscriber.h"

using namespace std;

// ConcreteOserver
class User : public Subscriber {
private:
    string name;

public:
    User(const string& name);
    string getName() const;
    virtual void handleMessage(const string& message) const override;
};

#endif // USER_H
