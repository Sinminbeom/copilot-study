#include <iostream>
#include "Sensor.cpp"

using namespace std;

class Camera : public Sensor {
public:
    Camera()
    {
        cout << "Camera created" << endl;
        this->setName("am20");
        this->setType("camera");
    }
    ~Camera() override
    {
        cout << "Camera destroyed" << endl;
    }
};