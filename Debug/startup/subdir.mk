################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../startup/startup_stm32l031xx.asm 

OBJS += \
./startup/startup_stm32l031xx.o 

ASM_DEPS += \
./startup/startup_stm32l031xx.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -DSTM32L031xx=#STM32L031xx -DUSE_HAL_DRIVER=#USE_HAL_DRIVER -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Inc" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\CMSIS\Include" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\STM32L0xx_HAL_Driver\Inc" -I"C:\Users\GRPA\Documents\WORK\C_Projects\IR_Control\Drivers\CMSIS\Device\ST\STM32L0xx\Include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


