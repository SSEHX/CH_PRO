#ifndef __APP_H__
#define	__APP_H__
#include "main.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"
#include "bc95.h"

#define QR_CODE_LEN 20

#define SYSTEM_LED_PORT     GPIOA
#define SYSTEM_LED_PIN      GPIO_PIN_15
#define _system_led         HAL_GPIO_TogglePin(SYSTEM_LED_PORT, SYSTEM_LED_PIN)

typedef struct {
    uint8_t     processing_status;
    uint32_t    boot;                   //设备开关机
    uint32_t    arrears_boot;           //停机开关机
    uint32_t    device_registe;         //设备注册状态
    uint32_t    device_mode;            //设备类型
    uint16_t    pure_tds;
    uint16_t    raw_tds;
    uint32_t    time;
    uint32_t    flow;
    uint32_t    rinse;
    uint32_t    filter[10];
    uint32_t    create_water_time_m;
    uint8_t     qr_code[QR_CODE_LEN+1];
}device_statusTypeDef;

extern device_statusTypeDef device_status; 

typedef struct{
    uint8_t     bc95_init_error;
    uint8_t     leakage;                    // leakage flag
    uint8_t     raw_no_water;               // no water flag
    uint8_t     create_water_too_long;
}device_errorTypeDef;

extern device_errorTypeDef device_error;

void test(uint8_t* string);

#endif