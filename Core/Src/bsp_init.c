/*
 * bsp.c
 *
 *  Created on: 2022å¹?6æœ?17æ—?
 *      Author: tyj
 */

#include "bsp_init.h"

#include "scd_inc.h"
#include "main.h"

uint8_t scd_rev_2buffer[2][USART_REV_BUFF_SIZE];
uint8_t scd_send_2buffer[2][USART_SEND_BUFF_SIZE];

void bsp_init_scd()
{
    // uart debug output
    scd_init_1();

    // fill the send buffer
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < USART_SEND_BUFF_SIZE; i++)
        {
            scd_send_2buffer[j][i] = scd_send1Byte(&scd_1);
        }
    }

    // rev 2 buff dma config
    LL_DMA_EnableDoubleBufferMode(DMA1, LL_DMA_STREAM_0);
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_0, LL_USART_DMA_GetRegAddr(USART1, LL_USART_DMA_REG_DATA_RECEIVE));
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_0, (uint32_t)scd_rev_2buffer[0]);
    LL_DMA_SetMemory1Address(DMA1, LL_DMA_STREAM_0, (uint32_t)scd_rev_2buffer[1]);
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_0, USART_REV_BUFF_SIZE);
    LL_DMA_EnableIT_TC(DMA1, LL_DMA_STREAM_0);

    // send 2 buff dma config
    LL_DMA_EnableDoubleBufferMode(DMA1, LL_DMA_STREAM_1);
    LL_DMA_SetPeriphAddress(DMA1, LL_DMA_STREAM_1, LL_USART_DMA_GetRegAddr(USART1, LL_USART_DMA_REG_DATA_TRANSMIT));
    LL_DMA_SetMemoryAddress(DMA1, LL_DMA_STREAM_1, (uint32_t)scd_send_2buffer[0]);
    LL_DMA_SetMemory1Address(DMA1, LL_DMA_STREAM_1, (uint32_t)scd_send_2buffer[1]);
    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_1, USART_SEND_BUFF_SIZE);
    LL_DMA_EnableIT_TC(DMA1, LL_DMA_STREAM_1);

    // enable usart dma trig
    LL_USART_EnableDMAReq_RX(USART1);
    LL_USART_EnableDMAReq_TX(USART1);

    // enable dma stream
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_0);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_1);
    return;
}
