/* 
 * File:   NEMS.h
 * Author: lars.magnusson
 *
 * Created on March 14, 2022, 7:01 AM
 */

#ifndef NEMS_H
#define	NEMS_H

#ifdef	__cplusplus
extern "C" {
#endif

void NEMSInit(void);
void SendBatteryData(uint16_t adcResult, float voltage, float percent);
void ADCValuesCb(void);
void DelayUs(uint32_t us);


float ConvertADCToVoltage(uint16_t adcResult);
float CalculateBattPercent(float voltage);


extern volatile bool adcValueReady; 
static volatile bool userMeasureRequested; 



#ifdef	__cplusplus
}
#endif

#endif	/* NEMS_H */

