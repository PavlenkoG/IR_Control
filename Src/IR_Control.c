/*
 * IR_Control.c
 *
 *  Created on: 18.07.2017
 *      Author: grpa
 */
#include "IR_control.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;
extern uint32_t DataTransfer;

int SendIrData (uint32_t *DataToSend, uint32_t Length)
{
    uint32_t Data;
    Data = *DataToSend;

    SendIrSymbol (START_SYMBOL);
    for (int i = 0; i < Length; i++){

        if (Data & 0x00000001)
        {
            SendIrSymbol(ONE_SYMBOL);
        }
        else{
            SendIrSymbol(ZERO_SYMBOL);
        }
        Data = Data >> 1;
    }
    return 0;
}

int SendIrSymbol (IR_SymbolTypeDef Symbol)
{
    // Start transfer symbol
    switch (Symbol){
    case START_SYMBOL:
        DataTransfer = START_LEVEL_INTERVAL_NUM;
        break;
    case ONE_SYMBOL:
        DataTransfer = ONE_LEVEL_INTERVAL_NUM;
        break;
    case ZERO_SYMBOL:
        DataTransfer = ZERO_LEVEL_INTERVAL_NUM;
        break;
    }

    HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_OC_Start_IT(&htim21, TIM_CHANNEL_1);
    // wait for end transfer of symbol
    while (DataTransfer){

    }
    HAL_TIM_OC_Stop(&htim2, TIM_CHANNEL_2);

    // start transfer separate symbol
    DataTransfer = PAUSE_LEVEL_INTERVAL_NUM;

    while (DataTransfer){

    }
    HAL_TIM_OC_Stop(&htim21, TIM_CHANNEL_2);
    return 0;
}

uint32_t CreasteIrPacket (IR_PacketTypeDef IR_Packet)
{
    uint32_t Packet = 0;
    Packet = IR_Packet.SendIrCommand;
    Packet = Packet | (IR_Packet.SendIrAddr << COMMAND_LENGTH);
    return Packet;
}


