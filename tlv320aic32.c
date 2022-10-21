/*
 *  Copyright 2007 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */
/*
 *  AIC32 Test
 *
 */
#include <stdio.h>
#include "tlv320aic32.h"
#include "mcc_generated_files/delay.h"

//#include "tlv320psc.h"

extern int16_t aic32_tone_headphone( );
extern int16_t aic32_tone_lineout( );
extern int16_t aic32_loop_linein( );
extern int16_t aic32_loop_micin( );
extern int16_t aic32_headphoneout( );
extern void button_push_play(void);
extern void power_off_buzzer(void);

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  aic32_test( )                                                           *
 *      Audio Test for Inputs & Outputs                                     *
 *                                                                          *
 *                     /-------                                            *
 *      Linein [P6] -> |       | -> [P4] Headphone                          *
 *                     | AIC32 |                                            *
 *      Micin  [P8] -> |       | -> [P5] Lineout                            *
 *                     -------/                                            *
 *                                                                          *
 * ------------------------------------------------------------------------ */

int16_t aic32_test( void )
{
    aic32_headphoneout();

    return 0;
}
void TLV320_SetHeadphoneVol(unsigned char volume){
    uint8_t cmd, regval, i;
    tlv320_volume_up[3] = tlv320_volume[volume];
    tlv320_volume_up[5] = tlv320_volume[volume];
    
    for (i = 0; i<  16; i+= 2){
        cmd = (tlv320_volume_up[i]);
        regval = tlv320_volume_up[i+1];
        i2c_write( AIC32_I2C_ADDR, cmd, regval );
        DELAY_milliseconds(1);
    }
    
}
void TLV320_Mute(unsigned char on_off){
    uint8_t cmd, regval, i;
    button_push_play();
//    power_off_buzzer();
    if(on_off == 1){ // mic mute on
        for (i = 0; i<  4; i+= 2){
            cmd = (tlv320_mic_control[i]);
            regval = tlv320_mic_control[i+1];
            i2c_write( AIC32_I2C_ADDR, cmd, regval );
            DELAY_milliseconds(1);
        }
    }
    else{ // mic mute off
        for (i = 4; i<  30; i+= 2){
            cmd = (tlv320_mic_control[i]);
            regval = tlv320_mic_control[i+1];
            i2c_write( AIC32_I2C_ADDR, cmd, regval );
            DELAY_milliseconds(1);
        }
    }
}