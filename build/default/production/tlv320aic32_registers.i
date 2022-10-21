# 1 "tlv320aic32_registers.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/ljehu/.mchp_packs/Microchip/PIC16F1xxxx_DFP/1.15.191/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "tlv320aic32_registers.c" 2








# 1 "./tlv320aic32.h" 1
# 10 "./tlv320aic32.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3
# 10 "./tlv320aic32.h" 2

# 1 "./mcc_generated_files/examples/i2c1_master_example.h" 1
# 51 "./mcc_generated_files/examples/i2c1_master_example.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 2 3
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 137 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 246 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

__attribute__((__format__(__printf__, 1, 2)))
int printf(const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int fprintf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int sprintf(char *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 3, 4)))
int snprintf(char *restrict, size_t, const char *restrict, ...);

__attribute__((__format__(__printf__, 1, 0)))
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 2, 0)))
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 3, 0)))
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

__attribute__((__format__(__scanf__, 1, 2)))
int scanf(const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int fscanf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int sscanf(const char *restrict, const char *restrict, ...);

__attribute__((__format__(__scanf__, 1, 0)))
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__scanf__, 2, 0)))
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 51 "./mcc_generated_files/examples/i2c1_master_example.h" 2

# 1 "./mcc_generated_files/examples/../i2c1_master.h" 1
# 56 "./mcc_generated_files/examples/../i2c1_master.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdbool.h" 1 3
# 56 "./mcc_generated_files/examples/../i2c1_master.h" 2


typedef enum {
    I2C1_NOERR,
    I2C1_BUSY,
    I2C1_FAIL


} i2c1_error_t;

typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} i2c1_operations_t;

typedef uint8_t i2c1_address_t;
typedef i2c1_operations_t (*i2c1_callback_t)(void *funPtr);


i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr);
i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr);






void I2C1_Initialize(void);
# 101 "./mcc_generated_files/examples/../i2c1_master.h"
i2c1_error_t I2C1_Open(i2c1_address_t address);
# 111 "./mcc_generated_files/examples/../i2c1_master.h"
i2c1_error_t I2C1_Close(void);
# 123 "./mcc_generated_files/examples/../i2c1_master.h"
i2c1_error_t I2C1_MasterOperation(_Bool read);




i2c1_error_t I2C1_MasterWrite(void);




i2c1_error_t I2C1_MasterRead(void);
# 142 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetTimeout(uint8_t timeOut);
# 152 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetBuffer(void *buffer, size_t bufferSize);
# 164 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr);
# 174 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr);
# 184 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr);
# 194 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr);
# 204 "./mcc_generated_files/examples/../i2c1_master.h"
void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr);
# 52 "./mcc_generated_files/examples/i2c1_master_example.h" 2


uint8_t I2C1_Read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t I2C1_Read2ByteRegister(i2c1_address_t address, uint8_t reg);
void I2C1_Write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void I2C1_Write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);
void I2C1_WriteNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadNBytes(i2c1_address_t address, uint8_t *data, size_t len);
void I2C1_ReadDataBlock(i2c1_address_t address, uint8_t reg, uint8_t *data, size_t len);
# 11 "./tlv320aic32.h" 2
# 36 "./tlv320aic32.h"
typedef int16_t AIC32_Handle;
typedef struct {
 int16_t regs[248];
} AIC32_Config;



uint8_t tlv320_volume_down[12] = {
    0x00, 0x00,
    0x41, 0xef,
    0x42, 0xef,
    0x00, 0x01,
    0x10, 0x0e,
    0x11, 0x0e,
    0x00, 0x00,
    0x40, 0x00,

};
uint8_t tlv320_volume_up[16] = {
    0x00, 0x00,
    0x41, 0x08,

    0x42, 0x08,

    0x00, 0x01,
    0x10, 0x0e,

    0x11, 0x0e,

    0x00, 0x00,
    0x40, 0x00,

};

uint8_t tlv320_volume_up2[4] = {
    0x00, 0x00,
    0x40, 0x00,
};

uint8_t tlv320_streaming_off[8] = {

    0x00, 0x00,
    0x40, 0x0c,

    0x00, 0x00,
    0x40, 0x00,
};
static uint8_t tlv320_volume[] = {
    0x81,






    0xf1,
    0xf9,
    0x00,
    0x08,
    0x10,
    0x18,
    0x20,
    0x28,
    0x30,
};




uint8_t tlv320_mic_control[34] = {

    0x00, 0x00,
    0X51, 0x00,



    0x00, 0x01,
    0x01, 0x08,
    0x02, 0x00,
    0xa0, 0x00,
    0x3d, 0x00,
    0x47, 0x32,
    0x7b, 0x01,

    0x37, 0x04,

    0x39, 0x04,
    0x3c, 0x5f,
    0x00, 0x00,
    0x51, 0xc0,
    0x52, 0x00,
};




AIC32_Handle TLV320AIC32_openCodec ( uint32_t id, uint8_t *config );
int16_t TLV320AIC32_closeCodec( AIC32_Handle aic32 );

int16_t TLV320AIC32_rget ( AIC32_Handle aic32, uint16_t regnum, uint16_t* regval );
int16_t TLV320AIC32_rset ( AIC32_Handle aic32, uint16_t regnum, uint16_t regval );
int16_t TLV320AIC32_rset_mask( AIC32_Handle aic32, uint16_t regnum, uint16_t regval, uint8_t mask );
int16_t TLV320AIC32_config ( AIC32_Handle aic32, uint8_t* config );

int16_t TLV320AIC32_read16 ( AIC32_Handle aic32, int16_t* data16 );
int16_t TLV320AIC32_read32 ( AIC32_Handle aic32, int32_t* data32 );
int16_t TLV320AIC32_write16 ( AIC32_Handle aic32, int16_t data16 );
int16_t TLV320AIC32_write32 ( AIC32_Handle aic32, int32_t data32 );

void TLV320AIC32_mute ( AIC32_Handle aic32, int16_t mode );
void TLV320_SetHeadphoneVol(unsigned char volume);
int16_t aic32_test( void );
void TLV320_Mute(unsigned char on_off);
# 9 "tlv320aic32_registers.c" 2



# 1 "./mcc_generated_files/delay.h" 1
# 34 "./mcc_generated_files/delay.h"
void DELAY_milliseconds(uint16_t milliseconds);
void DELAY_microseconds(uint16_t microseconds);
# 12 "tlv320aic32_registers.c" 2
# 28 "tlv320aic32_registers.c"
int16_t TLV320AIC32_rget( AIC32_Handle aic32, uint16_t regnum, uint16_t* regval )
{
    int16_t retcode = 0;

    uint8_t cmd = regnum & 0x7f;






    I2C1_Write1ByteRegister( 0x18, cmd, 1 );
 retcode |= I2C1_Read1ByteRegister( 0x18, cmd);


    return retcode;
}






int16_t TLV320AIC32_rset( AIC32_Handle aic32, uint16_t regnum, uint16_t regval )
{





     uint8_t cmd = (regnum <<1) & 0xFe;




     I2C1_Write1ByteRegister( 0x18, cmd, regval );


}






int16_t TLV320AIC32_rset_mask( AIC32_Handle aic32, uint16_t regnum,
                                 uint16_t regval, uint8_t mask )
{
    uint16_t old_regval;
    int16_t retcode = 0;

    retcode |= TLV320AIC32_rget( aic32, regnum, &old_regval );

    old_regval = ( ( old_regval & ( ~mask ) ) | ( regval & mask ) );

    retcode |= TLV320AIC32_rset( aic32, regnum, old_regval );
    return retcode;
}






int16_t TLV320AIC32_config( AIC32_Handle aic32, uint8_t *config )
{
    int16_t i, data;
    uint8_t cmd, regval;
    int16_t retcode = 0;
    unsigned char len = sizeof(config)/2;

    if ( config == 0 )
        return -1;






    for (i = 0; i< 248; i+= 2){




        cmd = (config[i]);
        regval = config[i+1];

            I2C1_Write1ByteRegister( 0x18, cmd, regval );
            DELAY_milliseconds(1);
    }
    return retcode;
}
