#include <gtest/gtest.h>
#include "CameraPropertyFactory.cpp"

TEST(CameraPropertyFactoryTest, CreateSensorReturnTypeTest) {
    SensorPropertyFactory* propertyFactory = new SensorPropertyFactory();
    Camera1SensorFactory cameraFactory(propertyFactory);
    Sensor* sensor = cameraFactory.createSensor();
    ASSERT_TRUE(dynamic_cast<Camera1*>(sensor) != nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}