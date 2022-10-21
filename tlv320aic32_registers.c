/*
 *  Copyright 2007 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */
/*
 *  AIC32 implementation
 *
 */
#include "tlv320aic32.h"
//#include "HAL_I2C.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "mcc_generated_files/delay.h"
#define I2C 0

#if I2C
#define i2c_write   i2cWrite // //halI2cWrite
#define i2c_read    i2cRead // //halI2cRead
#else
#define i2c_write   I2C1_Write1ByteRegister //halI2cWrite //i2cWrite //halI2cWrite
#define i2c_read    I2C1_Read1ByteRegister //halI2cRead //i2cRead //halI2cRead
#endif
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _AIC32_rget( aic32, regnum, regval )                                    *
 *      Return value of codec register regnum                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
int16_t TLV320AIC32_rget( AIC32_Handle aic32, uint16_t regnum, uint16_t* regval )
{
    int16_t retcode = 0;
//    uint8_t cmd[1];
    uint8_t cmd = regnum & 0x7f;         // 7-bit Register Address
    /* Read register */
#if I2C
	retcode |= i2c_write( AIC32_I2C_ADDR, cmd[0], 1, &cmd[0] );
	retcode |= i2c_read( AIC32_I2C_ADDR, cmd[0], 1, &cmd[0] );
#else
//	retcode |= i2c_write( AIC32_I2C_ADDR, cmd, 1 );
    i2c_write( AIC32_I2C_ADDR, cmd, 1 );
	retcode |= i2c_read( AIC32_I2C_ADDR, cmd);
#endif
//    *regval = cmd[0];
    return retcode;
}
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _AIC32_rset( aic32, regnum, regval )                                    *
 *      Set codec register regnum to value regval                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
int16_t TLV320AIC32_rset( AIC32_Handle aic32, uint16_t regnum, uint16_t regval )
{
//    uint8_t cmd[2];
//    cmd[0] = regnum & 0x7f;         // 7-bit Register Address
//    cmd[1] = regval;                // 8-bit Register Data
    
//    uint8_t cmd = regnum & 0x7f;         // 7-bit Register Address
     uint8_t cmd = (regnum <<1) & 0xFe;         // 7-bit shift Register Address
    /* Write register */
#if I2C
    	return i2c_write( AIC32_I2C_ADDR, cmd[0], 1, &cmd[1] );
#else
    	i2c_write( AIC32_I2C_ADDR, cmd, regval );
//        I2C1_Write2ByteRegister( AIC32_I2C_ADDR, cmd, regval );
#endif
}
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _AIC32_rset_mask( aic32, regnum, regval, mask )                         *
 *      Set codec register regnum to value regval                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
int16_t TLV320AIC32_rset_mask( AIC32_Handle aic32, uint16_t regnum,
                                 uint16_t regval, uint8_t mask )
{
    uint16_t old_regval;
    int16_t retcode = 0;
    /* Read register */
    retcode |= TLV320AIC32_rget( aic32, regnum, &old_regval );
    /* Mask then Set the value */
    old_regval = ( ( old_regval & ( ~mask ) ) | ( regval & mask ) );
    /* Write register */
    retcode |= TLV320AIC32_rset( aic32, regnum, old_regval );
    return retcode;
}
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _AIC32_config( aic32, config )                                          *
 *     Set the default codec register config values                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
int16_t TLV320AIC32_config( AIC32_Handle aic32, uint8_t *config )
{
    int16_t i, data;
    uint8_t cmd, regval;
    int16_t retcode = 0;
    unsigned char len = sizeof(config)/2;
    
    if ( config == 0 )
        return -1;
    /* Configure every non-reserved, non-status register */
    
//    for (; len--; data += 2){
//       tlv320aic3204_bulk_write(data, 2);
//    }
    
    for (i = 0; i<  AIC32_NUMREGS; i+= 2){
//    for ( i = 0 ; i < AIC32_NUMREGS ; i+=2){
//        data = ((config[i] << 8 ) & 0xff00) | (config[i+1] & 0xff);
//        if ( ( config ) == 0 )
//        cmd = (config[i] <<1) & 0xFe; 
        cmd = (config[i]);
        regval = config[i+1];
//            retcode |= TLV320AIC32_rset( aic32, , data );
            i2c_write( AIC32_I2C_ADDR, cmd, regval );
            DELAY_milliseconds(1);
    }
    return retcode;
}
