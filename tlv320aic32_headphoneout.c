
/*
 *  AIC32 Tone Lineout
 *
 */
#include "tlv320aic32.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC32 Setup Lineout                                                     *
 *                                                                          *
 *      AIC32.MCLK = CDCE949.Y2                                             *
 *      FS = ( AIC32.MCLK * K ) / ( 2048 * P )                              *
 *                                                                          *
 *      For a FS=[48 kHz] & MCLK=[12.0000 MHz]                              *
 *          : 48kHz = ( 12.0000 MHz * K ) / ( 2048 * P )                    *
 *          : P = 1, K[J.D] = 8.192                                        *
 *          : Real audio Frequency = 46,875 Hz                              *
 * ------------------------------------------------------------------------ */
int16_t aic32_headphoneout( );

static unsigned char aic32config_page[] = {
    0x00, 0x00,
    0x01, 0x01,
    0x0B, 0x81,
    0x0C, 0x82,
    0x0d, 0x00,
    0x0e, 0x80,
    0x12, 0x81,
    0x13, 0x82,
    0x14, 0x80,
    0x1b, 0x00,
    0x37, 0x0E,
    0x38, 0x02,
    0x3c, 0x08,
    0x3d, 0x01,
    
    0x00, 0x01,
    0x01, 0x08,
    0x02, 0x00,
    0x0a, 0x00,
    0x47, 0x31,
    0x7b, 0x01,
    0x14, 0x65,
    0x0c, 0x08, //0x09, // 0x08
    0x0d, 0x08, //0x0A, // 0X08
    0x34, 0x04,
    0x36, 0x04,
    0x37, 0x04,
    0x39, 0x08, //0x00, // 0X08
    0x00, 0x08,
    0x18, 0x7f,
    0x19, 0xff,
    0x1a, 0x00,
    0x1c, 0x80,
    0x1d, 0x01,
    0x1e, 0x00,
    0x20, 0x7f,
    0x21, 0xfc,
    0x22, 0x00,
    0x00, 0x09,
    0x20, 0x7f,
    0x21, 0xff,
    0x22, 0x00,
    0x24, 0x80,
    0x25, 0x01,
    0x26, 0x00,
    0x28, 0x7f,
    0x29, 0xfc,
    0x2a, 0x00,
    0x00, 0x01,
    0x33, 0x44, //0x48, // 0X44
    0x10, 0x00, // 0x00
    0x11, 0x00, // 0x00
    0x09, 0x30, //0x31, // 0x30
    0x3b, 0x9d,
    0x3c, 0x9d,
    0x00, 0x00,
          
    
    0x3f, 0xD6,
    0x40, 0x00,
    0x41, 0x81, // Left DAC Channel Digital Volume Control Register
    0x42, 0x81, // Right DAC Channel Digital Volume Control Register
    0x51, 0xC0,
    0x52, 0x00,
    
    0x0b, 0x81,
    0x0c, 0x82,
    
    0x00, 0x00,
    0x01, 0x01,
    0x0b, 0x81,
    0x0c, 0x82,
    0x0d, 0x00,
    0x0e, 0x80,
    0x12, 0x81,
    0x13, 0x82,
    0x14, 0x80,
    0x1b, 0x00,
    0x37, 0x0e,
    0x38, 0x02,
    0x3c, 0x08,
    0x3d, 0x01,
    
           
           
    
    0x00, 0x01,
    0x01, 0x08,
    0x02, 0x00,
    
    0x0a, 0x00,
    0x47, 0x31,
    0x7b, 0x01,
    0x14, 0x65,
    0x0c, 0x08, //0x09, // 0x08
    0x0d, 0x08, //0x0A, // 0x08
    0x34, 0x04,
    0x36, 0x04,
    0x37, 0x04,
    0x39, 0x08, //0x00, // 0X08
    0x00, 0x08,
    0x18, 0x7f,
    0x19, 0xff,
    0x1a, 0x00,
    0x1c, 0x80,
    0x1d, 0x01,
    0x1e, 0x00,
    0x20, 0x7f,
    0x21, 0xfc,
    0x22, 0x00,
    0x00, 0x09,
    0x20, 0x7f,
    0x21, 0xff,
    0x22, 0x00,
    0x24, 0x80,
    0x25, 0x01,
    0x26, 0x00,
    0x28, 0x7f,
    0x29, 0xfc,
    0x2a, 0x00,
    0x00, 0x01,
    0x33, 0x44, //0x48, // 0X44
    0x10, 0x0e, // 0x0e (14dB)
    0x11, 0x0e, // 0x0e (14dB)
    0x09, 0x30, // 0x30 - HPL, HPR Power Up
    0x3b, 0x9d,
    0x3c, 0x9d,
    0x00, 0x00,
    0x3f, 0xd6,
    0x40, 0x00,
    0x41, 0xe5, // Left DAC Channel Digital Volume Control Register
    0x42, 0xe5, // Right DAC Channel Digital Volume Control Register
    0x51, 0xc0, // Left, Right Channel ADC is Powered Up
    0x52, 0x00

};


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC32 Tone                                                              *
 *      Output a 1 kHz tone through the HEADPHONE/LINEOUT jacks             *
 *                                                                          *
 * ------------------------------------------------------------------------ */
int16_t aic32_headphoneout( )
{
    int16_t msec, sec;
    int16_t sample;
    AIC32_Handle aic32;
	/* Grab AIC32 handle */
	aic32 = TLV320AIC32_openCodec( AIC32_0, &aic32config_page );
	return 0;
}
