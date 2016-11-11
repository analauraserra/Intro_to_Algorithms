################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RCA.cpp \
../src/RandomizedContractionAlgorithm.cpp 

OBJS += \
./src/RCA.o \
./src/RandomizedContractionAlgorithm.o 

CPP_DEPS += \
./src/RCA.d \
./src/RandomizedContractionAlgorithm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GNU_EXPERIMENTAL_CXX0X__ -I/usr/include/c++/4.7 -I/usr/include/c++/4.7/backward -I/usr/include/x86_64-linux-gnu -I/usr/include/x86_64-linux-gnu/c++/4.7 -I/usr/lib/gcc/x86_64-linux-gnu/4.7/include -I/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


