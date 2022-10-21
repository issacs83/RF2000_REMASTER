/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18855
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set MIC_MUTE aliases
#define MIC_MUTE_TRIS                 TRISAbits.TRISA0
#define MIC_MUTE_LAT                  LATAbits.LATA0
#define MIC_MUTE_PORT                 PORTAbits.RA0
#define MIC_MUTE_WPU                  WPUAbits.WPUA0
#define MIC_MUTE_OD                   ODCONAbits.ODCA0
#define MIC_MUTE_ANS                  ANSELAbits.ANSA0
#define MIC_MUTE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define MIC_MUTE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define MIC_MUTE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define MIC_MUTE_GetValue()           PORTAbits.RA0
#define MIC_MUTE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define MIC_MUTE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define MIC_MUTE_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define MIC_MUTE_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define MIC_MUTE_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define MIC_MUTE_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define MIC_MUTE_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define MIC_MUTE_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_ANA1 aliases
#define channel_ANA1_TRIS                 TRISAbits.TRISA1
#define channel_ANA1_LAT                  LATAbits.LATA1
#define channel_ANA1_PORT                 PORTAbits.RA1
#define channel_ANA1_WPU                  WPUAbits.WPUA1
#define channel_ANA1_OD                   ODCONAbits.ODCA1
#define channel_ANA1_ANS                  ANSELAbits.ANSA1
#define channel_ANA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_ANA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_ANA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_ANA1_GetValue()           PORTAbits.RA1
#define channel_ANA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_ANA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_ANA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_ANA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_ANA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define channel_ANA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define channel_ANA1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define channel_ANA1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set L_LDO_EN_M aliases
#define L_LDO_EN_M_TRIS                 TRISAbits.TRISA2
#define L_LDO_EN_M_LAT                  LATAbits.LATA2
#define L_LDO_EN_M_PORT                 PORTAbits.RA2
#define L_LDO_EN_M_WPU                  WPUAbits.WPUA2
#define L_LDO_EN_M_OD                   ODCONAbits.ODCA2
#define L_LDO_EN_M_ANS                  ANSELAbits.ANSA2
#define L_LDO_EN_M_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define L_LDO_EN_M_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define L_LDO_EN_M_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define L_LDO_EN_M_GetValue()           PORTAbits.RA2
#define L_LDO_EN_M_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define L_LDO_EN_M_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define L_LDO_EN_M_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define L_LDO_EN_M_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define L_LDO_EN_M_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define L_LDO_EN_M_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define L_LDO_EN_M_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define L_LDO_EN_M_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set channel_ANA3 aliases
#define channel_ANA3_TRIS                 TRISAbits.TRISA3
#define channel_ANA3_LAT                  LATAbits.LATA3
#define channel_ANA3_PORT                 PORTAbits.RA3
#define channel_ANA3_WPU                  WPUAbits.WPUA3
#define channel_ANA3_OD                   ODCONAbits.ODCA3
#define channel_ANA3_ANS                  ANSELAbits.ANSA3
#define channel_ANA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define channel_ANA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define channel_ANA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define channel_ANA3_GetValue()           PORTAbits.RA3
#define channel_ANA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define channel_ANA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define channel_ANA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define channel_ANA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define channel_ANA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define channel_ANA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define channel_ANA3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define channel_ANA3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set PWM_CON aliases
#define PWM_CON_TRIS                 TRISAbits.TRISA4
#define PWM_CON_LAT                  LATAbits.LATA4
#define PWM_CON_PORT                 PORTAbits.RA4
#define PWM_CON_WPU                  WPUAbits.WPUA4
#define PWM_CON_OD                   ODCONAbits.ODCA4
#define PWM_CON_ANS                  ANSELAbits.ANSA4
#define PWM_CON_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define PWM_CON_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define PWM_CON_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define PWM_CON_GetValue()           PORTAbits.RA4
#define PWM_CON_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define PWM_CON_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define PWM_CON_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define PWM_CON_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define PWM_CON_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define PWM_CON_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define PWM_CON_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define PWM_CON_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set L_RESET aliases
#define L_RESET_TRIS                 TRISAbits.TRISA5
#define L_RESET_LAT                  LATAbits.LATA5
#define L_RESET_PORT                 PORTAbits.RA5
#define L_RESET_WPU                  WPUAbits.WPUA5
#define L_RESET_OD                   ODCONAbits.ODCA5
#define L_RESET_ANS                  ANSELAbits.ANSA5
#define L_RESET_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define L_RESET_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define L_RESET_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define L_RESET_GetValue()           PORTAbits.RA5
#define L_RESET_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define L_RESET_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define L_RESET_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define L_RESET_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define L_RESET_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define L_RESET_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define L_RESET_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define L_RESET_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set channel_ANA6 aliases
#define channel_ANA6_TRIS                 TRISAbits.TRISA6
#define channel_ANA6_LAT                  LATAbits.LATA6
#define channel_ANA6_PORT                 PORTAbits.RA6
#define channel_ANA6_WPU                  WPUAbits.WPUA6
#define channel_ANA6_OD                   ODCONAbits.ODCA6
#define channel_ANA6_ANS                  ANSELAbits.ANSA6
#define channel_ANA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define channel_ANA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define channel_ANA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define channel_ANA6_GetValue()           PORTAbits.RA6
#define channel_ANA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define channel_ANA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define channel_ANA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define channel_ANA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define channel_ANA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define channel_ANA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define channel_ANA6_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define channel_ANA6_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set L_PWR_ON aliases
#define L_PWR_ON_TRIS                 TRISAbits.TRISA7
#define L_PWR_ON_LAT                  LATAbits.LATA7
#define L_PWR_ON_PORT                 PORTAbits.RA7
#define L_PWR_ON_WPU                  WPUAbits.WPUA7
#define L_PWR_ON_OD                   ODCONAbits.ODCA7
#define L_PWR_ON_ANS                  ANSELAbits.ANSA7
#define L_PWR_ON_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define L_PWR_ON_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define L_PWR_ON_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define L_PWR_ON_GetValue()           PORTAbits.RA7
#define L_PWR_ON_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define L_PWR_ON_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define L_PWR_ON_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define L_PWR_ON_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define L_PWR_ON_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define L_PWR_ON_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define L_PWR_ON_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define L_PWR_ON_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RF_CSN aliases
#define RF_CSN_TRIS                 TRISBbits.TRISB0
#define RF_CSN_LAT                  LATBbits.LATB0
#define RF_CSN_PORT                 PORTBbits.RB0
#define RF_CSN_WPU                  WPUBbits.WPUB0
#define RF_CSN_OD                   ODCONBbits.ODCB0
#define RF_CSN_ANS                  ANSELBbits.ANSB0
#define RF_CSN_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RF_CSN_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RF_CSN_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RF_CSN_GetValue()           PORTBbits.RB0
#define RF_CSN_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RF_CSN_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RF_CSN_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define RF_CSN_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define RF_CSN_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define RF_CSN_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define RF_CSN_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define RF_CSN_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set NRESET aliases
#define NRESET_TRIS                 TRISBbits.TRISB4
#define NRESET_LAT                  LATBbits.LATB4
#define NRESET_PORT                 PORTBbits.RB4
#define NRESET_WPU                  WPUBbits.WPUB4
#define NRESET_OD                   ODCONBbits.ODCB4
#define NRESET_ANS                  ANSELBbits.ANSB4
#define NRESET_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define NRESET_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define NRESET_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define NRESET_GetValue()           PORTBbits.RB4
#define NRESET_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define NRESET_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define NRESET_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define NRESET_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define NRESET_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define NRESET_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define NRESET_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define NRESET_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set R_CHG2 aliases
#define R_CHG2_TRIS                 TRISBbits.TRISB5
#define R_CHG2_LAT                  LATBbits.LATB5
#define R_CHG2_PORT                 PORTBbits.RB5
#define R_CHG2_WPU                  WPUBbits.WPUB5
#define R_CHG2_OD                   ODCONBbits.ODCB5
#define R_CHG2_ANS                  ANSELBbits.ANSB5
#define R_CHG2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define R_CHG2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define R_CHG2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define R_CHG2_GetValue()           PORTBbits.RB5
#define R_CHG2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define R_CHG2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define R_CHG2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define R_CHG2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define R_CHG2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define R_CHG2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define R_CHG2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define R_CHG2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set L_LED_R aliases
#define L_LED_R_TRIS                 TRISCbits.TRISC0
#define L_LED_R_LAT                  LATCbits.LATC0
#define L_LED_R_PORT                 PORTCbits.RC0
#define L_LED_R_WPU                  WPUCbits.WPUC0
#define L_LED_R_OD                   ODCONCbits.ODCC0
#define L_LED_R_ANS                  ANSELCbits.ANSC0
#define L_LED_R_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define L_LED_R_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define L_LED_R_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define L_LED_R_GetValue()           PORTCbits.RC0
#define L_LED_R_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define L_LED_R_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define L_LED_R_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define L_LED_R_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define L_LED_R_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define L_LED_R_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define L_LED_R_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define L_LED_R_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set L_LED_G aliases
#define L_LED_G_TRIS                 TRISCbits.TRISC1
#define L_LED_G_LAT                  LATCbits.LATC1
#define L_LED_G_PORT                 PORTCbits.RC1
#define L_LED_G_WPU                  WPUCbits.WPUC1
#define L_LED_G_OD                   ODCONCbits.ODCC1
#define L_LED_G_ANS                  ANSELCbits.ANSC1
#define L_LED_G_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define L_LED_G_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define L_LED_G_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define L_LED_G_GetValue()           PORTCbits.RC1
#define L_LED_G_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define L_LED_G_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define L_LED_G_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define L_LED_G_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define L_LED_G_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define L_LED_G_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define L_LED_G_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define L_LED_G_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set PWM aliases
#define PWM_TRIS                 TRISCbits.TRISC2
#define PWM_LAT                  LATCbits.LATC2
#define PWM_PORT                 PORTCbits.RC2
#define PWM_WPU                  WPUCbits.WPUC2
#define PWM_OD                   ODCONCbits.ODCC2
#define PWM_ANS                  ANSELCbits.ANSC2
#define PWM_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define PWM_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define PWM_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define PWM_GetValue()           PORTCbits.RC2
#define PWM_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define PWM_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define PWM_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define PWM_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define PWM_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define PWM_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define PWM_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define PWM_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set L_LED_B aliases
#define L_LED_B_TRIS                 TRISCbits.TRISC5
#define L_LED_B_LAT                  LATCbits.LATC5
#define L_LED_B_PORT                 PORTCbits.RC5
#define L_LED_B_WPU                  WPUCbits.WPUC5
#define L_LED_B_OD                   ODCONCbits.ODCC5
#define L_LED_B_ANS                  ANSELCbits.ANSC5
#define L_LED_B_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define L_LED_B_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define L_LED_B_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define L_LED_B_GetValue()           PORTCbits.RC5
#define L_LED_B_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define L_LED_B_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define L_LED_B_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define L_LED_B_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define L_LED_B_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define L_LED_B_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define L_LED_B_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define L_LED_B_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set R_PG aliases
#define R_PG_TRIS                 TRISCbits.TRISC7
#define R_PG_LAT                  LATCbits.LATC7
#define R_PG_PORT                 PORTCbits.RC7
#define R_PG_WPU                  WPUCbits.WPUC7
#define R_PG_OD                   ODCONCbits.ODCC7
#define R_PG_ANS                  ANSELCbits.ANSC7
#define R_PG_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define R_PG_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define R_PG_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define R_PG_GetValue()           PORTCbits.RC7
#define R_PG_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define R_PG_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define R_PG_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define R_PG_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define R_PG_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define R_PG_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define R_PG_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define R_PG_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/