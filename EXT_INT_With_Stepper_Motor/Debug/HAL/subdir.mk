################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad.c \
../HAL/LCD.c \
../HAL/LCD_CFG.c \
../HAL/Stepper_Motor.c 

OBJS += \
./HAL/Keypad.o \
./HAL/LCD.o \
./HAL/LCD_CFG.o \
./HAL/Stepper_Motor.o 

C_DEPS += \
./HAL/Keypad.d \
./HAL/LCD.d \
./HAL/LCD_CFG.d \
./HAL/Stepper_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\STD" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\HAL" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


