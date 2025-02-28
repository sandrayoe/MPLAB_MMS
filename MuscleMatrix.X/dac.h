/* 
 * File:   dac.h
 * Author: lars.magnusson
 *
 * Created on March 25, 2022, 9:49 AM
 */

#ifndef DAC_H
#define	DAC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DAC_MAX_CURRENT_MILLI_AMPERE            120

void DACInit(void);
bool DACSetValue(uint8_t current);
bool DACSetValueTest(uint8_t val);


#ifdef	__cplusplus
}
#endif

#endif	/* DAC_H */

