#include "unity_fixture.h"
#include "LEDDriver.h"
#include "RuntimeErrorStub.h"

TEST_GROUP(LEDDriver);

static uint16_t virtualLeds;

TEST_SETUP(LEDDriver)
{
    LEDDriver_Create(&virtualLeds);
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

TEST(LEDDriver, TurnOnLedOne)
{
    LEDDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LEDDriver, TurnOffLedOne)
{
    LEDDriver_TurnOn(1);
    LEDDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LEDDriver, TurnOnMultipleLeds)
{
    LEDDriver_TurnOn(9);
    LEDDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(LEDDriver, TurnOffAnyLed)
{
    LEDDriver_TurnAllOn();
    LEDDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

TEST(LEDDriver, AllOn)
{
    LEDDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(LEDDriver, LedMemoryIsNotReadable)
{
    virtualLeds = 0xffff;
    LEDDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

TEST(LEDDriver, UpperAndLowerBounds)
{
    LEDDriver_TurnOn(1);
    LEDDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

TEST(LEDDriver, OutOfBoundsTurnOffDoesNoHarm)
{
    LEDDriver_TurnAllOn();
    LEDDriver_TurnOff(0);
    LEDDriver_TurnOff(17);
    LEDDriver_TurnOff(3141);
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}


TEST(LEDDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    LEDDriver_TurnOn(-1);
    LEDDriver_TurnOn(0);
    LEDDriver_TurnOn(17);
    LEDDriver_TurnOn(3141);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LEDDriver, OutOfBoundsProduceRuntimeError)
{
    LEDDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

IGNORE_TEST(LEDDriver, OutOfBoundsToDo)
{
    /* This test will not run */
    LEDDriver_TurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}