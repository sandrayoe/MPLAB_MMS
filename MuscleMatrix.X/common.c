#include <string.h>
#include "stdint.h"

#include "mcc_generated_files/uart2.h"
#include "common.h"

void reverse(int8_t s[])
{
    int8_t c, i, j;
    
    for(i = 0, j = strlen((const char *)s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoaU16(uint16_t n, int8_t s[])
{
    uint8_t i = 0;
    
    do
    {
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    
    s[i] = '\0';
    reverse(s);
}

void itoaU32(uint32_t n, int8_t s[])
{
    uint8_t i = 0;
    
    do
    {
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    
    s[i] = '\0';
    reverse(s);
}

void PutString(uint8_t* str)
{
    uint8_t index = 0;
    
    while(str[index])
        UART2_Write(str[index++]);
}

void PutConstString(char* str)
{
    uint8_t index = 0;
    
    while(str[index])
        UART2_Write(str[index++]);
}
