#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/tmr3.h"       // For LED-handling during battery charging
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/i2c1.h"
#include "mcc_generated_files/pin_manager.h"

// To get a PWM-signal
//#include "mcc_generated_files/oc1.h"
//#include "mcc_generated_files/tmr3.h"

#include "common.h"
#include "NEMS.h"

#include "math.h"

#define REF_VOLTAGE               3.3
#define ADC_MAX                   1023
#define MIN_VOLTAGE               2.75
#define MAX_VOLTAGE               4.2

#define FOSC                      32000000UL  // 32 MHz clock
#define FCY                       (FOSC / 2)  // Instruction cycle frequency for XC16


volatile bool adcValueReady = false;

void DelayUs(uint32_t us)
{
    // FOSC 32 MHz and FCY 16 MHz
    uint32_t cycles = (FCY / 1000000) * us; // Convert microseconds to cycles // 32 MHz clock, 1 ms = 32,000 cycles
    __delay32(cycles); 
}

void TMR3Cb(void)
{
    //PutConstString("TMR3\r\n");
    //ADC1_SoftwareTriggerEnable(); 
    
    // Start ADC Sampling (If ASAM = 0)
    AD1CON1bits.SAMP = 1;
    
    // Delay for sampling (if needed)
    DelayUs(10); 
  
    // Stop sampling and start conversion
    AD1CON1bits.SAMP = 0;
    
    userMeasureRequested = true;;
}

// Callback function used when there are set number of ADconversions ready
void ADCValuesCb(void)
{
    //PutConstString("ADC Int\r\n");
    //ADC1_ConversionResultGet(ADCBuffer);
    ADC1_InterruptFlagClear();
    adcValueReady = true;
}

// Convert the raw ADC value to the battery voltage
float ConvertADCToVoltage(uint16_t adcResult)
{
    float voltage = ((float)adcResult / ADC_MAX) * REF_VOLTAGE; // 1023 is the max ADC value for a 10-bit ADC
   
    return voltage;
}

// Calculate the battery percentage
float CalculateBattPercent(float voltage)
{
    // Ensure voltage stays within bounds
    if (voltage < MIN_VOLTAGE)
        voltage = MIN_VOLTAGE;
    else if (voltage > MAX_VOLTAGE)
        voltage = MAX_VOLTAGE;

    // Calculate the percentage
    float percent = ((voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100.0;

    return percent;
}

void SendBatteryData(uint16_t adcResult, float voltage, float percent)
{
    PutConstString("ADC:");
    int8_t buffer[10];
    itoaU16(adcResult, buffer);
    PutString((uint8_t*)buffer);
    
    PutConstString(", BAT:");
    int16_t intPart = (int16_t)percent;
    int16_t fracPart = (int16_t)((percent - intPart) * 100);
    
    itoaU16(intPart, buffer);
    PutString((uint8_t*)buffer);
    PutConstString(".");
    
    if (fracPart < 10) PutConstString("0"); // Ensure two decimal digits
    itoaU16(fracPart, buffer);
    PutString((uint8_t*)buffer);
    PutConstString("%\r\n");
}

void NEMSInit(void)
{
    TMR3_SetInterruptHandler(&TMR3Cb);
    ADC1_SetInterruptHandler(&ADCValuesCb);
    
    ADC1_InterruptEnable();
    ADC1_ChannelSelect(channel_AN0);
    ADC1_SoftwareTriggerEnable();
    
    adcValueReady = false;
    userMeasureRequested = false; 
    
    TMR3_Start();
}



