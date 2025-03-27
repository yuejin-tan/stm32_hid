/*
 * bsp.h
 *
 *  Created on: 2022å¹?6æœ?17æ—?
 *      Author: tyj
 */

#ifndef INC_BSP_H_
#define INC_BSP_H_

#include "stdint.h"

void bsp_init_scd(void);

#define USART_REV_BUFF_SIZE 4
#define USART_SEND_BUFF_SIZE 8
extern uint8_t scd_rev_2buffer[2][USART_REV_BUFF_SIZE];
extern uint8_t scd_send_2buffer[2][USART_SEND_BUFF_SIZE];

#endif /* INC_BSP_H_ */
