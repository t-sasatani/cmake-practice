#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "RuntimeErrorStub.h"
#include "RuntimeError.h"

void LEDDriver_Create(uint16_t * address);
void LEDDriver_TurnOn(int ledNumber);
void LEDDriver_TurnOff(int ledNumber);
void LEDDriver_TurnAllOn(void);
void LEDDriver_TurnAllOff(void);
bool LEDDriver_IsOn(int ledNumber);
bool LEDDriver_IsOff(int ledNumber);