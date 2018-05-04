################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/port/ethernetif.c \
../lwip/port/sys_arch.c 

OBJS += \
./lwip/port/ethernetif.o \
./lwip/port/sys_arch.o 

C_DEPS += \
./lwip/port/ethernetif.d \
./lwip/port/sys_arch.d 


# Each subdirectory must supply rules for building sources it contributes
lwip/port/%.o: ../lwip/port/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -DFRDM_K64F -DUSE_RTOS=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DFREEDOM -DPRINTF_ADVANCED_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\board" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\source" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\drivers" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\CMSIS" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\utilities" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\startup" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\contrib\apps\udpecho" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\port\arch" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\port" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\lwip\priv" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\lwip\prot" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\lwip" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\netif\ppp\polarssl" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\netif\ppp" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\netif" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\posix\sys" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include\posix" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\freertos\include" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\freertos\portable" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\src\include" -I"C:\p2\0502_demo_apps_lwip_lwip_udpecho_freertos\lwip\contrib\apps" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


