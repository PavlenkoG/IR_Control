################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32l0xx_hal_msp.c \
../Src/stm32l0xx_it.c \
../Src/system_stm32l0xx.c 

OBJS += \
./Src/main.o \
./Src/stm32l0xx_hal_msp.o \
./Src/stm32l0xx_it.o \
./Src/system_stm32l0xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32l0xx_hal_msp.d \
./Src/stm32l0xx_it.d \
./Src/system_stm32l0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32L031xx=#STM32L031xx -DUSE_HAL_DRIVER -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Inc" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\CMSIS\Include" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\STM32L0xx_HAL_Driver\Inc" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\CMSIS\Device\ST\STM32L0xx\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


