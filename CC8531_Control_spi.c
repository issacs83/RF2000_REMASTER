#include "CC8531_Control_spi.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

#define AIC32_I2C_ADDR          0x18//(0x18>>1)
#define i2c_write   I2C1_Write1ByteRegister //halI2cWrite //i2cWrite //halI2cWrite
uint8_t streaming_off_flag = 0x00;
extern void power_off_sequence(void);


void CC8531_Init_Data_Send(void){
    unsigned char cmd_count = 0;
    unsigned char check_connected = 0;
    unsigned char check_connected_retry_count = 0;
    SPI2_Open(SPI2_DEFAULT);
    
    while(1){
        RF_CSN_SetHigh();
        DELAY_microseconds(100); //500);
        RF_CSN_SetLow();

        for(cmd_count = 0; cmd_count < 4; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
        }
        RF_CSN_SetHigh();
        DELAY_milliseconds(1);
        RF_CSN_SetLow();
        for(cmd_count = 4; cmd_count < 30; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
        }

        RF_CSN_SetHigh();
        DELAY_microseconds(500);
        RF_CSN_SetLow();
        for(cmd_count = 30; cmd_count < 33; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
        }

        RF_CSN_SetHigh();
        DELAY_milliseconds(1500);
    
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x52, 0x88 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x40, 0x0c );
//    DELAY_milliseconds(500);
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x40, 0x00 );
//    DELAY_milliseconds(1);
    
        RF_CSN_SetLow();
        for(cmd_count = 33; cmd_count < 51; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
        }
    
        for(uint16_t i = 0; i<3000; i++){ // 1000ms delay
            RF_CSN_SetHigh(); 
            DELAY_microseconds(1);
            RF_CSN_SetLow();
            DELAY_microseconds(1);
        }
        // Read Device ID
        for(cmd_count = 51; cmd_count < 83; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
            if(cmd_count == 54){
                DELAY_microseconds(1);
                check_connected = SPI2_ReadByte();
            }
            
            if((cmd_count >= 55) && (cmd_count <= 58)){
                DELAY_microseconds(1);
                cc8531_init_data[cmd_count +32] = SPI2_ReadByte();

            }
        }
        RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
        RF_CSN_SetLow();
        for(cmd_count = 83 ; cmd_count < 103; cmd_count++){
            SPI2_WriteByte(cc8531_init_data[cmd_count]);
            DELAY_microseconds(1);
        }   
        // check RF Connected 
        // if RF not connected --> Loop Init
        if(check_connected != 0x00){
            break;
        }
        // Loop About 3 Second
        // doing power off sequence during 60 second
        if(check_connected_retry_count > 20){ 
            power_off_sequence();
        }
    }
    
    for(uint16_t i = 0; i<280; i++){ // 73ms Delay
        RF_CSN_SetHigh(); 
        DELAY_microseconds(1);
        RF_CSN_SetLow();
        DELAY_microseconds(1);
    }
    
    for(cmd_count = 103 ; cmd_count < 105; cmd_count++){
    SPI2_WriteByte(cc8531_init_data[cmd_count]);
    DELAY_microseconds(1);
    }  
 
    RF_CSN_SetHigh(); 
    DELAY_microseconds(100);//500);
    RF_CSN_SetLow();
    for(cmd_count = 105 ; cmd_count < 139; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }  
    
    RF_CSN_SetHigh(); 
    DELAY_milliseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 139 ; cmd_count < 157; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 157 ; cmd_count < 159; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 159 ; cmd_count < 162; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 162 ; cmd_count < 165; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 165 ; cmd_count < 169; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
  
        // volume control - i2c init process 
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x41, 0xf4 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x42, 0xf4 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x40, 0x0c );
//    DELAY_milliseconds(100);
 
    
    RF_CSN_SetLow();
    for(cmd_count = 169 ; cmd_count < 172; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }  
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 172 ; cmd_count < 175; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }  
    
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    RF_CSN_SetLow();
    for(cmd_count = 175 ; cmd_count < 179; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 

    // mic control - mute control process
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x01 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x3b, 0x9d );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x3c, 0x9d );
//    DELAY_milliseconds(1);
    
    DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 179 ; cmd_count < 181; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
    DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 181 ; cmd_count < 199; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
     DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 199 ; cmd_count < 201; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
    
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 201 ; cmd_count < 204; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 204 ; cmd_count < 207; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 207 ; cmd_count < 211; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 211 ; cmd_count < 214; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 214 ; cmd_count < 217; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
        DELAY_microseconds(500);
    
    RF_CSN_SetLow();
    for(cmd_count = 217 ; cmd_count < 222; cmd_count++){
        SPI2_WriteByte(cc8531_init_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh(); 
  
    // volume control - i2c init process 
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x40, 0x00 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x41, 0xf4 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x42, 0xf4 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x00, 0x01 );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x10, 0x0e );
//    DELAY_milliseconds(1);
//    i2c_write( AIC32_I2C_ADDR, 0x11, 0x0e );
    
    SPI2_Close();
    DELAY_microseconds(100);//500););
}

void CC8531_Polling_Data_Send(void){
    unsigned char cmd_count = 0;
    SPI2_Open(SPI2_DEFAULT);
    RF_CSN_SetHigh();
//    DELAY_microseconds(500);

    RF_CSN_SetLow();
    for(cmd_count = 0; cmd_count < 3; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 3; cmd_count < 6; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();
    
    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 6; cmd_count < 10; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();
    
    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 10; cmd_count < 13; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();    

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 13; cmd_count < 16; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   
    
    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 16; cmd_count < 20; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 20; cmd_count < 22; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 22; cmd_count < 40; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        if(cmd_count == 32){
            DELAY_microseconds(1);
            streaming_off_flag = SPI2_ReadByte();
            if(streaming_off_flag == 0x08){
//                streaming_off_flag = 0x11;
                
                DELAY_milliseconds(1000);
                i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
                DELAY_milliseconds(1);
                i2c_write( AIC32_I2C_ADDR, 0x40, 0x0c );
                DELAY_milliseconds(1000);
                i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
                DELAY_milliseconds(1);
                i2c_write( AIC32_I2C_ADDR, 0x40, 0x00 );
                DELAY_milliseconds(1);
                power_off_sequence();
            }
        }
//        if(cmd_count == 0x33){
//            if((SPI2_ReadByte() == 0x01)&&(streaming_off_flag == 0x10)){
//                streaming_off_flag = 0x11;
//            }
//            else{
//                streaming_off_flag = 0x00;
//            }
//        }
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 40; cmd_count < 42; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 42; cmd_count < 45; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 45; cmd_count < 48; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 48; cmd_count < 52; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 52; cmd_count < 55; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 55; cmd_count < 58; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

    DELAY_microseconds(1);
    RF_CSN_SetLow();
    for(cmd_count = 58; cmd_count < 62; cmd_count++){
        SPI2_WriteByte(cc8531_polling_data[cmd_count]);
        DELAY_microseconds(1);
    }
    RF_CSN_SetHigh();   

//    if(streaming_off_flag == 0x11){
//        DELAY_milliseconds(1000);
//        i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//        DELAY_milliseconds(1);
//        i2c_write( AIC32_I2C_ADDR, 0x40, 0x0c );
//        DELAY_milliseconds(1000);
//        i2c_write( AIC32_I2C_ADDR, 0x00, 0x00 );
//        DELAY_milliseconds(1);
//        i2c_write( AIC32_I2C_ADDR, 0x40, 0x00 );
//        DELAY_milliseconds(1);
//        power_off_sequence();
//    }
}