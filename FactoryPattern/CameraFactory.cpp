#include <iostream>
#include "SensorFactory.cpp"
#include "Camera.cpp"

using namespace std;

class CameraFactory : public SensorFactory {
public:
    Sensor* createSensor() override {
        return new Camera();
    }
};