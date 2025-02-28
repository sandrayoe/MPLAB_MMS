/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GA010
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/* 
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
*/
#include <stdio.h>  // For sprintf

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/tmr3.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/i2c1.h"

#include "NEMS.h"
#include "common.h"

bool IsUARTReadyToTransmit(void)
{
    return (U1STA & 0x0200) == 0; // Check TXBF flag (TX buffer full) - this may vary for your microcontroller
}

int main(void)
{
    SYSTEM_Initialize();
    
    NEMSInit();
    
    LED1_IO_RF0_SetLow();      // LED on
    for (volatile uint32_t i = 0; i < 128000; i++); 
    LED1_IO_RF0_SetHigh();      // LED off
    
    while(1)
    {
        // Check if TMR3 requested a measurement
        if (userMeasureRequested)
        {
            userMeasureRequested = false;
            ADC1_InterruptFlagClear(); 
            ADC1_SoftwareTriggerEnable();
        }
       
        // Check if ADC result is ready
        if (adcValueReady)
        {
                    //PutConstString("adcValueReady is TRUE\r\n"); // Debugging print
                    
                    adcValueReady = false;
                    // Read ADC result and process it
                    //uint16_t adcResult = ADC1BUF0;
                    PutConstString("ADC:");
                    uint16_t adcResult = ADC1BUF0; 
                    
                    int8_t buffer[10];
                    itoaU16(adcResult, buffer);
                    
                    while (!IsUARTReadyToTransmit()) {
                        DelayUs(5000); // or an appropriate delay for your system
                    }
                    
                    PutString((uint8_t*)buffer);
                    PutConstString("\r\n");
                    
                    //float batteryVoltage = ConvertADCToVoltage(adcResult);
                    //float batteryPercent = CalculateBattPercent(batteryVoltage);

                // Send data via UART
                //SendBatteryData(adcResult, batteryVoltage, batteryPercent);  
                
        }
           
        

    }
    return 1;
}

/**
 End of File
*/

