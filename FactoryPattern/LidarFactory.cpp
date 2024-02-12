#include <iostream>
#include "SensorFactory.cpp"
#include "Lidar.cpp"

using namespace std;

class LidarFactory : public SensorFactory {
public:
    LidarFactory() {
        cout << "LidarFactory created" << endl;
    }
    Sensor* createSensor() override {
        return new Lidar();
    }
};
