#pragma once

#include <iostream>

using namespace std;

class Sensor {
public:
    Sensor()
    {
        cout << "Sensor created" << endl;
    }
    virtual ~Sensor()
    {
        cout << "Sensor destroyed" << endl;
    }
    string getName() {
        return this->name;
    }
    string getType() {
        return this->type;
    }
    void setName(string name) {
        this->name = name;
    }
    void setType(string type) {
        this->type = type;
    }

private:
    string name;
    string type;
};