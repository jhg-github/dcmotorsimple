/*
 * com.c
 *
 *  Created on: Jul 31, 2020
 *      Author: javi
 */

#include "com.h"
#include "usart.h"


void com_Test_SendBuffer( uint8_t * const buffer, const uint16_t size_bytes ){
	uint16_t *u16buffer = (uint16_t *)buffer;
	uint16_t i;

	for(i=0;i<size_bytes/2;i++){
		u16buffer[i]=i;
	}

	HAL_UART_Transmit(&huart2, buffer, size_bytes, 5000);

}