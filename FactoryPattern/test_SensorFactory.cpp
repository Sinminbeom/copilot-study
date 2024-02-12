#include <gtest/gtest.h>
#include "SensorFactory.cpp"
#include "LidarFactory.cpp"
#include "CameraFactory.cpp"
#include "GnssFactory.cpp"



TEST(SensorFactoryTest, OrderSensorReturnsLidar) {
    SensorFactory* factory = new LidarFactory();
    Sensor* sensor = factory->orderSensor();
    EXPECT_EQ(typeid(*sensor), typeid(Lidar));
    delete sensor;
    delete factory;
}

TEST(SensorFactoryTest, OrderSensorReturnsCamera) {
    SensorFactory* factory = new CameraFactory();
    Sensor* sensor = factory->orderSensor();
    EXPECT_EQ(typeid(*sensor), typeid(Camera));
    delete sensor;
    delete factory;
}

TEST(SensorFactoryTest, OrderSensorReturnsGnss) {
    SensorFactory* factory = new GnssFactory();
    Sensor* sensor = factory->orderSensor();
    EXPECT_EQ(typeid(*sensor), typeid(Gnss));
    delete sensor;
    delete factory;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}