/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * tlv320aic32x4.h
 */


#ifndef _TLV320AIC32_H
#define _TLV320AIC32_H

#include "stdint.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#ifdef __cplusplus
extern "C" {
#endif
//#include "HAL_I2C.h"
//#include "evmdm6467_mcasp.h"
/* ------------------------------------------------------------------------ *
 *  AIC32 ID                                                                *
 * ------------------------------------------------------------------------ */
#define AIC32_0                 0
/* ------------------------------------------------------------------------ *
 *  AIC32 I2C address                                                       *
 * ------------------------------------------------------------------------ */
#define AIC32_I2C_ADDR          0x18//(0x18>>1)
/* ------------------------------------------------------------------------ *
 *  AIC32 Registers                                                         *
 * ------------------------------------------------------------------------ */
#define AIC32_NUMREGS           248 // 104
#define AIC32_PAGESELECT        0
#define AIC32_RESET             1
#define READONLY                0xaa00
#define RESERVED                0xffff
/* ------------------------------------------------------------------------ *
 *  AIC32 Data Structures                                                   *
 * ------------------------------------------------------------------------ */
typedef int16_t AIC32_Handle;
typedef struct {
	int16_t regs[AIC32_NUMREGS];
} AIC32_Config;

#define i2c_write   I2C1_Write1ByteRegister //halI2cWrite //i2cWrite //halI2cWrite

uint8_t tlv320_volume_down[12] = {
    0x00, 0x00,
    0x41, 0xef,
    0x42, 0xef,
    0x00, 0x01,
    0x10, 0x0e,
    0x11, 0x0e,
    0x00, 0x00, 
    0x40, 0x00, // DAC Channel Setup Register default 0x0c

};
uint8_t tlv320_volume_up[16] = {
    0x00, 0x00,
    0x41, 0x08, // Left DAC Channel Digital Volume Control Register  old :0xf4
                // Default 0x08 4dB
    0x42, 0x08, // Right DAC Channel Digital Volume Control Register
                // Default 0x08 4dB
    0x00, 0x01, 
    0x10, 0x0e, // HPL Driver Gain Setting Register old : 0x0e (14dB)
                // Default 0x00 0dB
    0x11, 0x0e, // HPR Driver Gain Setting Register
                // Default 0x00 0dB
    0x00, 0x00, 
    0x40, 0x00, // DAC Channel Setup Register default 0x0c
                // DAC Channel not Muted
};

uint8_t tlv320_volume_up2[4] = {
    0x00, 0x00,
    0x40, 0x00,
};

uint8_t tlv320_streaming_off[8] = {
    //dealy 1sec
    0x00, 0x00,
    0x40, 0x0c,
    // dealy 1sec
    0x00, 0x00,
    0x40, 0x00,
};
static uint8_t tlv320_volume[] = {
    0x81, //mute
//    0xd9, // -32db
//    0xdd, // -28db
//    0xe1, // -24db
//    0xe5, // -20db
//    0xe9, // -16db
//    0xed, // -12db
    0xf1, //-8 dB
    0xf9, // -4 dB
    0x00, // 0 dB
    0x08, // 4 dB
    0x10, // 8 dB
    0x18, // 12 dB
    0x20, // 16 dB
    0x28, // 20 dB
    0x30,  // 24 dB
};




uint8_t tlv320_mic_control[34] = {
    // MIC Mute On
    0x00, 0x00,
    0X51, 0x00, // Power Down Left and Right ADC Channels
    
    // MIC Mute Off
    // MIC Enable
    0x00, 0x01,
    0x01, 0x08, // powering up internal AVdd LDO
    0x02, 0x00, // Enable Master Analog Power Control
    0xa0, 0x00, // Set the Input Common Mode to 0.9V 
    0x3d, 0x00, // Select ADC PTM_R4
    0x47, 0x32, // Set MicPGA startup delay to 3.1ms
    0x7b, 0x01, // Set the REF charging time to 40ms
//    0x37, 0x08, // Route IN1R to RIGHT_P with input impedance of 20K
    0x37, 0x04, // Route IN1R to RIGHT_P with input impedance of 10K
//    0x39, 0x08, // Route Common Mode to RIGHT_M with impedance of 20K
    0x39, 0x04, // Route Common Mode to RIGHT_M with impedance of 10K
    0x3c, 0x5f, // 5f (47.5dB) // 0x0c (6dB),
    0x00, 0x00,
    0x51, 0xc0, // Power up Left and Right ADC Channels
    0x52, 0x00, // Unmute Left and Right ADC Digital Volume Control.
};
/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
/* Open/Close codec */
AIC32_Handle TLV320AIC32_openCodec ( uint32_t id, uint8_t *config );
int16_t        TLV320AIC32_closeCodec( AIC32_Handle aic32 );
/* Get/Set registers */
int16_t TLV320AIC32_rget     ( AIC32_Handle aic32, uint16_t regnum, uint16_t* regval );
int16_t TLV320AIC32_rset     ( AIC32_Handle aic32, uint16_t regnum, uint16_t regval );
int16_t TLV320AIC32_rset_mask( AIC32_Handle aic32, uint16_t regnum, uint16_t regval, uint8_t mask );
int16_t TLV320AIC32_config   ( AIC32_Handle aic32, uint8_t* config );
/* Read/Write 16-bit or 32-bit data */
int16_t TLV320AIC32_read16   ( AIC32_Handle aic32, int16_t* data16 );
int16_t TLV320AIC32_read32   ( AIC32_Handle aic32, int32_t* data32 );
int16_t TLV320AIC32_write16  ( AIC32_Handle aic32, int16_t data16 );
int16_t TLV320AIC32_write32  ( AIC32_Handle aic32, int32_t data32 );
/* Special functions */
void TLV320AIC32_mute      ( AIC32_Handle aic32, int16_t mode );
void TLV320_SetHeadphoneVol(unsigned char volume);
int16_t aic32_test( void );
void TLV320_Mute(unsigned char on_off);
#ifdef __cplusplus
}
#endif
#endif				/* _TLV320AIC32_H */
