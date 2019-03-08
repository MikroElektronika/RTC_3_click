/*
    __rtc3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rtc3_driver.h
@brief    RTC_3 Driver
@mainpage RTC_3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RTC3
@brief      RTC_3 Click Driver
@{

| Global Library Prefix | **RTC3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RTC3_H_
#define _RTC3_H_

/** 
 * @macro T_RTC3_P
 * @brief Driver Abstract type 
 */
#define T_RTC3_P    const uint8_t*

/** @defgroup RTC3_COMPILE Compilation Config */              /** @{ */

//  #define   __RTC3_DRV_SPI__                            /**<     @macro __RTC3_DRV_SPI__  @brief SPI driver selector */
   #define   __RTC3_DRV_I2C__                            /**<     @macro __RTC3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RTC3_DRV_UART__                           /**<     @macro __RTC3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RTC3_VAR Variables */                           /** @{ */

extern const uint8_t _RTC3_I2C_ADDRESS;
extern const uint8_t _RTC3_REG_TIME_SEC;
extern const uint8_t _RTC3_REG_TIME_MIN;
extern const uint8_t _RTC3_REG_TIME_HOUR;
extern const uint8_t _RTC3_REG_TIME_DAY_OF_THE_WEEK;
extern const uint8_t _RTC3_REG_TIME_DATE_DAY;
extern const uint8_t _RTC3_REG_TIME_DATE_MONTH;
extern const uint8_t _RTC3_REG_TIME_DATE_YEAR;
extern const uint8_t _RTC3_REG_CONFIG1;
extern const uint8_t _RTC3_REG_TRICKLE_CHARGE2;
extern const uint8_t _RTC3_REG_CONFIG2;
extern const uint8_t _RTC3_REG_SF_KEY1;
extern const uint8_t _RTC3_REG_SF_KEY2;
extern const uint8_t _RTC3_REG_SFR;
extern const uint8_t _RTC3_ENABLE_COUNTING;
extern const uint8_t _RTC3_DISABLE_COUNTING;

                                                                       /** @} */
/** @defgroup RTC3_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RTC3_INIT Driver Initialization */              /** @{ */

#ifdef   __RTC3_DRV_SPI__
void rtc3_spiDriverInit(T_RTC3_P gpioObj, T_RTC3_P spiObj);
#endif
#ifdef   __RTC3_DRV_I2C__
void rtc3_i2cDriverInit(T_RTC3_P gpioObj, T_RTC3_P i2cObj, uint8_t slave);
#endif
#ifdef   __RTC3_DRV_UART__
void rtc3_uartDriverInit(T_RTC3_P gpioObj, T_RTC3_P uartObj);
#endif


/** @defgroup RTC3_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic read byte of data function
 *
 * @param[in] regAddress                Register address
 *
 * Function read the 8-bit of data from the
 * target 8-bit register address of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_readByte( uint8_t regAddress );

/**
 * @brief Generic write byte of data function
 *
 * @param[in] regAddress                Register address
 *
 * @param[in] writeData                 Byte of data to write
 *
 * Function write the 8-bit of data to the
 * target 8-bit register address of BQ32000 chip on RTC 3 Click.
 */
void rtc3_writeByte( uint8_t regAddress, uint8_t writeData );

/**
 * @brief Enable counting function
 *
 * Function enable counting on RTC 3 Click.
 */
void rtc3_enableCounting();

/**
 * @brief Disable counting function
 *
 * Function disable counting on RTC 3 Click.
 */
void rtc3_disableCounting();

/**
 * @brief Get seconds function
 *
 * @return
 * Time seconds [ 0 sec - 59 sec ]
 *
 * Function gets seconds data from the target register address
 * ( 0x00 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getTimeSeconds();

/**
 * @brief Set seconds function
 *
 * @param[in] seconds                   Time seconds [ 0 sec - 59 sec ]
 *
 * Function sets seconds data to the target register address
 * ( 0x00 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setTimeSeconds( uint8_t seconds );

/**
 * @brief Get minutes function
 *
 * @return
 * Time minutes [ 0 min - 59 min ]
 *
 * Function gets minutes data from the target register address
 * ( 0x01 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getTimeMinutes();

/**
 * @brief Set minutes function
 *
 * @param[in] minutes                   Time minutes [ 0 min - 59 min ]
 *
 * Function sets minutes data to the target register address
 * ( 0x01 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setTimeMinutes( uint8_t minutes );

/**
 * @brief Get hours function
 *
 * @return
 * Time hours [ 0 h - 23 h ]
 *
 * Function gets hours data from the target register address
 * ( 0x02 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getTimeHours();

/**
 * @brief Set hours function
 *
 * @param[in] hours                     Time hours [ 0 h - 23 h ]
 *
 * Function sets hours data to the target register address
 * ( 0x02 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setTimeHours( uint8_t hours );

/**
 * @brief Get day of the week function
 *
 * @return
 * Day of the week [ 1 - 7 ]
 *
 * Function gets day of the week data from tne target register address
 * ( 0x03 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getDayOfTheWeek();

/**
 * @brief Set day of the week function
 *
 * @param[in] wDay                      Day of the week data [ 1 - 7 ]
 * - 1 : Monday;
 * - 2 : Tuesday;
 * - 3 : Wednesday;
 * - 4 : Thursday;
 * - 5 : Friday;
 * - 6 : Saturday;
 * - 7 : Sunday;
 *
 * Function sets day of the week data to the target register address
 * ( 0x03 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setDayOfTheWeek( uint8_t wDay );

/**
 * @brief Get day function
 *
 * @return
 * Day [ 1 - 7 ]
 * - 1 : Monday;
 * - 2 : Tuesday;
 * - 3 : Wednesday;
 * - 4 : Thursday;
 * - 5 : Friday;
 * - 6 : Saturday;
 * - 7 : Sunday;
 *
 * Function gets day data from the target register address
 * ( 0x04 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getDateDay();

/**
 * @brief Set day function
 *
 * @param[in] dateDay                   Date day data [ 1 - 31 ]
 *
 * Function sets day data from the target register address
 * ( 0x04 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setDateDay( uint8_t dateDay );

/**
 * @brief Get month function
 *
 * @return
 * Month [ 1 - 12 ]
 *
 * Function gets month data from the target register address
 * ( 0x05 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getDateMonth();

/**
 * @brief Set month function
 *
 * @param[in] dateMonth                 Date month data [ 1 - 12 ]
 *
 * Function sets month data from the target register address
 * ( 0x05 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setDateMonth( uint8_t dateMonth );

/**
 * @brief Get year function
 *
 * @return
 * Year [ 00 - 99 ]
 *
 * Function gets year data from the target register address
 * ( 0x06 ) of BQ32000 chip on RTC 3 Click.
 */
uint8_t rtc3_getDateYear();

/**
 * @brief Set year function
 *
 * @param[in] dateYear                  Date year data [ 00 - 99 ]
 *
 * Function sets year data from the target register address
 * ( 0x06 ) of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setDateYear( uint16_t dateYear );

/**
 * @brief Set time hours, minutes and seconds function
 *
 * @param[in] timeHours                 Time hours [ 0 h - 23 h ]
 *
 * @param[in] timeMinutes               Time minutes [ 0 min - 59 min ]
 *
 * @param[in] timeSeconds               Time seconds [ 0 sec - 59 sec ]
 *
 * Function sets time: hours, minutes and seconds data to
 * the target register address ( 0x00, 0x01 & 0x02 )
 * of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setTime( uint8_t timeHours, uint8_t timeMinutes, uint8_t timeSeconds );

/**
 * @brief Get time hours, minutes and seconds function
 *
 * @param[out] timeHours                 pointer of time hours [ 0 h - 23 h ]
 *
 * @param[out] timeMinutes               pointer of time minutes [ 0 min - 59 min ]
 *
 * @param[out] timeSeconds               pointer of time seconds [ 0 sec - 59 sec ]
 *
 * Function gets time: hours, minutes and seconds data from
 * the target register address ( 0x00, 0x01 & 0x02 )
 * of BQ32000 chip on RTC 3 Click.
 */
void rtc3_getTime( uint8_t *timeHours, uint8_t *timeMinutes, uint8_t *timeSeconds );

/**
 * @brief Set date hours, minutes and seconds function
 *
 * @param[in] dayOfTheWeek               Date of the week data [ 1 - 7 ]
 *
 * @param[in] dateDay                    Date day data [ 1 - 31 ]
 *
 * @param[in] dateMonth                  Date month data [ 1 - 12 ]
 *
 * @param[in] dateYear                   Date year data [ 0 - 99 ]
 *
 * Function sets date: day of the week, day, month and year data to
 * the target register address ( 0x03, 0x04, 0x05 & 0x06 )
 * of BQ32000 chip on RTC 3 Click.
 */
void rtc3_setDate( uint8_t dayOfTheWeek, uint8_t dateDay, uint8_t dateMonth, uint16_t dateYear );

/**
 * @brief Get time hours, minutes and seconds function
 *
 * @param[out] dayOfTheWeek               pointer of date of the week data [ 1 - 7 ]
 *
 * @param[out] dateDay                    pointer of date day data [ 1 - 31 ]
 *
 * @param[out] dateMonth                  pointer of date month data [ 1 - 12 ]
 *
 * @param[out] dateYear                   pointer of date year data [ 0 - 99 ]
 *
 * Function gets date: day of the week, day, month and year data from
 * the target register address ( 0x03, 0x04, 0x05 & 0x06 )
 * of BQ32000 chip on RTC 3 Click.
 */
void rtc3_getDate( uint8_t *dayOfTheWeek, uint8_t *dateDay, uint8_t *dateMonth, uint16_t *dateYear );

/**
 * @brief Set calibration function
 *
 * @param[in] calSign                     Calibration sign:
 * - 0: POSITIV;
 * - 1: NEGATIV;
 *
 * @param[in] calNumber                   Calibration number:
 * - positiv: number/491520 ppm
 * - negativ: number/245760 ppm
 *
 * Function set calibration by write CAL_CFG1 register of BQ32000 chip.
 */
void rtc3_setCalibration( uint8_t calSign, uint8_t calNumber );

/**
 * @brief Set trickle charge control function
 *
 * @param[in] tch2                        trickle charge control
 * - 0: Open;
 * - 1: Closed;
 *
 * Function set the TCH2 bit determines if 
 * the internal trickle charge switch is closed or open.
 * All the trickle charge switches must be closed
 * in order for trickle charging to occur.
 */
void rtc3_setTrickleCharge( uint8_t tch2 );

/**
 * @brief Set trickle charge bypass control function
 *
 * @param[in] tcfe                        trickle charge control
 * - 0: Open;
 * - 1: Closed;
 *
 * Function set the trickle charge FET bypass. 
 * The TCFE bit is used to enable the trickle charge FET. 
 * When TCFE is 0, the FET is off.
 */
void rtc3_setTrickleChargeBypass( uint8_t tcfe );

/**
 * @brief Set special function key byte 1 function
 *
 * @param[in] sfkey1                      special function key byte 1
 *
 * Function set special function access key byte 1. 
 * Reads as 0x00, and key is 0x5E.
 * The SF KEY 1 registers are used to enable access to the main special function register (SFR). 
 * Access to SFR is granted only after the special function keys are written sequentially to SF KEY 1. 
 * Each write to the SFR must be preceded by writing the SF keys to the SF key registers, 
 * in order, SF KEY 1 then SF KEY 2.
 */
void rtc3_setSpecialFunctionKey1( uint8_t sfkey1 );

/**
 * @brief Set special function key byte 2 function
 *
 * @param[in] sfkey2                      special function key byte 2
 *
 * Function set special function access key byte 2.
 * Reads as 0x00, and key is 0x5E.
 * The SF KEY 2 registers are used to enable access to the main special function register (SFR).
 * Access to SFR is granted only after the special function keys are written sequentially to SF KEY 2.
 * Each write to the SFR must be preceded by writing the SF keys to the SF key registers,
 * in order, SF KEY 1 then SF KEY 2.
 */
void rtc3_setSpecialFunctionKey2( uint8_t sfkey2 );

/**
 * @brief Set frequency calibration control function
 *
 * @param[in] ftf                         frequency of the calibration output
 * - 0: Normal 512 Hz calibration;
 * - 1: 1 Hz calibration;
 *
 * Function set force calibration control.
 * FTF allows the frequency of the calibration output to be changed from 512 Hz to 1 Hz. 
 * By default, FTF is cleared, and the RTC outputs a 512-Hz calibration signal. 
 * Setting FTF forces the calibration signal to 1 Hz, 
 * and the calibration tracks the internal ppm adjustment. 
 *
 * @note: The default 512-Hz calibration signal does not include
 * the effect of the ppm adjustment.
 */
void rtc3_setFrequencyCalibration( uint8_t ftf );

/**
 * @brief Get state of interrupt pin function
 *
 * @return state of INT pin
 * - 0: not active;
 * - 1: active
 * Function get state of interrupt ( INT ) pin.
 */
uint8_t rtc3_getInterrupt();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RTC_3_STM.c
    @example Click_RTC_3_TIVA.c
    @example Click_RTC_3_CEC.c
    @example Click_RTC_3_KINETIS.c
    @example Click_RTC_3_MSP.c
    @example Click_RTC_3_PIC.c
    @example Click_RTC_3_PIC32.c
    @example Click_RTC_3_DSPIC.c
    @example Click_RTC_3_AVR.c
    @example Click_RTC_3_FT90x.c
    @example Click_RTC_3_STM.mbas
    @example Click_RTC_3_TIVA.mbas
    @example Click_RTC_3_CEC.mbas
    @example Click_RTC_3_KINETIS.mbas
    @example Click_RTC_3_MSP.mbas
    @example Click_RTC_3_PIC.mbas
    @example Click_RTC_3_PIC32.mbas
    @example Click_RTC_3_DSPIC.mbas
    @example Click_RTC_3_AVR.mbas
    @example Click_RTC_3_FT90x.mbas
    @example Click_RTC_3_STM.mpas
    @example Click_RTC_3_TIVA.mpas
    @example Click_RTC_3_CEC.mpas
    @example Click_RTC_3_KINETIS.mpas
    @example Click_RTC_3_MSP.mpas
    @example Click_RTC_3_PIC.mpas
    @example Click_RTC_3_PIC32.mpas
    @example Click_RTC_3_DSPIC.mpas
    @example Click_RTC_3_AVR.mpas
    @example Click_RTC_3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rtc3_driver.h

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