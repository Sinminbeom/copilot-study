#include <iostream>
#include <typeinfo>
#include "CameraPropertyFactory.cpp"

int main() {
    SensorPropertyFactory* propertyFactory = new Camera1PropertyFactory();
    SensorFactory* sensorFactory = new Camera1SensorFactory(propertyFactory);
    Sensor* sensor = sensorFactory->createSensor();

    if (typeid(*sensor) == typeid(Camera1)) {
        std::cout << "Sensor is an instance of Camera1" << std::endl;
    } else {
        std::cout << "Sensor is not an instance of Camera1" << std::endl;
    }

    delete sensor;
    delete sensorFactory;
    delete propertyFactory;

    return 0;
}