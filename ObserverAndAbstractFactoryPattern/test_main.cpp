#include <gtest/gtest.h>
#include "main.cpp"
// Include the necessary headers for your classes

// Define a fixture for your tests
class CameraTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create the sensor factories and property factories
        camera1SensorFactory = new Camera1SensorFactory(new Camera1PropertyFactory());
        camera2SensorFactory = new Camera2SensorFactory(new Camera2PropertyFactory());

        // Create the sensors
        camera1 = camera1SensorFactory->createSensor();
        camera2 = camera2SensorFactory->createSensor();

        // Register the sensors as subscribers to the Camera subject
        publisher.registerSubscriber("Camera", camera1);
        publisher.registerSubscriber("Camera", camera2);
    }

    void TearDown() override {
        // Unregister the sensors from the Camera subject
        publisher.unregisterSubscriber("Camera", camera1);
        publisher.unregisterSubscriber("Camera", camera2);

        // Delete the sensors and factories
        delete camera1;
        delete camera2;
        delete camera1SensorFactory;
        delete camera2SensorFactory;
    }

    // Declare the necessary objects for your tests
    Publisher publisher;
    Camera1SensorFactory* camera1SensorFactory;
    Camera2SensorFactory* camera2SensorFactory;
    Sensor* camera1;
    Sensor* camera2;
};

// Define your tests
TEST_F(CameraTest, TestLoggingStatus) {
    // Call the notifySubscribers function with the desired logging status
    publisher.notifySubscribers("Camera", ELoggingStatus::START);

    // Check the logging status of the sensors
    EXPECT_EQ(camera1->getSensorLogging()->getLoggingStatus(), ELoggingStatus::START);
    EXPECT_EQ(camera2->getSensorLogging()->getLoggingStatus(), ELoggingStatus::START);

    // Call the notifySubscribers function with a different logging status
    publisher.notifySubscribers("Camera", ELoggingStatus::ERROR);

    // Check the logging status of the sensors again
    EXPECT_EQ(camera1->getSensorLogging()->getLoggingStatus(), ELoggingStatus::ERROR);
    EXPECT_EQ(camera2->getSensorLogging()->getLoggingStatus(), ELoggingStatus::ERROR);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}