#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "RuntimeErrorStub.h"
#include "RuntimeError.h"

void LEDDriver_Create(uint16_t * address);
void LEDDriver_TurnOn(int ledNumber);
void LEDDriver_TurnOff(int ledNumber);
void LEDDriver_TurnAllOn(void);