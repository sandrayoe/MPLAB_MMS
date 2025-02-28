/* 
 * File:   imu.h
 * Author: lars.magnusson
 *
 * Created on June 16, 2022, 12:36 PM
 */

#ifndef IMU_H
#define	IMU_H

#ifdef	__cplusplus
extern "C" {
#endif

uint8_t LIS331DLHTRGetWhoAmI(void);
uint16_t LIS331DLHTRGetOutX(void);
uint16_t LIS331DLHTRGetOutY(void);
uint16_t LIS331DLHTRGetOutZ(void);
uint8_t LIS331DLHTRGetMode(void);
void LIS331DLHTRSetMode(void);
void LIS331DLHTRPowerOff(void);



#ifdef	__cplusplus
}
#endif

#endif	/* IMU_H */

