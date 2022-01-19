################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 04-APP/subdir.mk
-include 03-HAL/motor/subdir.mk
-include 03-HAL/TEMP/subdir.mk
-include 03-HAL/LCD/subdir.mk
-include 03-HAL/KEYPAD/subdir.mk
-include 02-MCAL/TIMER/subdir.mk
-include 02-MCAL/PWM/subdir.mk
-include 02-MCAL/DIO/subdir.mk
-include 02-MCAL/ADC/subdir.mk
-include 01-LIB/DET/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Thermostat.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Thermostat.elf secondary-outputs

# Tool invocations
Thermostat.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Thermostat.map -mmcu=atmega16 -o "Thermostat.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Thermostat.lss: Thermostat.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Thermostat.elf  >"Thermostat.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Thermostat.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Thermostat.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Thermostat.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
