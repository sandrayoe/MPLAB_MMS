/* 
 * File:   electrode.h
 * Author: lars.magnusson
 *
 * Created on March 15, 2022, 4:46 PM
 */

#ifndef ELECTRODE_H
#define	ELECTRODE_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum
{
    STATE_ELECTRODE_TRISTATE,
    STATE_ELECTRODE_POS,
    STATE_ELECTRODE_GND
}STATE_ELECTRODE_T;

// 32 functions where each function handles a single electrode (two processor pins))
// An electrode can be connected to plus, ground or be tri-stated
static inline void Electrode0(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA0  = 1; LATAbits.LATA1  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA0  = 0; LATAbits.LATA1  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA0  = 0; LATAbits.LATA1  = 0; }
}

static inline void Electrode1(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA2  = 1; LATAbits.LATA3  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA2  = 0; LATAbits.LATA3  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA2  = 0; LATAbits.LATA3  = 0; }
}

static inline void Electrode2(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA4  = 1; LATAbits.LATA5  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA4  = 0; LATAbits.LATA5  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA4  = 0; LATAbits.LATA5  = 0; }
}

static inline void Electrode3(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA6  = 1; LATAbits.LATA7  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA6  = 0; LATAbits.LATA7  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA6  = 0; LATAbits.LATA7  = 0; }
}

static inline void Electrode4(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA9  = 1; LATAbits.LATA10 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA9  = 0; LATAbits.LATA10 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA9  = 0; LATAbits.LATA10 = 0; }
}

static inline void Electrode5(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATAbits.LATA14 = 1; LATAbits.LATA15 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATAbits.LATA14 = 0; LATAbits.LATA15 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATAbits.LATA14 = 0; LATAbits.LATA15 = 0; }
}

static inline void Electrode6(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATBbits.LATB8  = 1; LATBbits.LATB9  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATBbits.LATB8  = 0; LATBbits.LATB9  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATBbits.LATB8  = 0; LATBbits.LATB9  = 0; }
}

static inline void Electrode7(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATBbits.LATB10 = 1; LATBbits.LATB11 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATBbits.LATB10 = 0; LATBbits.LATB11 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATBbits.LATB10 = 0; LATBbits.LATB11 = 0; }
}

static inline void Electrode8(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATBbits.LATB12 = 1; LATBbits.LATB13 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATBbits.LATB12 = 0; LATBbits.LATB13 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATBbits.LATB12 = 0; LATBbits.LATB13 = 0; }
}

static inline void Electrode9(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATBbits.LATB14 = 1; LATBbits.LATB15 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATBbits.LATB14 = 0; LATBbits.LATB15 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATBbits.LATB14 = 0; LATBbits.LATB15 = 0; }
}

static inline void Electrode10(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATCbits.LATC1  = 1; LATCbits.LATC2  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATCbits.LATC1  = 0; LATCbits.LATC2  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATCbits.LATC1  = 0; LATCbits.LATC2  = 0; }
}

static inline void Electrode11(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATCbits.LATC3  = 1; LATCbits.LATC4  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATCbits.LATC3  = 0; LATCbits.LATC4  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATCbits.LATC3  = 0; LATCbits.LATC4  = 0; }
}

static inline void Electrode12(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD0  = 1; LATDbits.LATD1  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD0  = 0; LATDbits.LATD1  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD0  = 0; LATDbits.LATD1  = 0; }
}

static inline void Electrode13(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD2  = 1; LATDbits.LATD3  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD2  = 0; LATDbits.LATD3  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD2  = 0; LATDbits.LATD3  = 0; }
}

static inline void Electrode14(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD4  = 1; LATDbits.LATD5  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD4  = 0; LATDbits.LATD5  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD4  = 0; LATDbits.LATD5  = 0; }
}

static inline void Electrode15(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD6  = 1; LATDbits.LATD7  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD6  = 0; LATDbits.LATD7  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD6  = 0; LATDbits.LATD7  = 0; }
}

static inline void Electrode16(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD8  = 1; LATDbits.LATD9  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD8  = 0; LATDbits.LATD9  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD8  = 0; LATDbits.LATD9  = 0; }
}

static inline void Electrode17(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD10 = 1; LATDbits.LATD11 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD10 = 0; LATDbits.LATD11 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD10 = 0; LATDbits.LATD11 = 0; }
}

static inline void Electrode18(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD12 = 1; LATDbits.LATD13 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD12 = 0; LATDbits.LATD13 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD12 = 0; LATDbits.LATD13 = 0; }
}

static inline void Electrode19(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATDbits.LATD14 = 1; LATDbits.LATD15 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATDbits.LATD14 = 0; LATDbits.LATD15 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATDbits.LATD14 = 0; LATDbits.LATD15 = 0; }
}

static inline void Electrode20(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATEbits.LATE0  = 1; LATEbits.LATE1  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATEbits.LATE0  = 0; LATEbits.LATE1  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATEbits.LATE0  = 0; LATEbits.LATE1  = 0; }
}

static inline void Electrode21(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATEbits.LATE2  = 1; LATEbits.LATE3  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATEbits.LATE2  = 0; LATEbits.LATE3  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATEbits.LATE2  = 0; LATEbits.LATE3  = 0; }
}

static inline void Electrode22(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATEbits.LATE4  = 1; LATEbits.LATE5  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATEbits.LATE4  = 0; LATEbits.LATE5  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATEbits.LATE4  = 0; LATEbits.LATE5  = 0; }
}

static inline void Electrode23(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATEbits.LATE6  = 1; LATEbits.LATE7  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATEbits.LATE6  = 0; LATEbits.LATE7  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATEbits.LATE6  = 0; LATEbits.LATE7  = 0; }
}

static inline void Electrode24(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATEbits.LATE8  = 1; LATEbits.LATE9  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATEbits.LATE8  = 0; LATEbits.LATE9  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATEbits.LATE8  = 0; LATEbits.LATE9  = 0; }
}

static inline void Electrode25(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATFbits.LATF7  = 1; LATFbits.LATF8  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATFbits.LATF7  = 0; LATFbits.LATF8  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATFbits.LATF7  = 0; LATFbits.LATF8  = 0; }
}

static inline void Electrode26(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATFbits.LATF12 = 1; LATFbits.LATF13 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATFbits.LATF12 = 0; LATFbits.LATF13 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATFbits.LATF12 = 0; LATFbits.LATF13 = 0; }
}

static inline void Electrode27(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATGbits.LATG0  = 1; LATGbits.LATG1  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATGbits.LATG0  = 0; LATGbits.LATG1  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATGbits.LATG0  = 0; LATGbits.LATG1  = 0; }
}

static inline void Electrode28(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATGbits.LATG6  = 1; LATGbits.LATG7  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATGbits.LATG6  = 0; LATGbits.LATG7  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATGbits.LATG6  = 0; LATGbits.LATG7  = 0; }
}

static inline void Electrode29(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATGbits.LATG8  = 1; LATGbits.LATG9  = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATGbits.LATG8  = 0; LATGbits.LATG9  = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATGbits.LATG8  = 0; LATGbits.LATG9  = 0; }
}

static inline void Electrode30(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATGbits.LATG12 = 1; LATGbits.LATG13 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATGbits.LATG12 = 0; LATGbits.LATG13 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATGbits.LATG12 = 0; LATGbits.LATG13 = 0; }
}

static inline void Electrode31(STATE_ELECTRODE_T state)
{
    if(state == STATE_ELECTRODE_POS)             { LATGbits.LATG14 = 1; LATGbits.LATG15 = 0; }
    else if(state == STATE_ELECTRODE_GND)        { LATGbits.LATG14 = 0; LATGbits.LATG15 = 1; }
    else /* state == STATE_ELECTRODE_TRISTATE */ { LATGbits.LATG14 = 0; LATGbits.LATG15 = 0; }
}




#ifdef	__cplusplus
}
#endif

#endif	/* ELECTRODE_H */

