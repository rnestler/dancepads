/* Main.c file generated by New Project wizard
 *
 * Created:   Sa Nov 2 2013
 * Processor: PIC18F24K22
 * Compiler:  MPLAB XC8
 */

#include <xc.h>
#include <p18cxxx.h>
#include <stdint.h>
#include <spi.h>

#include "dp_adc.h"
#include "dp_led.h" 
#include "dp_spi.h"

#define _XTAL_FREQ 4000000
#define MAX (32)

void main(void)
{
    adc_initialize();
    //led_initialize();
    spi_initialize();

    uint8_t max = MAX;
    uint8_t r=0, g=0, b=0;
    uint8_t s=0, result=0;
    unsigned short adc;
    
    result = ReadSPI1();
    WriteSPI1(result);
    
    // Write your code here
    while (1) {
        adc = adc_busy_read();
        s = adc;
        WriteSPI1(s);
        
        //led_set_rgb(result,result,result);
        /*
        if (result < 63)
            led_set_rgb(512,0,0);
        if (result > 63)
            led_set_rgb(0,0,1);
        if (result == 63)
            led_set_rgb(0,1,0);
        */
        //__delay_ms(10);
    }
 }