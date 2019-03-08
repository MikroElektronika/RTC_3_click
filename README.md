![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# RTC_3 Click

---

- **CIC Prefix**  : RTC3
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the RTC_3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/1241/rtc3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control RTC 3 Click board.
RTC 3 click communicates with the target board via I2C protocol. 
This library contains drivers for write and read data from BQ32000 chip,
set time and date, get time and date, enable and disable counting,
set frequency by write configuration register, enable and set special function register.

Key functions :

- ``` void rtc3_setTime( uint8_t timeHours, uint8_t timeMinutes, uint8_t timeSeconds ) ``` - Set time hours, minutes and seconds function
- ``` void rtc3_getTime( uint8_t *timeHours, uint8_t *timeMinutes, uint8_t *timeSeconds ) ``` - Get time hours, minutes and seconds function
- ``` void rtc3_getDate( uint8_t *dayOfTheWeek, uint8_t *dateDay, uint8_t *dateMonth, uint16_t *dateYear ) ``` - Get time hours, minutes and seconds function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     set start time and date, enable counting and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of RTC 3 Click board.
     RTC 3 Click communicates with register via I2C by write to register and read from register,
     set time and date, get time and date, enable and disable counting.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart changes for every 1 sec.


```.c

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

```

- void displayLogDayOfTheWeek( uint8_t dayOfTheWeek ) - Write day of the week log on USART terminal.
- void displayLogUart( uint8_t value ) - Write the value of time or date as a two-digit number.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1241/rtc3-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions
- C_String

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
