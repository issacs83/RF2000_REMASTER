/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18855
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/delay.h"
//#include "tlv320aic.h"
#include "tlv320aic32.h"
#include "main.h"
#include "CC8531_Control_spi.h"

#define     ON      1
#define     OFF     0

//#include "beep.h"
void power_off_buzzer(void);
void power_on_buzzer(void);
void button_push_play(void);
void volume_control(void);
void charge_display(void);
void led_control(led_state_struct led_state);
void power_off(void);
void power_on(void);
void power_off_sequence(void);
void mic_detect(void);

//extern void init_play(void);

unsigned char count_2_Second = 0;
uint16_t    volume_count = 0;
uint16_t    key_count = 0;
//uint16_t    l_pwr_on_count = 0;
mic_state   mic_state_choosed = MUTE_ON;
led_state_struct led_state;
bool key_pressed_volume = 0;
bool key_pressed_mute = 0;
//bool battery_low_flag = 0;
//bool battery_high_flag = 0;
uint8_t battery_count = 0;

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
//    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
//    mic_state_choosed = MIC_DISCONNECTED;
//    volume_count = 4; // Volume Default Value 4dB
    volume_count = DATAEE_ReadByte(0xF000);
    if(volume_count > 9) volume_count = 4;
    TLV320_SetHeadphoneVol(volume_count);    
    
    power_on();            
//    TLV320_Mute(OFF);
    while (1)
    {
        // Add your application code
        volume_control();
        charge_display();
        power_off();
        mic_detect();
        CC8531_Polling_Data_Send();
    }
}

void charge_display(void){
    adc_result_t charger_value, charger_temp; 

    if(R_PG_GetValue() == LOW ){ // ??? ??
        if(R_CHG2_GetValue() == LOW){ // ?? ??
            led_control(GREEN_LED_ON);
        }
        else{ // ?? ?
            led_control(RED_LED_ON);
        }
    }
    else{ // ??? ?? ??
        ADCC_StartConversion(channel_ANA6);
        while(!ADCC_IsConversionDone());
        charger_value = ADCC_GetConversionResult();
        charger_value = charger_value >> 3; // 7 bit adc
        
        // ADC Resolution : 5 bit (32) -> 0.102 V / 1 ADC Resolution
        // ADC Resolution : 6 bit (64) -> 0.051 V / 1 ADC Resolution
        // ADC Resolution : 7 bit (128) -> 0.025 V / 1 ADC Resolution
        // reference voltage : 3.3V
        // 
        // MCU Input : Vbat/2
        // Max Vbat : 4.11V (20 ADC Value)
        // Cut-off Vbat : 3.35V
        // 100 ~ 50% : Green -> 4.11 ~ 3.72V 
        //  50 ~ 20% : Blue  -> 3.72 ~ 3.502V
        //  20 ~  0% : Red   -> 3.502 ~ 3.35V
        
        // ADC Value
        // Calculated Value 
        // 3.72V (@ 3.270 V Reference Voltage) : 1.86 ADC input -> 72 --> 3.67 V
        // 3.50V (@ 3.259 V Reference Voltage) : 1.75 ADC input -> 68  --> 3.46 V
        // 3.35V (@ 3.188 V Reference Voltage) : 1.675 ADC input -> 66 --> 3.28 V
        
        // Actual Value 
        // 3.75 V : 70
        // 3.55 V : 66
        // 3.29 V : 65
        if(battery_count != 0){
            charger_temp = (charger_temp + charger_value)/2;
        }
        else{
            charger_temp = charger_value;
        }
        battery_count++;
             
        if(battery_count > 200){
            if(charger_value > 70 ) { // Green LED // Actual Value : 3.75V
                led_control(GREEN_LED_ON);      
            }
            else if((charger_value <= 70) && (charger_value > 66)){ // Actual Value : 3.75 ~ 3.55V
                led_control(BLUE_LED_ON);
            }
            else if((charger_value <= 66) && (charger_value >= 65)){ // Actual Value : 3.55 ~ 3.29 V
                led_control(RED_LED_ON);
            }
            else { // 3.29 V
                power_off_sequence();
            }
            battery_count = 0;
        }
    }
}

void mic_detect(void){
    adc_result_t mic_detect_value; 

    ADCC_StartConversion(channel_ANA1);
    while(!ADCC_IsConversionDone());
    mic_detect_value = ADCC_GetConversionResult();

    // 0x3FF - MIC DISCONNECTED
    // 0x2C0 - MIC CONNECTED
    if((mic_detect_value < 0x02FF)){ // active low        
        if((MIC_MUTE_GetValue() == LOW) && (key_pressed_mute == LOW)){
            if(mic_state_choosed == MUTE_OFF){
                TLV320_Mute(ON); // ??? Mute
                mic_state_choosed = MUTE_ON;
            }
            else{
                TLV320_Mute(OFF); // ??? Mute
                mic_state_choosed = MUTE_OFF;
            }
            key_pressed_mute = HIGH;
        }
        else if((MIC_MUTE_GetValue() == HIGH) && (key_pressed_mute == HIGH)){
            key_pressed_mute = LOW;
        }
    }
    else if((mic_detect_value > 0x0380) && (mic_state_choosed == MUTE_OFF)){ // mic off
        TLV320_Mute(ON); // ??? Mute
        mic_state_choosed = MUTE_ON;
    }
}


void volume_control(void){
    adc_result_t convertedValue; 
    
    ADCC_StartConversion(channel_ANA3);
    while(!ADCC_IsConversionDone());
    convertedValue = ADCC_GetConversionResult();

    if(convertedValue <= 0x300){ // Volume up
        if(volume_count > 8){
            volume_count = 9;
            button_push_play();
        }
        else{
            if(key_pressed_volume == LOW){
                volume_count++;
                key_pressed_volume =  HIGH;
//                DATAEE_WriteByte(0xF000, volume_count);
                TLV320_SetHeadphoneVol(volume_count);    
            }
        }
    }
    else if((convertedValue > 0x300) && (convertedValue <= 0x350)){
        if(volume_count < 1){
            volume_count = 0;
            button_push_play();
        }
        else{
            if(key_pressed_volume == LOW){
                volume_count--;
                key_pressed_volume = HIGH;
//                DATAEE_WriteByte(0xF000, volume_count);
                TLV320_SetHeadphoneVol(volume_count);
            }
        }
        
    }
    else{
         key_pressed_volume = LOW;
    }
}

void beep(unsigned int note, unsigned int duration)
{
	//This is the semiperiod of each note.
	long beepDelay = (long)(100000/note);
	//This is how much time we need to spend on the note.
	long time = (long)((duration*10)/(beepDelay*2));
	int i;
    PWM_CON_SetHigh();
	for(i=0;i<time;i++)
	{
		//1st semiperiod
//		digitalWrite(B_PIN, HIGH);
        PWM_SetHigh();
//		delayMicroseconds(beepDelay);
        DELAY_microseconds(beepDelay);
		//2nd semiperiod
//		digitalWrite(B_PIN, LOW);
        PWM_SetLow();
//		delayMicroseconds(beepDelay);
        DELAY_microseconds(beepDelay);
	}

	//Add a little delay to separate the single notes
//	digitalWrite(B_PIN, LOW);
    PWM_CON_SetLow();
    PWM_SetLow();
//	delay(20);
    DELAY_milliseconds(20);
}

void power_on_buzzer(void)
{
	beep( cS, 500);
	beep( f, 500);
    beep( gS, 500);
    beep( cHS, 500);

}

void power_off_buzzer(void)
{
	beep( cHS, 500);
	beep( gS, 500);
    beep( f, 500);
    beep( cS, 500);

}
void button_push_play(void){
    beep( bH, 500);
	beep( bH, 500);
//    beep( a, 500);
//	beep( a, 500);
//	beep( f, 350);
//	beep( cH, 150);
    
    
}
void led_control(led_state_struct led_state){
    switch(led_state){
        case RED_LED_ON:
            L_LED_R_SetHigh();
            L_LED_G_SetLow();
            L_LED_B_SetLow();
            break;
        case GREEN_LED_ON:
            L_LED_R_SetLow();
            L_LED_G_SetHigh();
            L_LED_B_SetLow();
            break;
        case BLUE_LED_ON:
            L_LED_R_SetLow();
            L_LED_G_SetLow();
            L_LED_B_SetHigh();
            break;
        case LED_OFF:
        default:
            L_LED_R_SetLow();
            L_LED_G_SetLow();
            L_LED_B_SetLow();
            break;
    }
}



void power_on(void){
//    if(R_PG_GetValue() == HIGH){ // ??? ?? ??
//        if(L_PWR_ON_GetValue() == HIGH){ // ?? On
            L_LDO_EN_M_SetHigh();
            power_on_buzzer();
            
            DELAY_milliseconds(100);
//            L_RESET_SetLow();
//            NRESET_SetLow();
//            
            L_RESET_SetHigh();
            NRESET_SetHigh();          
            
            led_control(BLUE_LED_ON);
            DELAY_milliseconds(200);
            led_control(LED_OFF);
            DELAY_milliseconds(200);
            led_control(BLUE_LED_ON);
            DELAY_milliseconds(200);
            led_control(LED_OFF);
            DELAY_milliseconds(200);
            led_control(BLUE_LED_ON);
//            DELAY_milliseconds(200);
//            led_control(LED_OFF);
            
//            L_RESET_SetHigh();
//            NRESET_SetHigh();
//            
            ADCC_Initialize();  
            DELAY_milliseconds(100);
            SPI2_Initialize();
            DELAY_milliseconds(100);
            aic32_test();
//            DELAY_milliseconds(1000);
            DELAY_milliseconds(300);
            CC8531_Init_Data_Send();
//            DELAY_milliseconds(50);
//            CC8531_Polling_Data_Send();
//            DELAY_milliseconds(50);
//            CC8531_Polling_Data_Send();
//        }
//    }
}

void power_off(void){
    if(L_PWR_ON_GetValue() == HIGH){
        if(key_count >100){
            power_off_sequence();
            key_count = 0;
        }
        else{
            key_count++;
        }
    }
    else{
        key_count = LOW;
    }
}

void power_off_sequence(void){
    DATAEE_WriteByte(0xF000, volume_count);
    power_off_buzzer();
    led_control(RED_LED_ON);
    DELAY_milliseconds(400);
    led_control(LED_OFF);
    DELAY_milliseconds(400);
    led_control(RED_LED_ON);
    DELAY_milliseconds(400);
    led_control(LED_OFF);
    DELAY_milliseconds(400);
    led_control(RED_LED_ON);
    DELAY_milliseconds(400);
    led_control(LED_OFF);
     L_LDO_EN_M_SetLow();
}

/**
 End of File
*/