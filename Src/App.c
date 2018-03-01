#include "App.h"

device_statusTypeDef device_status = {0};
device_errorTypeDef device_error   = {0};

void test(uint8_t* string){
    HAL_UART_Transmit_DMA(&huart1, string, 10);
}