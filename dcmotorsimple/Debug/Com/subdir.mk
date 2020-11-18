################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Com/com.c 

OBJS += \
./Com/com.o 

C_DEPS += \
./Com/com.d 


# Each subdirectory must supply rules for building sources it contributes
Com/com.o: ../Com/com.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303xE -DUSE_FULL_LL_DRIVER -DDEBUG -c -I/home/javi/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.0/Drivers/STM32F3xx_HAL_Driver/Inc -I/home/javi/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Core/Inc -I/home/javi/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.0/Drivers/CMSIS/Include -I/home/javi/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.0/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Com/com.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

