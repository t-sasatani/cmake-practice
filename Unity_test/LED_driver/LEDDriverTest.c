#include "unity_fixture.h"

TEST_GROUP(LEDDriver);

TEST_SETUP(LEDDriver)
{
}

TEST_TEAR_DOWN(LEDDriver)
{
}

TEST(LEDDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xffff;
    LEDDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}