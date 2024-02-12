#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Camera1SensorInfo;
class Camera1SensorLogging;
class Camera2SensorInfo;
class Camera2SensorLogging;
class SensorInfo;
class SensorLogging;

enum ELoggingStatus
{
    START,
    ERROR,
    END
};

/**
 * @class SensorLogging
 * @brief Class representing the sensor logging functionality.
 * 
 * This class provides methods to set and get the logging status of a sensor.
 */
class SensorLogging {
public:
    /**
     * @brief Constructor for SensorLogging class.
     * 
     * This constructor is called when a SensorLogging object is created.
     * It prints a message indicating that a SensorLogging object has been created.
     */
    SensorLogging() {
        cout << "SensorLogging created" << endl;
    }

    /**
     * Destructor for the SensorLogging class.
     */
    ~SensorLogging() {}

    /**
     * @brief Sets the logging status of the camera property factory.
     * 
     * @param loggingStatus The logging status to be set.
     */
    void setLoggingStatus(ELoggingStatus loggingStatus) {
        this->loggingStatus = loggingStatus;
    }

    /**
     * @brief Get the logging status.
     * 
     * @return ELoggingStatus The logging status.
     */
    ELoggingStatus getLoggingStatus() {
        return this->loggingStatus;
    }
private:

    /**
     * Enum representing the logging status of the camera.
     */
    ELoggingStatus loggingStatus;
};

class Subscriber {
public:
    // virtual void handleMessage(const string& message) const = 0;
    virtual void handleLogging(const ELoggingStatus loggingStatus) = 0;
};

class Sensor: public Subscriber{
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

    // void handleMessage(const string& message) const override {
    //     cout << this->name << " " << message << endl;
    // }
    void handleLogging(const ELoggingStatus loggingStatus) override {
        this->sensorLogging->setLoggingStatus(loggingStatus);
        cout << this->name << " " << this->sensorLogging->getLoggingStatus() << endl;
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

class Publisher {
public:
    void registerSubscriber(const string& subject, Subscriber* subscriber) {
        subscribers[subject].push_back(subscriber);
    }
    void unregisterSubscriber(const string& subject, Subscriber* subscriber) {
        auto it = subscribers.find(subject);
        if (it != subscribers.end()) {
            auto& subscriberList = it->second;
            subscriberList.erase(remove(subscriberList.begin(), subscriberList.end(), subscriber), subscriberList.end());
        }
    }
    void notifySubscribers(const string& subject, const ELoggingStatus loggingStatus) {
        auto it = subscribers.find(subject);
        if (it != subscribers.end()) {
            for (auto subscriber : it->second) {
                // subscriber->handleMessage(message);
                subscriber->handleLogging(loggingStatus);
            }
        }
    };
private:
    unordered_map<string, vector<Subscriber*>> subscribers;
};


int main() {
    // SensorFactory* camera1SensorFactory = new Camera1SensorFactory(new Camera1PropertyFactory());
    // Sensor* camera1 = camera1SensorFactory->createSensor();
    // cout << camera1->getName() << endl;
    // cout << camera1->getType() << endl;

    // cout << "===========================" << endl;

    // SensorFactory* camera2SensorFactory = new Camera2SensorFactory(new Camera2PropertyFactory());
    // Sensor* camera2 = camera2SensorFactory->createSensor();
    // cout << camera2->getName() << endl;
    // cout << camera2->getType() << endl;
    // return 0;

    // Publisher Subscriber Test
    Publisher publisher;
    Camera1SensorFactory* camera1SensorFactory = new Camera1SensorFactory(new Camera1PropertyFactory());
    Camera2SensorFactory* camera2SensorFactory = new Camera2SensorFactory(new Camera2PropertyFactory());
    Sensor* camera1 = camera1SensorFactory->createSensor();
    Sensor* camera2 = camera2SensorFactory->createSensor();
    cout << "========================" << endl;
    publisher.registerSubscriber("Camera", camera1);
    publisher.registerSubscriber("Camera", camera2);
    publisher.notifySubscribers("Camera", ELoggingStatus::END);
    return 0;
}
