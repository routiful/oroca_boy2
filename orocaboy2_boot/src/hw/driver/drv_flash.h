/*
 *  drv_flash.h
 *
 *  Created on: Feb 08, 2018
 *      Author: opus
 */

#ifndef DRV_FLASH_H
#define DRV_FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif

#include "hw_def.h"

bool drvFlashInit(void);

err_code_t drvFlashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
err_code_t drvFlashRead(uint32_t addr, uint8_t *p_data, uint32_t length);
err_code_t drvFlashErase(uint32_t addr, uint32_t length);

#ifdef __cplusplus
}
#endif


#endif /* DRV_FLASH_H */