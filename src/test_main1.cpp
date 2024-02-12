#include <gtest/gtest.h>
#include "main1.cpp"

TEST(SensorTest, GetName)
{
    Sensor sensor;
    sensor.setName("Temperature Sensor");
    EXPECT_EQ(sensor.getName(), "Temperature Sensor");
}

TEST(SensorTest, GetType)
{
    Sensor sensor;
    sensor.setType("Temperature");
    EXPECT_EQ(sensor.getType(), "Temperature");
}

TEST(SensorTest, SetName)
{
    Sensor sensor;
    sensor.setName("Pressure Sensor");
    EXPECT_EQ(sensor.getName(), "Pressure Sensor");
}

TEST(SensorTest, SetType)
{
    Sensor sensor;
    sensor.setType("Pressure");
    EXPECT_EQ(sensor.getType(), "Pressure");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}