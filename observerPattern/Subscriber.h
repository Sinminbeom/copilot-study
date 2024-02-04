#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

using namespace std;

class Subscriber {
public:
    virtual void handleMessage(const string& message) const = 0;
};

#endif // SUBSCRIBER_H