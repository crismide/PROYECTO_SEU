#ifndef __hardware_management_h__

#define __hardware_management_h__
#include "main.h"
#include <stdint.h>

extern ADC_HandleTypeDef hadc1;

//exported functions
void check_threshold();
void set_lights();
void check_alarm();

#endif