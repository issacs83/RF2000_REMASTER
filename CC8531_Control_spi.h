/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  


// TODO Insert appropriate #include <>
unsigned char cc8531_init_data[222]={
     // array 0
    // 0xDF -> 0b11011111 
    //      -> 0b11 : CMD_REQ
    //      -> 0b011111 : Command type (0x1F) => Get Chip Info
    // 0x02 -> Number of bytes
    // 0x00, 0xB0 -> Must be 0x00B0
    0xDF,    0x02,    0x00,    0xB0,   
    
     // array 4
    // 0x90 -> 0b10010000
    //      -> 0b1001 : READ
    //      -> 0b0000 + 0x18 : Number of bytes (24)
    0x90,    0x18,    0x00,    0xb0,    0x00,    
    0x00,    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,    0x00,    
    0x1a,    0x00,    0x52,    0xb7,    0x01,    0x00,
     
    // array 30
    // 0xD9 -> 0b11011001
    //      -> 0b11 : CMD_REQ
    //      -> 0b011001 : Command type (0x19) => Clear EHIF event flags
    // 0x01 -> Number of bytes
    // 0x3f -> all flag clear
    0xd9,    0x01,    0x3f,    

     // array 33
    // 0xC8 -> 0b11001000
    //      -> 0b11 : CMD_REQ
    //      -> 0b001000 : Command type (0x08) => NWM_DO_SCAN
    //                    Performs a scan of the whole 2.4 GHz band
    //                    searching for audio networks within range and
    //                    returns a list of those found
    // 0x01 -> Number of bytes
    0xc8,    0x10,
    0x80,    0x64,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,    0x00,
    0x00,    0x00,    0x00,    0x00,    0x00,   0x80,
     
    // array 51
    // 0xA0 -> 0b10100000
    //      --> 0b1010 READBC (Reads an unspecified number of bytes)
    //      --> Other bits Don't Care
    0xa0, 0x10, // 16-bit Status word
    0x80, 0x64, // Number of bytes in the data field
                // 0x00 --> Not Connected
    0x00, 0x00, 0x00, 0x00, // Device ID -> 0x20, 0xD6, 0x45, 0x57
    0x00, 0x00, 0x00, 0x00, // Manufacturer ID
    0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20,
    0x00, 0x52, 0xb7, 0x01, 0x00, 0x40, 0x00,
    0x04, 0x3c, 0xa0, 0x1c,
     
    // array 83
    // 0xC9 -> 0b11001001
    //      --> 0b11 : CMD_REQ
    //      --> 0b001001 -> 0x09  NWM_DO_JOIN
    //     Joins a specific audio network or the first available
    //     one meeting specified criteria. Also used to leave a network
    0xc9, 0x12, 
    0x00, 0x64,             // Time out 
    //0x20, 0xd6, 0x45, 0x57, // Device ID
    0x00, 0x00, 0x00, 0x00, // Device ID
    0x00, 0x00, 0x00, 0x00, // Manufacturer ID
    0x00, 0x00, 0x00, 0x00, // Product/family ID
    0x00, 0x00, 0x00, 0x00, // Filtering criteria
    
    // array 103
    // 0xCA -> 0b11001010
    //      --> 0b11 : CMD_REQ
    //      --> 0b001010 -> 0x0A  NWM_GET_STATUS
    //      Returns status about current audio network status and other nodes in network
    0xca, 0x00,
    
    // array 105
    // 0xA0 -> 0b10100000
    //      -->0b1010 READBC (Reads an unspecified number of bytes)
    //      --> Other bits Don't Care    
    0xa0, 0x00, 0x00, 0x64, 0x20, 0xd6, 0x45, 0x57,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x52, 0xb7,
    0x01, 0x00, 0x40, 0x00, 0x06, 0x3c, 0xa0, 0x1c,
    0x01, 0x00,
    
    // array 139
    // 0xCB -> 0b11001011
    //      --> 0b11 : CMD_REQ
    //      --> 0b001011 -> 0x0B  NWM_ACH_SET_USAGE
    //      Used on protocol slaves to define how logical audio channels supported in audio network should be mapped to
    //      local audio interface channels as defined by the PurePath Wireless Configurator. 
    0xcb, 0x10, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
    0xff, 0xff,
    
    // array 157
    // 0x80 -> 0b10000000
    //      --> 0b1000 : WRITE
    //      --> 0b000000 -> 0x00  Number of bytes in the data field
    0x80, 0x00,
    
    // array 159
    // 0xD6 -> 0b11010110
    //      --> 0b11 : CMD_REQ
    //      --> 0b010110 -> 0x16  VC_GET_VOLUME   
    0xd6, 0x01, 0x31,
    
    // array 162
    // 0xD6 -> 0b11010110
    //      --> 0b11 : CMD_REQ
    //      --> 0b010110 -> 0x16  VC_GET_VOLUME       
    0xd6, 0x01, 0x30,
    
    // array 165
    // 0x90 -> 0b10010000
    //      -> 0b1001 : READ
    //      -> 0b0000 + 0x02 : Number of bytes (2)
    0x90, 0x02, 0x30, 0x01,
    
    // array 169
    0xd6, 0x01, 0x31,
    
    // array 172
    0xd6, 0x01, 0x30,
    
    // array 175
    0x90, 0x02, 0x30, 0x01,
    
    // array 179
    // 0xDD -> 0b11011101
    //      --> 0b11 : CMD_REQ
    //      --> 0b011101 -> 0x1D  PM_GET_DATA 
    //          Returns power management related information.
    0xdd, 0x00,
    
    //arrary 181
    // 0xA0 -> 0b10100000
    //      -->0b1010 READBC (Reads an unspecified number of bytes)
    //      --> Other bits Don't Care  
    0xa0, 0x00, 0x32, 0x01,  
    0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0xff, 0xff, 0xff,
    
    // array 199
    // 0x80 -> 0b10000000
    //      --> 0b1000 : WRITE
    //      --> 0b000000 -> 0x00  Number of bytes in the data field
    0x80, 0x00,
    
    //array 201
    0xd6, 0x01, 0x31,
    
    //array 204
    0xd6, 0x01, 0x30,
    
    //array 207
    0x90, 0x02, 0x30, 0x01,
    
    //array 211
    0xd6, 0x01, 0x31,
    
    // array 214
    0xd6, 0x01, 0x30,
    
    //array 217
    0x90, 0x02, 0x30, 0x01
    
    //arrary 222
            
};

unsigned char cc8531_polling_data[62]={
    // array 0
    // 0xD6 -> 0b11010110
    //      --> 0b11 : CMD_REQ
    //      --> 0b010110 -> 0x16  VC_GET_VOLUME    
    0xd6, 0x01, 0x33, 
    
    // array 3
    0xd6, 0x01, 0x32,
    // array 6
    0x90, 0x02, 0x32, 0x01,
    // array 10
    0xd6, 0x01, 0x33,
    // array 13
    0xd6, 0x01, 0x32,
    // array 16
    0x90, 0x02, 0x32, 0x01,
    // array 20
    // 0xDD -> 0b11011101
    //      --> 0b11 : CMD_REQ
    //      --> 0b011101 -> 0x1D  PM_GET_DATA 
    //          Returns power management related information.
    0xdd, 0x00,
    
    // array 22
    0xa0, 0x00, 0x32, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, // 32 - 0x08 --> streaming stop
    0xff, // 33 - 0x01 --> streaming stop
    0xff, 0xff, 0x00, 0xff, 0xff, 0xff,
    // array 40
    0x80, 0x00,
    // array 42
    0xd6, 0x01, 0x31,
    // array 45
    0xd6, 0x01, 0x30,
    // array 48
    0x90, 0x02, 0x30, 0x01,
    // array 52
    0xd6, 0x01, 0x31,
    // array 55
    0xd6, 0x01, 0x30,
    // array 58
    0x90, 0x02, 0x30, 0x01,
    // array 62
};
// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
void CC8531_Init_Data_Send(void);
void CC8531_Polling_Data_Send(void);
// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */


