################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../SDK/platform/devices/S32K118/startup/system_S32K118.c" \

C_SRCS += \
../SDK/platform/devices/S32K118/startup/system_S32K118.c \

OBJS_OS_FORMAT += \
./SDK/platform/devices/S32K118/startup/system_S32K118.o \

C_DEPS_QUOTED += \
"./SDK/platform/devices/S32K118/startup/system_S32K118.d" \

OBJS += \
./SDK/platform/devices/S32K118/startup/system_S32K118.o \

OBJS_QUOTED += \
"./SDK/platform/devices/S32K118/startup/system_S32K118.o" \

C_DEPS += \
./SDK/platform/devices/S32K118/startup/system_S32K118.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/S32K118/startup/system_S32K118.o: ../SDK/platform/devices/S32K118/startup/system_S32K118.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/devices/S32K118/startup/system_S32K118.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/devices/S32K118/startup/system_S32K118.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


