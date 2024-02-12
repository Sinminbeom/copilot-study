#include <iostream>
#include "Sensor.cpp"

using namespace std;

class Lidar : public Sensor {
public:
    Lidar()
    {
        cout << "Lidar created" << endl;
        this->setName("at128");
        this->setType("lidar");
    }
    ~Lidar() override
    {
        cout << "Lidar destroyed" << endl;
    }

};