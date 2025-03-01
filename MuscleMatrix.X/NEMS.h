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
void ADCValuesCb(void);
void DelayUs(uint32_t us);


float ConvertADCToVoltage(uint16_t adcResult);


extern volatile bool adcValueReady; 


#ifdef	__cplusplus
}
#endif

#endif	/* NEMS_H */

