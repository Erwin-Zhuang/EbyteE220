/*
 * EbyteE220.c
 *
 *  Created on: Mar 19, 2024
 *      Author: zibo_
 */
#include "stm32f1xx_hal.h"
#include "EbyteE220.h"



/************************************
  * @brief Config_E220
  * @param UART_HandleTypeDef *huart,UART_HandleTypeDef *huartdebug,E220_InitTypeDefine* E220_InitStruct
  * @retval HAL_StatusTypeDefine
************************************/
HAL_StatusTypeDef E220_Config(UART_HandleTypeDef *huart,E220_InitTypeDefine* E220_InitStruct)
{
	uint8_t COMMAND[11]={0xc0,0x00,0x08};
	uint8_t RECEIVE[11]={0};

	COMMAND[3]=E220_InitStruct->ADD_H;
	COMMAND[4]=E220_InitStruct->ADD_L;
	COMMAND[5]=(E220_InitStruct->UART_BPS<<5)
				|(E220_InitStruct->UART_CHECK<<3)
				|(E220_InitStruct->AIR_BPS);
	COMMAND[6]=(E220_InitStruct->DATA_LENGTH<<6)
				|(E220_InitStruct->RSSI_NOISE<<5)
				|(E220_InitStruct->TRAMSMIT_POWER);
	COMMAND[7]=E220_InitStruct->CHANNEL;
	COMMAND[8]=(E220_InitStruct->RSSI_BYTE<<7)
				|(E220_InitStruct->TRANSMIT_MODE<<6)
				|(E220_InitStruct->RELAY<<5)
				|(E220_InitStruct->LBT<<4)
				|(E220_InitStruct->WOR_CYCLE);
	COMMAND[9]=E220_InitStruct->CRYPTH;
	COMMAND[10]=E220_InitStruct->CRYPTL;

	HAL_Delay(100);

	HAL_UART_Transmit(huart, COMMAND, 11, 0xff);
	HAL_UART_Receive(huart, RECEIVE, 11, 0Xff);

	if(RECEIVE[0]==0XC1) return HAL_OK;
	return HAL_ERROR;
}
