#include <hardware_management.h>
#include <stdbool.h>

uint8_t pot_value;
uint8_t sensor_mode;
uint8_t sensor_value;
uint8_t threshold_value;
bool danger_zone = false;

//FIRST LEVEL FUNCTIONS

void check_threshold(int pulsations){
    pot_value = read_pot_value(); //the possible values range is [0-4095]
    sensor_mode = check_sensor_mode(pulsations);
    threshold_value = check_threshold_value(pot_value,sensor_mode);
    set_lights_threshold(threshold_value);
}

void set_lights(int pulsations){
    sensor_mode = check_sensor_mode(pulsations);
    sensor_value = check_sensor_value(sensor_mode);
    set_lights_sensor(sendor_value, sensor_mode);
}

void check_alarm(){
    sensor_mode = check_sensor_mode(pulsations);
    sensor_value = check_sensor_value(sensor_mode);
    threshold_value = check_threshold_value(pot_value,sensor_mode);
    if (threshold_value>sensor_value){
        put_alarm();
        if(pulsacion_b1()){
            stop_alarm();
            {int sec; for(sec=0; sec<100000000; sec++)}
        }
        check_alarm();
    }
}

//SECOND LEVEL FUNCTIONS

uint8_t read_pot_value(){
    uint32_t valueAD;
	ADC_ChannelConfTypeDef sConfig;
		sConfig.Channel = ADC_CHANNEL_4;
		sConfig.Rank = 1;
		sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		break;
	}
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 10000);
	valueAD=HAL_ADC_GetValue(&hadc1);
	return valueAD;
}

uint8_t check_sensor_mode(int pulsations){
    if((pulsations%2)==0){ return 0; } //default mode -> light mode
    else return 1; //temperature mode
}

uint8_t check_threshold_value(uint8_t pot_value, uint8_t sensor_mode){
    swtich(sensor_mode){
        //light mode
        case 0:
            break;

        //temperature mode
        case 1:
            break;
    }
}

uint8_t check_sensor_value(){
    
}

void set_lights_threshold(uint8_t threshold_value){

}


void set_lights_sensor(uint8_t sensor_value, uint8_t sensor_mode){

}

