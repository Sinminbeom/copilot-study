#include <iostream>
#include <string>
#include <gtest/gtest.h>
using namespace std;

class Camera1SensorInfo;
class Camera1SensorLogging;
class Camera2SensorInfo;
class Camera2SensorLogging;
class SensorInfo;
class SensorLogging;

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
    void setSensorInfo(SensorInfo* sensorInfo) {
        this->sensorInfo = sensorInfo;
    }
    void setSensorLogging(SensorLogging* sensorLogging) {
        this->sensorLogging = sensorLogging;
    }
    SensorInfo* getSensorInfo() {
        return this->sensorInfo;
    }
    SensorLogging* getSensorLogging() {
        return this->sensorLogging;
    }

private:
    string name;
    string type;
    SensorInfo* sensorInfo;
    SensorLogging* sensorLogging;
};


class SensorPropertyFactory {
public:
    SensorPropertyFactory() {
        std::cout << "SensorPropertyFactory created" << std::endl;
    }
    virtual SensorInfo* createSensorInfo() = 0;
    virtual SensorLogging* createSensorLogging() = 0;
};

class SensorInfo {
public:
    SensorInfo() {
        cout << "SensorInfo created" << endl;
    }
    ~SensorInfo() {}
};

class SensorLogging {
public:
    SensorLogging() {
        cout << "SensorLogging created" << endl;
    }
    ~SensorLogging() {}
};

class CameraLogging: public SensorLogging {
public:
    CameraLogging() {
        cout << "CameraLogging created" << endl;
    }
};

class CameraSensorInfo: public SensorInfo {
public:
    CameraSensorInfo() {
        cout << "CameraSensorInfo created" << endl;
    }
};

class CameraPropertyFactory: public SensorPropertyFactory{
public:
    CameraPropertyFactory() {
        cout << "CameraPropertyFactory created" << endl;
    }
};

// ==============================================

class Camera1SensorInfo: public CameraSensorInfo{
public:
    Camera1SensorInfo() {
        cout << "Camera1SensorInfo created" << endl;
    }
};

class Camera1SensorLogging: public CameraLogging{
public:
    Camera1SensorLogging() {
        cout << "Camera1SensorLogging created" << endl;
    }
};
// ==============================================

class Camera1PropertyFactory: public CameraPropertyFactory{
public:
    Camera1PropertyFactory() {
        cout << "Camera1PropertyFactory created" << endl;
    }
    SensorInfo* createSensorInfo() override {
        return new Camera1SensorInfo();
    }
    SensorLogging* createSensorLogging() override {
        return new Camera1SensorLogging();
    }
};

class Camera2SensorInfo: public CameraSensorInfo{
public:
    Camera2SensorInfo() {
        cout << "Camera2SensorInfo created" << endl;
    }
};
class Camera2SensorLogging: public CameraLogging{
public:
    Camera2SensorLogging() {
        cout << "Camera2SensorLogging created" << endl;
    }
};

class Camera2PropertyFactory: public CameraPropertyFactory{
public:
    Camera2PropertyFactory() {
        cout << "Camera2PropertyFactory created" << endl;
    }
    SensorInfo* createSensorInfo() override {
        return new Camera2SensorInfo();
    }
    SensorLogging* createSensorLogging() override {
        return new Camera2SensorLogging();
    }
};

class Camera : public Sensor {
public:
    Camera()
    {
        cout << "Camera created" << endl;
    }
    ~Camera() override
    {
        cout << "Camera destroyed" << endl;
    }
};

class Camera1 : public Camera {
public:
    Camera1() {
        cout << "Camera1 created" << endl;
    }
    ~Camera1() override
    {
        cout << "Camera destroyed" << endl;
    }
};

class SensorFactory {
public:
    SensorFactory() {
        cout << "SensorFactory created" << endl;
    }
    virtual Sensor* createSensor() = 0;
};

class CameraSensorFactory: public SensorFactory{
public:
    CameraSensorFactory() {
        cout << "CameraSensorFactory created" << endl;
    }
};

class Camera1SensorFactory: public CameraSensorFactory {
public:
    Camera1SensorFactory(SensorPropertyFactory* propertyFactory) {
        this->propertyFactory = propertyFactory;
        cout << "Camera1SensorFactory created" << endl;
    }
    Sensor* createSensor() {
        Sensor* sensor = new Camera1();
        sensor->setName("Camera1");
        sensor->setType("Camera");
        sensor->setSensorInfo(propertyFactory->createSensorInfo());
        sensor->setSensorLogging(propertyFactory->createSensorLogging());
        return sensor;
    }

private:
    SensorPropertyFactory* propertyFactory;
};

class Camera2SensorFactory: public CameraSensorFactory {
public:
    Camera2SensorFactory(SensorPropertyFactory* propertyFactory) {
        this->propertyFactory = propertyFactory;
        cout << "Camera2SensorFactory created" << endl;
    }
    Sensor* createSensor() {
        Sensor* sensor = new Camera1();
        sensor->setName("Camera2");
        sensor->setType("Camera");
        sensor->setSensorInfo(propertyFactory->createSensorInfo());
        sensor->setSensorLogging(propertyFactory->createSensorLogging());
        return sensor;
    }

private:
    SensorPropertyFactory* propertyFactory;
};

int main() {
    SensorFactory* camera1SensorFactory = new Camera1SensorFactory(new Camera1PropertyFactory());
    Sensor* camera1 = camera1SensorFactory->createSensor();
    cout << camera1->getName() << endl;
    cout << camera1->getType() << endl;

    cout << "===========================" << endl;

    SensorFactory* camera2SensorFactory = new Camera2SensorFactory(new Camera2PropertyFactory());
    Sensor* camera2 = camera2SensorFactory->createSensor();
    cout << camera2->getName() << endl;
    cout << camera2->getType() << endl;
    return 0;
}
