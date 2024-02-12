#pragma once
#include <iostream>
#include "Sensor.cpp"

using namespace std;

class SensorFactory {
public:
    SensorFactory() {
        cout << "SensorFactory created" << endl;
    }
    Sensor* orderSensor() {
        Sensor* sensor = createSensor();
        return sensor;
    }
    virtual Sensor* createSensor() = 0;
};