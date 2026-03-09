/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SPI_private.h            ****************/
/****************************************************************************/



#ifndef    SPI_PRIVATE_H_
#define    SPI_PRIVATE_H_

/*________________include part______________*/

#include "STD_types.h"


/*______________SPI Registers Def____________*/

typedef struct {

    uint_8 SPCR ;        /*0x2D*/
    uint_8 SPSR ;        /*0x2E*/
    uint_8 SPDR ;        /*0x2F*/
 
}SPI_Regs;


#define      SPI_DDR   *((volatile uint_8 *)0x37)

#define      SPI       ((volatile SPI_Regs*)0x2D)


/*_________________SPCR BITS__________________*/

typedef enum {
    SPCR_SPR0 = 0,  
    SPCR_SPR1 = 1,  
    SPCR_CPHA = 2,  
    SPCR_CPOL = 3,  
    SPCR_MSTR = 4,  
    SPCR_DORD = 5,  
    SPCR_SPE  = 6,  
    SPCR_SPIE = 7   
} SPI_SPCR_BITS;

/*_________________SPSR BITS__________________*/

typedef enum {
    SPSR_SPI2X = 0, 
    SPSR_WCOL  = 6, 
    SPSR_SPIF  = 7  
} SPI_SPSR_BITS;

/*_________________SPI_DDR BITS__________________*/

typedef enum {
    DDR_SS = 4 ,
    DDR_MOSI   ,
    DDR_MISO   ,
    DDR_SCK    ,

} SPI_DDR_BITS;


#endif /*<SPI_PRIVATE_H_*/
