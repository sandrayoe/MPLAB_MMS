#include "mcc_generated_files/i2c1.h"
#include "eeprom.h"

#define EEPROM_PAGE_SIZE                    16
#define EEPROM_NO_OF_USED_PAGES             16
#define EEPROM_I2C_DEVICE_ADDRESS           0x50
//#define DATA_LENGTH                         1

/*typedef struct FT24C08A_DATA_T
{
    uint16_t memPos;
    uint16_t memSize;
}FT24C08A_DATA_T;

FT24C08A_DATA_T ft24c08aOrganization[FT24C08A_DATA_POS_NO_OF_DATA] =
{
    // Address 0x50
    { .memPos =  0              ,    .memSize = DATA_LENGTH },
    { .memPos =  1 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  2 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  3 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  4 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  5 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  6 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  7 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  8 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos =  9 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos = 10 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos = 11 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos = 12 * DATA_LENGTH,    .memSize = DATA_LENGTH },
    { .memPos = 12 * DATA_LENGTH,    .memSize = DATA_LENGTH }
};*/

typedef union
{
    uint8_t b[EEPROM_NO_OF_USED_PAGES][EEPROM_PAGE_SIZE];            //  64 * 16 bytes = 1024 bytes

    struct
    {
        uint8_t amplitude;          // 1 byte
        uint8_t amplitude2;         // 1 byte
        uint8_t frequency;          // 1 byte
        uint8_t phaseDuration;      // 1 byte
        uint8_t symmetryFactor;     // 1 byte
        uint8_t onTime;             // 1 byte
        uint8_t offTime;            // 1 byte
        uint8_t contractions;       // 1 byte
        uint8_t rampUp;             // 1 byte
        uint8_t rampDown;           // 1 byte
        uint8_t channel1;           // 1 byte
        uint8_t channel2;           // 1 byte
        uint8_t channel3;           // 1 byte
        uint8_t channel4;           // 1 byte
        uint8_t filler[242];        // 242 bytes

    }data;
}FT24C08A_EEPROM_MIRROR_T;

FT24C08A_EEPROM_MIRROR_T eepromMirror;

static int ReadAllEEPROM(void)
{
    uint8_t deviceAndPageAddress;
    uint8_t readAddr = 0;
    int ret;

    deviceAndPageAddress = EEPROM_I2C_DEVICE_ADDRESS;

    // Just read the first 16 pages
    for(uint8_t pageNo = 0; pageNo < EEPROM_NO_OF_USED_PAGES; pageNo++)
    {
        I2C1_MESSAGE_STATUS i2cStatus;

        I2C1_MasterWrite(&readAddr, 1, deviceAndPageAddress, &i2cStatus);

        while(i2cStatus == I2C1_MESSAGE_PENDING)
            ;
            
/*        if(i2cStatus == I2C1_MESSAGE_COMPLETE)
        {
            ret = true;
        }
        else
        {
            ret = false;
            break;
        }*/

        I2C1_MasterRead(eepromMirror.b[pageNo], EEPROM_PAGE_SIZE, deviceAndPageAddress, &i2cStatus);

        while(i2cStatus == I2C1_MESSAGE_PENDING)
            ;
            
        if(i2cStatus == I2C1_MESSAGE_COMPLETE)
        {
            ret = true;
        }
        else
        {
            ret = false;
            break;
        }

        // Go to next page
        readAddr += EEPROM_PAGE_SIZE;
    }

    return ret;
}

void FT24C08AInit(void)
{
    ReadAllEEPROM();
}

bool FT24C08AWriteData(uint8_t* data, uint8_t noOfBytes, uint8_t startAddr)
{
    bool ret;
    uint8_t buf[EEPROM_PAGE_SIZE + 1];
    uint16_t deviceAndPageAddress;
    uint16_t noOfBytesLeftToWrite;

    deviceAndPageAddress = EEPROM_I2C_DEVICE_ADDRESS;
    noOfBytesLeftToWrite = noOfBytes;
    buf[0] = startAddr;
    
    if(startAddr + noOfBytes < EEPROM_PAGE_SIZE * EEPROM_NO_OF_USED_PAGES)
    {
        while(noOfBytesLeftToWrite > 0)
        {
            I2C1_MESSAGE_STATUS i2cStatus;

            uint8_t noOfBytesToWrite;

            if(noOfBytesLeftToWrite > EEPROM_PAGE_SIZE)
            {
                noOfBytesToWrite = EEPROM_PAGE_SIZE;
                noOfBytesLeftToWrite -= EEPROM_PAGE_SIZE;
            }
            else
            {
                noOfBytesToWrite = noOfBytesLeftToWrite;
                noOfBytesLeftToWrite = 0;
            }

            for(uint8_t i = 1; i <= noOfBytesToWrite; i++)
                buf[i] = *(data + i - 1);

            I2C1_MasterWrite(buf, noOfBytesToWrite + 1, deviceAndPageAddress, &i2cStatus);

            while(i2cStatus == I2C1_MESSAGE_PENDING)
                ;
            
            if(i2cStatus == I2C1_MESSAGE_COMPLETE)
            {
                ret = true;
            }
            else
            {
                ret = false;
                break;
            }
        }
    }
    else
    {
        ret = false;
    }
    
    // It seems there must be a delay before the EEPROM can be read
    //ReadAllEEPROM();
    
    return ret;
}

// Write the whole program (14 bytes). A page is 32 bytes, so the whole program can be written at once
int BR24T32WriteProgram(uint8_t* data)
{
    uint8_t deviceAndPageAddress;
    uint8_t buf[16];
    int ret;
    I2C1_MESSAGE_STATUS i2cStatus;
    
    buf[0] = 0x00;
    buf[1] = 0x00;
    
    for(uint8_t i = 0; i <= 14; i++)
        buf[i + 2] = *(data + i);
    
    deviceAndPageAddress = EEPROM_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(buf, 16, deviceAndPageAddress, &i2cStatus);

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
    
    return ret;
}

uint8_t* BR24T32ReadProgram(void)
{
    uint8_t deviceAndPageAddress;
    uint8_t readAddr[2] = { 0x00, 0x00 };
    int ret;
    I2C1_MESSAGE_STATUS i2cStatus;

    deviceAndPageAddress = EEPROM_I2C_DEVICE_ADDRESS;

    I2C1_MasterWrite(readAddr, 2, deviceAndPageAddress, &i2cStatus);

    while(i2cStatus == I2C1_MESSAGE_PENDING)
        ;

    I2C1_MasterRead(eepromMirror.b[0], 14, deviceAndPageAddress, &i2cStatus);

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

    return (uint8_t*)(eepromMirror.b);
}

uint8_t* FT24C08AGetProgram(void)
{
    ReadAllEEPROM();
    return (uint8_t*)(eepromMirror.b);
}