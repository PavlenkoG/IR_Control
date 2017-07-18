/*
 * IR_control.h
 *
 *  Created on: 18.07.2017
 *      Author: grpa
 */

#ifndef INC_IR_CONTROL_H_
#define INC_IR_CONTROL_H_



#endif /* INC_IR_CONTROL_H_ */

#include <stm32l0xx_hal.h>

#define SPACE_INTERVAL_US           19200

#define ONE_LEVEL_INTERVAL_NUM      2
#define ZERO_LEVEL_INTERVAL_NUM     1
#define START_LEVEL_INTERVAL_NUM    4
#define PAUSE_LEVEL_INTERVAL_NUM    1

#define START_TIME_CORRECTION_US    10
#define END_TIME_CORRECTION_US      10

#define COMMAND_LENGTH              7
#define ADDR_LENGTH                 13

#define DEVICE_ADDRESS              0x1E3A

typedef struct {
    uint32_t SendIrCommand;
    uint32_t SendIrAddr;
} IR_PacketTypeDef;

typedef enum {
    START_SYMBOL    = 0x01U,
    ONE_SYMBOL      = 0x02U,
    ZERO_SYMBOL     = 0x03U
} IR_SymbolTypeDef;


int SendIrData (uint32_t *DataToSend, uint32_t Length);
int SendIrSymbol (IR_SymbolTypeDef Symbol);
uint32_t CreasteIrPacket (IR_PacketTypeDef IR_Packet);
