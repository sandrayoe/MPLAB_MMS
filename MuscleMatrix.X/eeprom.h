/* 
 * File:   eeprom.h
 * Author: lars.magnusson
 *
 * Created on March 15, 2022, 4:52 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

/*typedef enum
{
    FT24C08A_DATA_POS_AMPLITUDE = 0,
    FT24C08A_DATA_POS_AMPLITUDE_2,
    FT24C08A_DATA_POS_FREQUENCY,
    FT24C08A_DATA_POS_PHASE_DURATION,
    FT24C08A_DATA_POS_SYMMETRY_FACTOR,
    FT24C08A_DATA_POS_ON_TIME,
    FT24C08A_DATA_POS_OFF_TIME,
    FT24C08A_DATA_POS_NO_OF_CONTRACTIONS,
    FT24C08A_DATA_POS_RAMP_UP_TIME,
    FT24C08A_DATA_POS_RAMP_DOWN_TIME,
    FT24C08A_DATA_POS_CHANNEL1,
    FT24C08A_DATA_POS_CHANNEL2,
    FT24C08A_DATA_POS_CHANNEL3,
    FT24C08A_DATA_POS_CHANNEL4,
    FT24C08A_DATA_POS_NO_OF_DATA
}FT24C08A_DATA_POS_T; 
*/

void FT24C08AInit(void);
bool FT24C08AWriteData(uint8_t* data, uint8_t noOfBytes, uint8_t startAddr);
uint8_t* FT24C08AGetProgram(void);

int BR24T32WriteProgram(uint8_t* data);
uint8_t* BR24T32ReadProgram(void);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

