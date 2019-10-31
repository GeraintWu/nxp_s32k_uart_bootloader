################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 26
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Generated_Code/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include SDK/platform/devices/S32K118/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/lpit/subdir.mk
-include SDK/platform/drivers/src/lpuart/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include Sources/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
s32k118_uart_bootloader.elf \

EXECUTABLES_QUOTED += \
"s32k118_uart_bootloader.elf" \

EXECUTABLES_OS_FORMAT += \
s32k118_uart_bootloader.elf \

SECONDARY_SIZE += \
s32k118_uart_bootloader.siz \

SECONDARY_SIZE_QUOTED += \
"s32k118_uart_bootloader.siz" \

SECONDARY_SIZE_OS_FORMAT += \
s32k118_uart_bootloader.siz \


# All Target
all: warning-messages explicit-dependencies s32k118_uart_bootloader.elf secondary-outputs

# Tool invocations
s32k118_uart_bootloader.elf: $(OBJS) C:/Workspace/NXP/S32/s32k_uart_boot/s32k118_uart_bootloader/s32k118_uart_bootloader/Project_Settings/Linker_Files/S32K118_25_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #27 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "s32k118_uart_bootloader.elf" "@s32k118_uart_bootloader.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

s32k118_uart_bootloader.siz: $(EXECUTABLES)
	@echo 'Executing target #28 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*/*.d ./*/*/*/*/*/*.d ./*/*/*/*/*/*/*.d  ./*/*.o ./*/*/*/*.o ./*/*/*/*/*/*.o ./*/*/*/*/*/*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

