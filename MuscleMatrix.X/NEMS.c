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
    // Start ADC Sampling (If ASAM = 0)
    AD1CON1bits.SAMP = 1;
    // Stop sampling and start conversion
    // AD1CON1bits.SAMP = 0;
}

// Callback function used when there are set number of ADconversions ready
void ADCValuesCb(void)
{
    //PutConstString("ADC Int\r\n");
    adcValueReady = true;
}

void NEMSInit(void)
{
    
    TMR3_SetInterruptHandler(&TMR3Cb);
    ADC1_SetInterruptHandler(&ADCValuesCb);
    
    ADC1_ChannelSelect(channel_AN0);
    ADC1_SoftwareTriggerEnable();
    
    adcValueReady = false;

    TMR3_Start();
}



