#include "LEDDriver.h"

enum {
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum {
    FIRST_LED = 1,
    LAST_LED = 16
};

static uint16_t * ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}


static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

static bool IsLedOutOfBounds(int ledNumber)
{
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
    return (ledNumber < FIRST_LED || ledNumber > LAST_LED);
}

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}

void LEDDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LEDDriver_Destroy(void)
{
}

void LEDDriver_TurnOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;
    setLedImageBit(ledNumber);
    updateHardware();
}

void LEDDriver_TurnOff(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;
    clearLedImageBit(ledNumber);
    updateHardware();
}

void LEDDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

void LEDDriver_TurnAllOff(void)
{
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

bool LEDDriver_IsOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return false;
    return ledsImage & convertLedNumberToBit(ledNumber);
}

bool LEDDriver_IsOff(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return true;
    return !LEDDriver_IsOn(ledNumber);
}