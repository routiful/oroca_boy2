/*
 * boot.h
 *
 *  Created on: 2017. 11. 23.
 *      Author: opus
 */

#ifndef BOOT_H_
#define BOOT_H_


#ifdef __cplusplus
 extern "C" {
#endif


#define _BOOT_VER_STR               "OROCABOY2 BOOTLOADER V180208R1"
#define _BOOT_VER_NUM               {1, 0, 0}

typedef enum
{
  BOOT_LOADER = 0, BOOT_DBGCLI, BOOT_JUMP_APP
} boot_mode_t;

void bootInit(void);
void bootProcess(void);
boot_mode_t bootCheckMode(void);


#ifdef __cplusplus
 }
#endif


#endif /* BOOT_H_ */