/* 
 * File:   common.h
 * Author: lars.magnusson
 *
 * Created on March 14, 2022, 8:48 AM
 */

#ifndef COMMON_H
#define	COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdint.h"

#define FIRMWARE_VERSION            "V0.30.06"

void reverse(int8_t s[]);
void itoaU16(uint16_t n, int8_t s[]);
void itoaU32(uint32_t n, int8_t s[]);
void PutString(uint8_t* str);
void PutConstString(char* str);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

