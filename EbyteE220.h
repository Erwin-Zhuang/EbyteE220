/*
 * EbyteE220.h
 *
 *  Created on: Mar 19, 2024
 *      Author: zibo_
 */

#ifndef INC_EBYTEE220_H_
#define INC_EBYTEE220_H_

#include "stm32f1xx_hal_def.h"


#define ADD_H_DEFAULT 				0X12
#define ADD_L_DEFAULT 				0X34

#define UART_BPS_1200 				0x00
#define UART_BPS_2400 				0x01
#define UART_BPS_4800 				0x02
#define UART_BPS_9600 				0x03
#define UART_BPS_19200 				0x04
#define UART_BPS_38400 				0x05
#define UART_BPS_57600 				0x06
#define UART_BPS_115200 			0x07

#define UART_CHECK_8N1 				0x00
#define UART_CHECK_801 				0x01
#define UART_CHECK_8E1 				0x02

#define AIR_BPS_2K4 				0X02
#define AIR_BPS_4K8 				0X03
#define AIR_BPS_9K6 				0X04
#define AIR_BPS_19K2 				0X05
#define AIR_BPS_38K4 				0X06
#define AIR_BPS_62K5 				0X07

#define DATA_LENGTH_200				0X00
#define DATA_LENGTH_128				0X01
#define DATA_LENGTH_64				0X02
#define DATA_LENGTH_32				0X03

#define RSSI_NOISE_DISABLE			0x00
#define RSSI_NOISE_ENABLE			0x01

#define TRANSMIT_POWER_22DBM		0X00
#define TRANSMIT_POWER_17DBM		0X01
#define TRANSMIT_POWER_13DBM		0X10
#define TRANSMIT_POWER_10DBM		0X11

#define RSSI_BYTE_DISABLE			0x00
#define RSSI_BYTE_ENABLE			0x01

#define TRANSMIT_MODE_TRANSPARTNT	0X00
#define TRANSMIT_MODE_POINT			0x01

#define RELAY_DISABLE				0X00
#define RELAY_ENABLE				0X01

#define LBT_DISABLE					0X00
#define LBT_ENABLE					0X01

#define WOR_CYCLE_500MS				0X00
#define WOR_CYCLE_1000MS			0X01
#define WOR_CYCLE_1500MS			0X02
#define WOR_CYCLE_2000MS			0X03
#define WOR_CYCLE_2500MS			0X04
#define WOR_CYCLE_3000MS			0X05
#define WOR_CYCLE_3500MS			0X06
#define WOR_CYCLE_4000MS			0X07

#define CRYPTH_DEFAULT				0X78
#define CRYPTL_DEFAULT				0X9A

typedef struct{
	uint8_t ADD_H;
	uint8_t ADD_L;

	uint8_t UART_BPS;
	uint8_t UART_CHECK;
	uint8_t AIR_BPS;
	//EG0
	uint8_t DATA_LENGTH;
	uint8_t RSSI_NOISE;
	uint8_t TRAMSMIT_POWER;
	//REG1
	uint8_t CHANNEL;
	//REG2
	uint8_t RSSI_BYTE;
	uint8_t TRANSMIT_MODE;
	uint8_t RELAY;
	uint8_t LBT;
	uint8_t WOR_CYCLE;
	//REG3
	uint8_t CRYPTH;
	uint8_t CRYPTL;
}E220_InitTypeDefine;

HAL_StatusTypeDef E220_Config(UART_HandleTypeDef *huart,E220_InitTypeDefine* E220_InitStruct);



#endif /* INC_EBYTEE220_H_ */
