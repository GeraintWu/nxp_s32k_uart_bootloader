################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/comm.c" \
"../Sources/fsl_flash_driver_c90tfs.c" \
"../Sources/lpit_user_if.c" \
"../Sources/main.c" \
"../Sources/mem_man.c" \

C_SRCS += \
../Sources/comm.c \
../Sources/fsl_flash_driver_c90tfs.c \
../Sources/lpit_user_if.c \
../Sources/main.c \
../Sources/mem_man.c \

OBJS_OS_FORMAT += \
./Sources/comm.o \
./Sources/fsl_flash_driver_c90tfs.o \
./Sources/lpit_user_if.o \
./Sources/main.o \
./Sources/mem_man.o \

C_DEPS_QUOTED += \
"./Sources/comm.d" \
"./Sources/fsl_flash_driver_c90tfs.d" \
"./Sources/lpit_user_if.d" \
"./Sources/main.d" \
"./Sources/mem_man.d" \

OBJS += \
./Sources/comm.o \
./Sources/fsl_flash_driver_c90tfs.o \
./Sources/lpit_user_if.o \
./Sources/main.o \
./Sources/mem_man.o \

OBJS_QUOTED += \
"./Sources/comm.o" \
"./Sources/fsl_flash_driver_c90tfs.o" \
"./Sources/lpit_user_if.o" \
"./Sources/main.o" \
"./Sources/mem_man.o" \

C_DEPS += \
./Sources/comm.d \
./Sources/fsl_flash_driver_c90tfs.d \
./Sources/lpit_user_if.d \
./Sources/main.d \
./Sources/mem_man.d \


# Each subdirectory must supply rules for building sources it contributes
Sources/comm.o: ../Sources/comm.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/comm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/comm.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/fsl_flash_driver_c90tfs.o: ../Sources/fsl_flash_driver_c90tfs.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/fsl_flash_driver_c90tfs.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/fsl_flash_driver_c90tfs.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lpit_user_if.o: ../Sources/lpit_user_if.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/lpit_user_if.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/lpit_user_if.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mem_man.o: ../Sources/mem_man.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/mem_man.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/mem_man.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


