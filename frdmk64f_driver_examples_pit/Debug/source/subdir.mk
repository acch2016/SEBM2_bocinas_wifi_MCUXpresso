################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/pit.c \
../source/semihost_hardfault.c 

OBJS += \
./source/pit.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/pit.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -DFRDM_K64F -DCR_INTEGER_PRINTF -DFREEDOM -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\board" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\source" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\drivers" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\CMSIS" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\utilities" -I"C:\p2\SEBM2_bocinas_wifi_MCUXpresso\frdmk64f_driver_examples_pit\startup" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


