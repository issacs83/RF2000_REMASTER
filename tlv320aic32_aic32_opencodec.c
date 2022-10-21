/*
 *  Copyright 2007 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */
/*
 *  AIC32 implementation
 *
 */
#include "tlv320aic32.h"
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _AIC32_openCodec( )                                                     *
 *     Open the codec and return a codec handle                             *
 *                                                                          *
 *      Inputs:                                                             *
 *              id     -> AIC32 id (                                        *
 *              config -> Register configurations                           *
 *                                                                          *
 *      Return:                                                             *
 *              1+: AIC32 handle                                            *
 *              -1: Error                                                   *
 *                                                                          *
 * ------------------------------------------------------------------------ */
AIC32_Handle TLV320AIC32_openCodec( uint32_t id, uint8_t *config )
{
    int16_t retcode = 0;
//    uint32_t vdd3p3vpwdn;
    AIC32_Handle aic32;
    if ( ( id != AIC32_0 ) || ( config == 0 ) )
        return -1;
    /*
     *  The MCASP0-1 pins are on dedicated pins and do not need to be muxed,
     *  however the 3.3V power does need to be enabled.
     */
//    vdd3p3vpwdn = ( 1 << 18 );
//    EVMDM6467_clrPinMux( 0, 0, vdd3p3vpwdn );
    /* -------------------------------- *
     *                                  *
     *  AIC32 <-> MCASP0                *
     *  .BCLK --> .ACLKX0 [input]       *
     *        +-> .ACLKR0               *
     *  .WCLK --> .AFSX0  [input]       *
     *        +-> .AFSR0                *
     *  .DOUT --> .AXR0[1][input]       *
     *  .DIN  <-- .AXR0[0][output]      *
     *                                  *
     * -------------------------------- */
    /* The AIC32 handle is the unique aic32 I2C address */
    aic32 = ( AIC32_Handle )AIC32_I2C_ADDR;
    /* Reset AIC32 */
//    retcode |= TLV320AIC32_rset( aic32, AIC32_PAGESELECT, 0 );
//    retcode |= TLV320AIC32_rset( aic32, AIC32_RESET, 0x80 );
    /* Configure AIC32 */
    retcode |= TLV320AIC32_config( aic32, config );
    /* Initialize MCASP0 */
//    retcode |= EVMDM6467_MCASP_open( MCASP_0 );
    if ( retcode )
        return -1;
    return aic32;
}
