#include <iostream>
#include "SensorFactory.cpp"
#include "Gnss.cpp"

using namespace std;

class GnssFactory : public SensorFactory {
public:
    Sensor* createSensor() override {
        return new Gnss();
    }
};
