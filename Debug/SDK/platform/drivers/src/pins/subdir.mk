################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../SDK/platform/drivers/src/pins/pins_driver.c" \
"../SDK/platform/drivers/src/pins/pins_port_hw_access.c" \

C_SRCS += \
../SDK/platform/drivers/src/pins/pins_driver.c \
../SDK/platform/drivers/src/pins/pins_port_hw_access.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/pins/pins_driver.o \
./SDK/platform/drivers/src/pins/pins_port_hw_access.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/pins/pins_driver.d" \
"./SDK/platform/drivers/src/pins/pins_port_hw_access.d" \

OBJS += \
./SDK/platform/drivers/src/pins/pins_driver.o \
./SDK/platform/drivers/src/pins/pins_port_hw_access.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/pins/pins_driver.o" \
"./SDK/platform/drivers/src/pins/pins_port_hw_access.o" \

C_DEPS += \
./SDK/platform/drivers/src/pins/pins_driver.d \
./SDK/platform/drivers/src/pins/pins_port_hw_access.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/pins/pins_driver.o: ../SDK/platform/drivers/src/pins/pins_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/pins/pins_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/pins/pins_driver.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/pins/pins_port_hw_access.o: ../SDK/platform/drivers/src/pins/pins_port_hw_access.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/pins/pins_port_hw_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/pins/pins_port_hw_access.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


