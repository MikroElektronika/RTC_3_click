/*
    __rtc3_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__rtc3_driver.h"
#include "__rtc3_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __RTC3_DRV_I2C__
static uint8_t _slaveAddress;
#endif

// Register address
const uint8_t _RTC3_I2C_ADDRESS                                          = 0x68;

// Register address
const uint8_t _RTC3_REG_TIME_SEC                                         = 0x00;
const uint8_t _RTC3_REG_TIME_MIN                                         = 0x01;
const uint8_t _RTC3_REG_TIME_HOUR                                        = 0x02;
const uint8_t _RTC3_REG_TIME_DAY_OF_THE_WEEK                             = 0x03;
const uint8_t _RTC3_REG_TIME_DATE_DAY                                    = 0x04;
const uint8_t _RTC3_REG_TIME_DATE_MONTH                                  = 0x05;
const uint8_t _RTC3_REG_TIME_DATE_YEAR                                   = 0x06;
const uint8_t _RTC3_REG_CONFIG1                                          = 0x07;
const uint8_t _RTC3_REG_TRICKLE_CHARGE2                                  = 0x08;
const uint8_t _RTC3_REG_CONFIG2                                          = 0x09;
const uint8_t _RTC3_REG_SF_KEY1                                          = 0x20;
const uint8_t _RTC3_REG_SF_KEY2                                          = 0x21;
const uint8_t _RTC3_REG_SFR                                              = 0x22;

// Configuration bits
const uint8_t _RTC3_ENABLE_COUNTING                                      = 0x7F;
const uint8_t _RTC3_DISABLE_COUNTING                                     = 0x80;
const uint8_t _RTC3_CONFIG1_INITIAL                                      = 0x80;
const uint8_t _RTC3_TCH2_OPEN                                            = 0x00;
const uint8_t _RTC3_TCH2_CLOSED                                          = 0x20;
const uint8_t _RTC3_TCFE_OPEN                                            = 0x00;
const uint8_t _RTC3_TCFE_CLOSED                                          = 0x20;
const uint8_t _RTC3_FTF_NORMAL_512_HZ                                    = 0x00;
const uint8_t _RTC3_FTF_1_HZ                                             = 0x01;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RTC3_DRV_SPI__

void rtc3_spiDriverInit(T_RTC3_P gpioObj, T_RTC3_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RTC3_DRV_I2C__

void rtc3_i2cDriverInit(T_RTC3_P gpioObj, T_RTC3_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RTC3_DRV_UART__

void rtc3_uartDriverInit(T_RTC3_P gpioObj, T_RTC3_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */



/* Generic read byte of data function */
uint8_t rtc3_readByte( uint8_t regAddress )
{
    uint8_t rBuffer[ 1 ];
    uint8_t wBuffer[ 1 ];

    wBuffer[ 0 ] = regAddress;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 2, END_MODE_STOP );

    return rBuffer[ 0 ];
}

/* Generic write byte of data function */
void rtc3_writeByte( uint8_t regAddress, uint8_t writeData )
{
    uint8_t wBuffer[ 2 ];

    wBuffer[ 0 ] = regAddress;
    wBuffer[ 1 ] = writeData;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 2, END_MODE_STOP );
}

/* Enable counting function */
void rtc3_enableCounting()
{
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_SEC );

    temp &= 0x7F;

    rtc3_writeByte( _rtc3_REG_TIME_SEC, temp );
}

/* Disable counting function */
void rtc3_disableCounting()
{
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_SEC );

    temp |= 0x80;

    rtc3_writeByte( _RTC3_REG_TIME_SEC, temp );
}

/* Get seconds function */
uint8_t rtc3_getTimeSeconds()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_SEC );

    ones = temp & 0x0F;

    tens = ( temp & 0x70 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set seconds function */
void rtc3_setTimeSeconds( uint8_t seconds )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    seconds %= 60;

    ones = seconds % 10;

    tens = ( seconds / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_SEC, temp );
}

/* Get minutes function */
uint8_t rtc3_getTimeMinutes()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_MIN );

    ones = temp & 0x0F;

    tens = ( temp & 0x70 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set minutes function */
void rtc3_setTimeMinutes( uint8_t minutes )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    minutes %= 60;

    ones = minutes % 10;

    tens = ( minutes / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_MIN, temp );
}

/* Get hours function */
uint8_t rtc3_getTimeHours()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_HOUR );

    ones = temp & 0x0F;

    tens = ( temp & 0x30 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set hours function */
void rtc3_setTimeHours( uint8_t hours )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    hours %= 24;

    ones = hours % 10;

    tens = ( hours / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_HOUR, temp );
}

/* Get day of the week function */
uint8_t rtc3_getDayOfTheWeek()
{
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_DAY_OF_THE_WEEK );

    return temp;
}

/* Set day of the week function */
void rtc3_setDayOfTheWeek( uint8_t wDay )
{
    wDay %= 8;

    if ( wDay == 0 )
    {
        wDay = 1;
    }
    rtc3_writeByte( _RTC3_REG_TIME_DAY_OF_THE_WEEK, wDay );
}

/* Get day function */
uint8_t rtc3_getDateDay()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_DATE_DAY );

    ones = temp & 0x0F;

    tens = ( temp & 0x30 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set day function */
void rtc3_setDateDay( uint8_t dateDay )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    dateDay %= 32;

    if ( dateDay == 0 )
    {
        dateDay = 1;
    }

    ones = dateDay % 10;

    tens = ( dateDay / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_DATE_DAY, temp );
}

/* Get month function */
uint8_t rtc3_getDateMonth()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_DATE_MONTH );

    ones = temp & 0x0F;

    tens = ( temp & 0x10 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set month function */
void rtc3_setDateMonth( uint8_t dateMonth )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    dateMonth %= 13;

    if ( dateMonth == 0 )
    {
        dateMonth = 1;
    }

    ones = dateMonth % 10;

    tens = ( dateMonth / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_DATE_MONTH, temp );
}

/* Get year function */
uint8_t rtc3_getDateYear()
{
    uint8_t ones;
    uint8_t tens;
    uint8_t result;
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TIME_DATE_YEAR );

    ones = temp & 0x0F;

    tens = ( temp & 0xF0 ) >> 4;

    result = ( 10 * tens ) + ones;

    return result;
}

/* Set year function */
void rtc3_setDateYear( uint16_t dateYear )
{
    uint8_t ones;
    uint8_t tens;
    uint8_t temp;

    ones = 0x00;
    tens = 0x00;

    dateYear %= 100;

    ones = dateYear % 10;

    tens = ( dateYear / 10 ) << 4;

    temp = tens | ones;

    rtc3_writeByte( _RTC3_REG_TIME_DATE_YEAR, temp );
}

/* Set time hours, minutes and seconds function */
void rtc3_setTime( uint8_t timeHours, uint8_t timeMinutes, uint8_t timeSeconds )
{
    rtc3_setTimeHours( timeHours );
    rtc3_setTimeMinutes( timeMinutes );
    rtc3_setTimeSeconds( timeSeconds );
}

/* Get time hours, minutes and seconds function */
void rtc3_getTime( uint8_t *timeHours, uint8_t *timeMinutes, uint8_t *timeSeconds )
{
    *timeHours = rtc3_getTimeHours();
    *timeMinutes = rtc3_getTimeMinutes();
    *timeSeconds = rtc3_getTimeSeconds();
}

/* Set date hours, minutes and seconds function */
void rtc3_setDate( uint8_t dayOfTheWeek, uint8_t dateDay, uint8_t dateMonth, uint16_t dateYear )
{
    rtc3_setDayOfTheWeek( dayOfTheWeek );
    rtc3_setDateDay( dateDay );
    rtc3_setDateMonth( dateMonth );
    rtc3_setDateYear( dateYear );
}

/* Get time hours, minutes and seconds function */
void rtc3_getDate( uint8_t *dayOfTheWeek, uint8_t *dateDay, uint8_t *dateMonth, uint16_t *dateYear )
{
    *dayOfTheWeek = rtc3_getDayOfTheWeek();
    *dateDay = rtc3_getDateDay();
    *dateMonth = rtc3_getDateMonth();
    *dateYear = rtc3_getDateYear();
}

/* Set calibration function */
void rtc3_setCalibration( uint8_t calSign, uint8_t calNumber )
{
    uint8_t temp;
    
    temp = _RTC3_CONFIG1_INITIAL;
    
    temp |= calSign << 5;
    temp |= calNumber;
    
    rtc3_writeByte( _RTC3_REG_CONFIG1, temp );
}

/* Set trickle charge control function */
void rtc3_setTrickleCharge( uint8_t tch2 )
{
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_TRICKLE_CHARGE2 );

    if ( tch2 == 0 )
    {
        temp |= _RTC3_TCH2_OPEN;
    }

    if ( tch2 == 1 )
    {
        temp |= _RTC3_TCH2_CLOSED;
    }

    rtc3_writeByte( _RTC3_REG_TRICKLE_CHARGE2, temp );
}

/* Set trickle charge bypass control function */
void rtc3_setTrickleChargeBypass( uint8_t tcfe )
{
    uint8_t temp;

    temp = rtc3_readByte( _RTC3_REG_CONFIG2 );

    if ( tcfe == 0 )
    {
        temp |= _RTC3_TCFE_OPEN;
    }

    if ( tcfe == 1 )
    {
        temp |= _RTC3_TCFE_CLOSED;
    }

    rtc3_writeByte( _RTC3_REG_CONFIG2, temp );
}

/* Set special function key byte 1 function */
void rtc3_setSpecialFunctionKey1( uint8_t sfkey1 )
{
    rtc3_writeByte( _RTC3_REG_SF_KEY1, sfkey1 );
}

/* Set special function key byte 2 function */
void rtc3_setSpecialFunctionKey2( uint8_t sfkey2 )
{
    rtc3_writeByte( _RTC3_REG_SF_KEY2, sfkey2 );
}

/* Set frequency calibration control function */
void rtc3_setFrequencyCalibration( uint8_t ftf )
{
    if ( ftf == 0 )
    {
        rtc3_writeByte( _RTC3_REG_SFR, _RTC3_FTF_NORMAL_512_HZ);
    }

    if ( ftf == 1 )
    {
        rtc3_writeByte( _RTC3_REG_SFR, _RTC3_FTF_1_HZ);
    }
}

/* Get state of interrupt pin function */
uint8_t rtc3_getInterrupt()
{
    return hal_gpio_intGet();
}



/* -------------------------------------------------------------------------- */
/*
  __rtc3_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */