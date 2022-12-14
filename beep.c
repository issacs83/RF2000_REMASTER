#include "mcc_generated_files/mcc.h"
#include "beep.h"
//void beep(unsigned int note, unsigned int duration);
//void play(void);
//void init_play(void);

//FREQUENCIES
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

#define B_PIN  21//12



//This function generates the square wave that makes the piezo speaker sound at a determinated frequency.
void beep(unsigned int note, unsigned int duration)
{
	//This is the semiperiod of each note.
	long beepDelay = (long)(1000000/note);
	//This is how much time we need to spend on the note.
	long time = (long)((duration*1000)/(beepDelay*2));
	int i;
    PWM_CON_SetHigh();
	for(i=0;i<time;i++)
	{
		//1st semiperiod
//		digitalWrite(B_PIN, HIGH);
        PWM_SetHigh();
//		delayMicroseconds(beepDelay);
        DELAY_milliseconds(beepDelay);
		//2nd semiperiod
//		digitalWrite(B_PIN, LOW);
        PWM_SetLow();
//		delayMicroseconds(beepDelay);
        DELAY_milliseconds(beepDelay);
	}

	//Add a little delay to separate the single notes
//	digitalWrite(B_PIN, LOW);
    PWM_CON_SetLow();
    PWM_SetLow();
//	delay(20);
    DELAY_milliseconds(20);
}

//The source code of the Imperial March from Star Wars
void play(void)
{
	beep( a, 500);
	beep( a, 500);
	beep( f, 350);
	beep( cH, 150);

	beep( a, 500);
	beep( f, 350);
	beep( cH, 150);
	beep( a, 1000);
	beep( eH, 500);

	beep( eH, 500);
	beep( eH, 500);
	beep( fH, 350);
	beep( cH, 150);
	beep( gS, 500);

	beep( f, 350);
	beep( cH, 150);
	beep( a, 1000);
	beep( aH, 500);
	beep( a, 350);

	beep( a, 150);
	beep( aH, 500);
	beep( gHS, 250);
	beep( gH, 250);
	beep( fHS, 125);

	beep( fH, 125);
	beep( fHS, 250);

//	delay(250);
    DELAY_milliseconds(250);

	beep( aS, 250);
	beep( dHS, 500);
	beep( dH, 250);
	beep( cHS, 250);
	beep( cH, 125);

	beep( b, 125);
	beep( cH, 250);

//	delay(250);
    DELAY_milliseconds(250);

	beep( f, 125);
	beep( gS, 500);
	beep( f, 375);
	beep( a, 125);
	beep( cH, 500);

	beep( a, 375);
	beep( cH, 125);
	beep( eH, 1000);
	beep( aH, 500);
	beep( a, 350);

	beep( a, 150);
	beep( aH, 500);
	beep( gHS, 250);
	beep( gH, 250);
	beep( fHS, 125);

	beep( fH, 125);
	beep( fHS, 250);

//	delay(250);
    DELAY_milliseconds(250);

	beep( aS, 250);
	beep( dHS, 500);
	beep( dH, 250);
	beep( cHS, 250);
	beep( cH, 125);

	beep( b, 125);
	beep( cH, 250);

//	delay(250);
    DELAY_milliseconds(250);

	beep( f, 250);
	beep( gS, 500);
	beep( f, 375);
	beep( cH, 125);
	beep( a, 500);

	beep( f, 375);
	beep( c, 125);
	beep( a, 1000);
}

void init_play(void)
{
	beep( a, 500);
	beep( a, 500);
	beep( f, 350);
	beep( cH, 150);

	beep( a, 500);
	beep( f, 350);
	beep( cH, 150);
	beep( a, 1000);
	beep( eH, 500);

	beep( eH, 500);
	beep( eH, 500);
	beep( fH, 350);
	beep( cH, 150);
	beep( gS, 500);

	beep( f, 350);
	beep( cH, 150);
	beep( a, 1000);
}