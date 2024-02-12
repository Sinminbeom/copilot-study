#include <iostream>
#include "Sensor.cpp"

using namespace std;

class Gnss : public Sensor {
public:
    Gnss()
    {
        cout << "Gnss created" << endl;
        this->setName("gnss");
        this->setType("gnss");
    }
    ~Gnss() override
    {
        cout << "Gnss destroyed" << endl;
    }
};