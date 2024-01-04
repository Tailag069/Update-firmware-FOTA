/*
 * Flash.h
 *
 *  Created on: Dec 3, 2023
 *      Author: LENOVO
 */
#ifndef INC_FLASH_H_
#define INC_FLASH_H_
#include <stdint.h>

void Flash_Erase(uint32_t sector);

void Flash_Write(uint32_t address, int value);

int Flash_Read(uint32_t address);

#endif /* INC_FLASH_H_ */
