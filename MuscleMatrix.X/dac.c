#include "mcc_generated_files/i2c1.h"
#include "dac.h"

#define MCP4728_I2C_DEVICE_ADDRESS                  0x60
#define MCP4728_CMD_GENERAL_CALL_ADDRESS            0x00        /* First byte */
#define MCP4728_GENERAL_CALL_RESET                  0x06        /* Second byte */
#define MCP4728_GENERAL_CALL_WAKEUP                 0x09        /* Second byte */
#define MCP4728_GENERAL_CALL_SW_UPDATE              0x08        /* Second byte */
#define MCP4728_GENERAL_CALL_READ_ADDRESS_BITS      0x0C        /* Second byte */
#define MCP4728_DAC_MAX_VALUE                       4095

#define DAC081C081_I2C_DEVICE_ADDRESS               0x0D
#define DAC081C081_DAC_MAX_VALUE                     255

typedef union
{
    uint8_t u8[2];
    uint16_t u16;
}DAC_VALUE_T;

void DACInit(void)
{
    
}

bool DACSetValue(uint8_t current)
{   
    bool ret;
    DAC_VALUE_T DACValue;
    uint16_t DACVal;
    //uint8_t DACData[8];
    uint8_t DACData[2];
    I2C1_MESSAGE_STATUS i2cStatus;

    if(current <= DAC_MAX_CURRENT_MILLI_AMPERE)
    {
        //DACValue.u16 = (uint16_t)(((uint32_t)current * (uint32_t)MCP4728_DAC_MAX_VALUE) / (uint32_t)DAC_MAX_CURRENT_MILLI_AMPERE);
        DACVal = (uint16_t)(((uint32_t)current * (uint32_t)DAC081C081_DAC_MAX_VALUE) / (uint32_t)DAC_MAX_CURRENT_MILLI_AMPERE);
        DACVal = (uint16_t)((float)DACVal * 1.05);       // It's not possible to get 120 mA. Increase DAC-value by 5 % to get the wanted current
        
        if(DACVal > DAC081C081_DAC_MAX_VALUE)
            DACVal = DAC081C081_DAC_MAX_VALUE;
    }
    else
        //DACValue.u16 = MCP4728_DAC_MAX_VALUE;
        DACVal = DAC081C081_DAC_MAX_VALUE;

    DACVal <<= 4;       // Shift to put the value in bits 4 - 12
    
    //for(uint8_t i = 0; i < 4; i++)
/*    for(uint8_t i = 0; i < 1; i++)
    {
        DACData[i*2] = DACValue.u8[1];
        DACData[i*2+1] = DACValue.u8[0];
    }*/
    DACData[0] = (DACVal >> 8) & 0x0F;
    DACData[1] = DACVal & 0xF0;

    //I2C1_MasterWrite(DACData, sizeof(DACData), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
    I2C1_MasterWrite(DACData, sizeof(DACData), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;
    
    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
        ret = true;
    else
        ret = false;
    
    return ret;
}

bool DACSetValueTest(uint8_t val)
{   
    bool ret;
    I2C1_MESSAGE_STATUS i2cStatus;
    
    if(val == 0)
    {
        //uint8_t data[] = { 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00 };
        //I2C1_MasterWrite(data, sizeof(data), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
        uint8_t data[] = { 0x00, 0x00 };
        I2C1_MasterWrite(data, sizeof(data), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);
    }
    else if(val == 1)
    {
//        uint8_t data[] = { 0x05, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00 };
  //      I2C1_MasterWrite(data, sizeof(data), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
        uint8_t data[] = { 0x04, 0x00 };
        I2C1_MasterWrite(data, sizeof(data), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);
    }
    else if(val == 2)
    {
    //    uint8_t data[] = { 0x09, 0x00, 0x0a, 0x00, 0x0b, 0x00, 0x0c, 0x00 };
      //  I2C1_MasterWrite(data, sizeof(data), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
        uint8_t data[] = { 0x08, 0x00 };
        I2C1_MasterWrite(data, sizeof(data), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);
    }
    else if(val == 3)
    {
//        uint8_t data[] = { 0x0d, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x0f, 0xff };
  //      I2C1_MasterWrite(data, sizeof(data), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
        uint8_t data[] = { 0x0C, 0x00 };
        I2C1_MasterWrite(data, sizeof(data), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);
    }
    else //if(val == 3)
    {
    //    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
      //  I2C1_MasterWrite(data, sizeof(data), MCP4728_I2C_DEVICE_ADDRESS, &i2cStatus);
        uint8_t data[] = { 0x0F, 0xF0 };
        I2C1_MasterWrite(data, sizeof(data), DAC081C081_I2C_DEVICE_ADDRESS, &i2cStatus);
    }

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;
    
    if(i2cStatus == I2C1_MESSAGE_COMPLETE)
        ret = true;
    else
        ret = false;
    
    return ret;
}
