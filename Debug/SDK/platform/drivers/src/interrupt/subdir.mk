################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../SDK/platform/drivers/src/interrupt/interrupt_manager.c" \

C_SRCS += \
../SDK/platform/drivers/src/interrupt/interrupt_manager.c \

OBJS_OS_FORMAT += \
./SDK/platform/drivers/src/interrupt/interrupt_manager.o \

C_DEPS_QUOTED += \
"./SDK/platform/drivers/src/interrupt/interrupt_manager.d" \

OBJS += \
./SDK/platform/drivers/src/interrupt/interrupt_manager.o \

OBJS_QUOTED += \
"./SDK/platform/drivers/src/interrupt/interrupt_manager.o" \

C_DEPS += \
./SDK/platform/drivers/src/interrupt/interrupt_manager.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/interrupt/interrupt_manager.o: ../SDK/platform/drivers/src/interrupt/interrupt_manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/interrupt/interrupt_manager.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/drivers/src/interrupt/interrupt_manager.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


