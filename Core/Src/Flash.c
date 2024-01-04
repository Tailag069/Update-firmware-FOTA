/*
 * Flash.c
 *
 *  Created on: Dec 3, 2023
 *      Author: LENOVO
 */


#include "Flash.h"
#include "stm32f4xx.h"


void Flash_Erase(uint32_t sector){
	HAL_FLASH_Unlock();
	FLASH_EraseInitTypeDef flash;
	flash.VoltageRange = VOLTAGE_RANGE_3;
	flash.NbSectors = 1;
	flash.Sector = sector;
	flash.TypeErase = FLASH_TYPEERASE_SECTORS;
	uint32_t err=0;
	HAL_FLASHEx_Erase(&flash,&err);
	HAL_FLASH_Lock();
}


void Flash_Write(uint32_t address, int value){
	HAL_FLASH_Unlock();
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,  address, value);
	HAL_FLASH_Lock();
}

int Flash_Read(uint32_t address){
	return *(__IO uint32_t*)address;
}
