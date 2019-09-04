################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
uart_transmiter.lss \

FLASH_IMAGE += \
uart_transmiter.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: uart_transmiter.elf secondary-outputs

# Tool invocations
uart_transmiter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,uart_transmiter.map -mmcu=atmega32 -o "uart_transmiter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

uart_transmiter.lss: uart_transmiter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S uart_transmiter.elf  >"uart_transmiter.lss"
	@echo 'Finished building: $@'
	@echo ' '

uart_transmiter.hex: uart_transmiter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex uart_transmiter.elf  "uart_transmiter.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: uart_transmiter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 uart_transmiter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) uart_transmiter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
