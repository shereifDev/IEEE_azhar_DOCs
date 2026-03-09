/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SPI_program.c            ****************/
/****************************************************************************/

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "STD_types.h"
#include "BIT_MATH.h"





// void  HAL_SPI_Master_init(void){

//     /* Set MOSI and SCK output*/
//     SET_BIT(SPI_DDR,DDR_MOSI);
//     SET_BIT(SPI_DDR,DDR_SCK);

//     /*Set as a Master*/
//     SET_BIT(SPI->SPCR,SPCR_MSTR);

//     /*Set the CLK Rate (Fosc/16)*/
//     SET_BIT(SPI->SPCR,SPCR_SPR0);

//     /*Enable SPI*/
//     SET_BIT(SPI->SPCR,SPCR_SPE);

// }


// void  HAL_SPI_Slave_init(void){

//     /* Set MISO output*/
//     SET_BIT(SPI_DDR,DDR_MISO);

//     /*Enable SPI*/
//     SET_BIT(SPI->SPCR,SPCR_SPE);

// }


void HAL_SPI_init(void){

#if SPI_MODE == MASTER 

    /* Set MOSI and SCK output*/
    SET_BIT(SPI_DDR,DDR_MOSI);
    SET_BIT(SPI_DDR,DDR_SCK);

    /*Set as a Master*/
    SET_BIT(SPI->SPCR,SPCR_MSTR);

    /*Set CLK Rate*/

    // Clear Speed Bits
    SPI->SPCR &= ~((1<<SPCR_SPR0) | (1<<SPCR_SPR1));
    CLR_BIT(SPI->SPSR, SPSR_SPI2X);

    #if CLK_RATE == F_OSC_DIV_4
    // SPR0=0, SPR1=0, SPI2X=0 (Default)
    #elif CLK_RATE == F_OSC_DIV_16
    SET_BIT(SPI->SPCR, SPCR_SPR0);
    #elif CLK_RATE == F_OSC_DIV_64
    SET_BIT(SPI->SPCR, SPCR_SPR1);
    #elif CLK_RATE == F_OSC_DIV_128
    SET_BIT(SPI->SPCR, SPCR_SPR0);
    SET_BIT(SPI->SPCR, SPCR_SPR1);
    #elif CLK_RATE == F_OSC_DIV_2
    SET_BIT(SPI->SPSR, SPSR_SPI2X); 
    #elif CLK_RATE == F_OSC_DIV_8
    SET_BIT(SPI->SPCR, SPCR_SPR0);
    SET_BIT(SPI->SPSR, SPSR_SPI2X);
    #elif CLK_RATE == F_OSC_DIV_32
    SET_BIT(SPI->SPCR, SPCR_SPR1);
    SET_BIT(SPI->SPSR, SPSR_SPI2X);

    #endif /*<CLK_RATE*/


#else 

    /* Set MISO output*/
    SET_BIT(SPI_DDR,DDR_MISO);

 #endif /*<_SPI_MODE_*/

    /*Enable SPI*/
    SET_BIT(SPI->SPCR,SPCR_SPE);

}



///////////////////////////////////////////////////////////////////////////____0_0_///////////


void  HAL_SPI_MasterTransmit(uint_8 Data){

    /*Send the Data*/
    SPI->SPDR = Data ;

    /*Wait Untill Data Transmit*/
    while(!(READ_BIT(SPI->SPSR,SPSR_SPIF)));
}

///////////////////////////////////////////////////////////////////////////____0_0_///////////


uint_8 HAL_SPI_SlaveReceive(void){

    uint_8 Received_Data ;

    /*Wait Untill Data Received Copmletely*/
    while(!(READ_BIT(SPI->SPSR,SPSR_SPIF)));

    /*Return data*/
    Received_Data = SPI->SPDR ;
    return Received_Data ;
}
