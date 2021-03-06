#ifndef __BC95_H__
#define	__BC95_H__
#include "main.h"
#include "stm32f1xx_hal.h"
#include "usart.h"
#include "tools.h"
#include "App.h"


#define BC95_CMD_DELAY      50             // cmmand send
#define BC95_TIMEOUT        2
#define BC95_LOOP_NUMBER    10
#define OK                  1
#define ERROR               0

#define RX_LEN              600
#define SERVER_CMD_LEN      44              //need (length * 2)

#define _CLEAR_RX_TYPEDEF  memset(&bc95_recv, 0, sizeof(bc95_recvTypeDef));

/*
|---------------------------------- 
|   bc95 status typedef
|----------------------------------
*/
typedef struct{
    uint8_t     rx_buf[RX_LEN];     /*!< bc95 command return data       */
    uint32_t    rx_size;            /*!< bc95 rx size                   */
    uint8_t     rx_flag:1;          /*!< bc95 rx flag                   */
    uint8_t     server_cmd_flag:1;  /*!< have a server command          */
    uint8_t     server_cmd[RX_LEN]; /*!< server command                 */
}bc95_recvTypeDef;  

extern bc95_recvTypeDef   bc95_recv;

typedef struct{
    uint8_t     imsi[16];           /*!< imsi                     */
    uint8_t     imei[16];           /*!< imei                     */
    uint8_t     iccid[20];          /*!< iccid                    */
    uint8_t     csq;                /*!< csq                      */
    uint16_t    snr;                /*!< nsr                      */
    uint8_t     profile_status;     /*!< profile status           */
}bc95_statusTypeDef;

extern bc95_statusTypeDef bc95_status;

void bc95_init();
uint8_t bc95_send_command(uint8_t *cmd, uint8_t *ack, uint8_t timeout, uint8_t loop);
void bc95_open_recv();
uint8_t bc95_check_ack(uint8_t *ack);
void bc95_recv_idle_callback(UART_HandleTypeDef *huart);
uint8_t bc95_get_imsi();
uint8_t bc95_get_imei();
uint8_t bc95_get_iccid();
uint8_t bc95_get_csq();
uint8_t bc95_get_profile_status();
void bc95_reboot();
uint8_t bc95_set_server_ip();
uint8_t bc95_send_coap(uint8_t *ack);
void bc95_read_coap(uint8_t timeout);


#endif