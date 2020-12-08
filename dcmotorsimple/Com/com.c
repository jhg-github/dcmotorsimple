/*
 * com.c
 *
 *  Created on: Jul 31, 2020
 *      Author: javi
 */

#include "com.h"
#include "usart.h"


void com_Test_SendBuffer( uint8_t * const buffer, const uint16_t size_bytes ){
	HAL_UART_Transmit(&huart2, buffer, size_bytes, 5000);
}
