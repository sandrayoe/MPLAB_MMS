#include "mcc_generated_files/i2c1.h"
#include "imu.h"

#define LIS331DLHTR_I2C_DEVICE_ADDRESS              0x18
#define LIS331DLHTR_REG_WHO_AM_I                    0x0F
#define LIS331DLHTR_REG_OUT_X_L                     0xA8
#define LIS331DLHTR_REG_OUT_X_H                     0x29

uint8_t LIS331DLHTRGetWhoAmI(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t readAddr = LIS331DLHTR_REG_WHO_AM_I;
    uint8_t WhoAmI = 0;
    I2C1_MESSAGE_STATUS i2cStatus;
    int ret;

    deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(&readAddr, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(&WhoAmI, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    
    return WhoAmI;
}

uint8_t LIS331DLHTRGetMode(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr = 0x20;
    uint8_t value = 0;
    I2C1_MESSAGE_STATUS i2cStatus;
    
    I2C1_MasterWrite(&regAddr, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(&value, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;
    
    return value;
}

void LIS331DLHTRSetMode(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr = 0x20;
    uint8_t buf[2] = { 0x20, 0x37 };
    I2C1_MESSAGE_STATUS i2cStatus;
    
    I2C1_MasterWrite(buf, 2, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;
}

void LIS331DLHTRPowerOff(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr = 0x20;
    uint8_t buf[2] = { 0x20, 0x07 };
    I2C1_MESSAGE_STATUS i2cStatus;
    
    I2C1_MasterWrite(buf, 2, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;
}

uint16_t LIS331DLHTRGetOutX(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr1 = 0x28;
    uint8_t regAddr2 = 0x29;
    uint8_t retVal[2];
    uint16_t accVal;
    I2C1_MESSAGE_STATUS i2cStatus;
    int ret;

    deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(&regAddr1, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(retVal, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterWrite(&regAddr2, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead((retVal + 1), 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    
    accVal = (uint16_t)retVal[1];
    accVal <<= 8;
    accVal += (uint16_t)retVal[0];
    //accVal = (uint16_t)retVal;
    return accVal;
}

uint16_t LIS331DLHTRGetOutY(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr1 = 0x2A;
    uint8_t regAddr2 = 0x2B;
    uint8_t retVal[2];
    uint16_t accVal;
    I2C1_MESSAGE_STATUS i2cStatus;
    int ret;

    deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(&regAddr1, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(retVal, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterWrite(&regAddr2, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead((retVal + 1), 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    
    accVal = (uint16_t)retVal[1];
    accVal <<= 8;
    accVal += (uint16_t)retVal[0];
    //accVal = (uint16_t)retVal;
    return accVal;
}

uint16_t LIS331DLHTRGetOutZ(void)
{
    uint8_t deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;
    uint8_t regAddr1 = 0x2C;
    uint8_t regAddr2 = 0x2D;
    uint8_t retVal[2];
    uint16_t accVal;
    I2C1_MESSAGE_STATUS i2cStatus;
    int ret;

    deviceAddress = LIS331DLHTR_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(&regAddr1, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(retVal, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterWrite(&regAddr2, 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead((retVal + 1), 1, deviceAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    
    accVal = (uint16_t)retVal[1];
    accVal <<= 8;
    accVal += (uint16_t)retVal[0];
    //accVal = (uint16_t)retVal;
    return accVal;
}
