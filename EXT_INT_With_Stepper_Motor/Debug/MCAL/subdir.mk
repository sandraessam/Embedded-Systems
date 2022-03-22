################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/DIO.c \
../MCAL/DIO_CFG.c \
../MCAL/EXT_INT.c \
../MCAL/SPI.c \
../MCAL/TIMER.c \
../MCAL/TWI.c \
../MCAL/UART.c \
../MCAL/WDG.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/DIO.o \
./MCAL/DIO_CFG.o \
./MCAL/EXT_INT.o \
./MCAL/SPI.o \
./MCAL/TIMER.o \
./MCAL/TWI.o \
./MCAL/UART.o \
./MCAL/WDG.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/DIO.d \
./MCAL/DIO_CFG.d \
./MCAL/EXT_INT.d \
./MCAL/SPI.d \
./MCAL/TIMER.d \
./MCAL/TWI.d \
./MCAL/UART.d \
./MCAL/WDG.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\STD" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\HAL" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\Simple_Embedded\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


