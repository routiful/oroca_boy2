/*
 * drv_uart.h
 *
 *  Created on: Feb 08, 2018
 *      Author: opus
 */

#ifndef DRV_UART_H_
#define DRV_UART_H_



#ifdef __cplusplus
 extern "C" {
#endif


#include "hw_def.h"

#include "bsp.h"
#include "qbuffer.h"


#define DRV_UART_CH_MAX   _HW_DEF_UART_CH_MAX

typedef struct
{
  // 공용 코드

  struct
  {
    bool     init;
    bool     open;
    uint8_t  channel;
    uint32_t baud;
    uint32_t tx_cnt;
    uint32_t rx_cnt;
    uint32_t tx_err_cnt;
    uint32_t rx_err_cnt;
    uint32_t tx_retry_cnt;
    uint32_t rx_retry_cnt;
  } core;


  struct
  {
    UART_HandleTypeDef h_uart;
    USART_TypeDef     *h_uart_inst;
    qbuffer_node_t     uart_buffer;
    uint8_t            uart_rx_buf[2048];
    uint8_t            uart_tx_buf[2048];
    DMA_HandleTypeDef  hdma_rx;
    DMA_HandleTypeDef  hdma_tx;

    bool               dma_enable;
    bool               vcp_enable;

    bool               tx_dma_enable;
    bool               tx_done;
    void               (*txDoneISR)(void);
  } hw;

} drv_uart_t;



bool      drvUartInit(void);
bool      drvUartOpen(uint8_t channel, uint32_t baud, uint32_t option);
bool      drvUartClose(uint8_t channel);
void      drvUartSetTxDoneISR(uint8_t channel, void (*func)(void));
bool      drvUartIsEnable(uint8_t channel);
bool      drvUartFlush(uint8_t channel);
uint32_t  drvUartIsAvailable(uint8_t channel);
int32_t   drvUartWrite(uint8_t channel, uint8_t *p_data, uint32_t length);
uint8_t   drvUartRead(uint8_t channel);
uint32_t  drvUartGetTxErrCount(uint8_t channel);
uint32_t  drvUartGetTxCount(uint8_t channel);
uint32_t  drvUartGetTxRetryCount(uint8_t channel);
uint32_t  drvUartGetRxCount(uint8_t channel);

#endif /* _USE_HW_UART */

#ifdef __cplusplus
}
#endif