################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../18125130_Ex02.cpp \
../Ex02_1.cpp \
../Ex02_2.cpp \
../Ex02_3.cpp 

OBJS += \
./18125130_Ex02.o \
./Ex02_1.o \
./Ex02_2.o \
./Ex02_3.o 

CPP_DEPS += \
./18125130_Ex02.d \
./Ex02_1.d \
./Ex02_2.d \
./Ex02_3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


