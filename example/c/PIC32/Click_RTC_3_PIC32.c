/*
Example for RTC_3 Click

    Date          : Nov 2018.
    Author        : Nenad Filipovic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     set start time and date, enable counting and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of RTC 3 Click board.
     RTC 3 Click communicates with register via I2C by write to register and read from register,
     set time and date, get time and date, enable and disable counting
     and set frequency by write configuration register.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart changes for every 1 sec.

Additional Functions :

- void displayLogDayOfTheWeek( uint8_t dayOfTheWeek ) - Write day of the week log on USART terminal.
- void displayLogUart( uint8_t value ) - Write the value of time or date as a two-digit number.

*/

#include "Click_RTC_3_types.h"
#include "Click_RTC_3_config.h"

uint8_t timeHours;
uint8_t timeMinutes;
uint8_t timeSeconds;
uint8_t dayOfTheWeek;
uint8_t dateDay;
uint8_t dateMonth;
uint16_t dateYear;
uint8_t timeSecondsNew = 0xFF;
char logText[50];

void displayLogDayOfTheWeek( uint8_t dayOfTheWeek )
{
    if ( dayOfTheWeek == 1 )
        mikrobus_logWrite( "      Monday      ", _LOG_LINE );
    if ( dayOfTheWeek == 2 )
        mikrobus_logWrite( "      Tuesday     ", _LOG_LINE );
    if ( dayOfTheWeek == 3 )
        mikrobus_logWrite( "     Wednesday    ", _LOG_LINE );
    if ( dayOfTheWeek == 4 )
        mikrobus_logWrite( "     Thursday     ", _LOG_LINE );
    if ( dayOfTheWeek == 5 )
        mikrobus_logWrite( "      Friday      ", _LOG_LINE );
    if ( dayOfTheWeek == 6 )
        mikrobus_logWrite( "     Saturday     ", _LOG_LINE );
    if ( dayOfTheWeek == 7 )
        mikrobus_logWrite( "      Sunday      ", _LOG_LINE );
}

void displayLogUart( uint8_t value )
{
    IntToStr( value / 10, logText );
    ltrim( logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    IntToStr( value % 10, logText );
    ltrim( logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_RTC3_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    rtc3_i2cDriverInit( (T_RTC3_P)&_MIKROBUS1_GPIO, (T_RTC3_P)&_MIKROBUS1_I2C, _RTC3_I2C_ADDRESS );

    mikrobus_logWrite( "------------------", _LOG_LINE );
    mikrobus_logWrite( "    RTC 3 Click   ", _LOG_LINE );
    mikrobus_logWrite( "------------------", _LOG_LINE );
    
    // Set Time: 23h, 59 min and 50 sec
    rtc3_setTime( 23, 59, 50 );
    // Set Date: 1 ( Day of the week ), 31 ( day ), 12 ( month ) and 2018 ( year )
    rtc3_setDate( 1, 31, 12, 2018 );
    // Start counting
    rtc3_enableCounting();
}

void applicationTask()
{
    rtc3_getTime( &timeHours, &timeMinutes, &timeSeconds );

    rtc3_getDate( &dayOfTheWeek, &dateDay, &dateMonth, &dateYear );

    if ( timeSecondsNew != timeSeconds )
    {
        if ( ( ( timeHours | timeMinutes | timeSeconds ) == 0 )  && ( ( dateDay | dateMonth ) == 1 ) )
        {
            mikrobus_logWrite( "  Happy New Year  ", _LOG_LINE );
            mikrobus_logWrite( "------------------", _LOG_LINE );
        }
        
        mikrobus_logWrite( " Time : ", _LOG_TEXT );

        displayLogUart( timeHours );
        mikrobus_logWrite( ":", _LOG_TEXT );

        displayLogUart( timeMinutes );
        mikrobus_logWrite( ":", _LOG_TEXT );

        displayLogUart( timeSeconds );
        mikrobus_logWrite( "", _LOG_LINE );

        displayLogDayOfTheWeek( dayOfTheWeek );

        mikrobus_logWrite( " Date: ", _LOG_TEXT );

        displayLogUart( dateDay );
        mikrobus_logWrite( ".", _LOG_TEXT );

        displayLogUart( dateMonth );
        mikrobus_logWrite( ".", _LOG_TEXT );

        mikrobus_logWrite( "20", _LOG_TEXT );

        displayLogUart( dateYear );
        mikrobus_logWrite( ".", _LOG_LINE );

        mikrobus_logWrite( "------------------", _LOG_LINE );

        timeSecondsNew = timeSeconds;
    }

    Delay_1ms();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}