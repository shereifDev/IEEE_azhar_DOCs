/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  USART_program.c          ****************/
/****************************************************************************/


/**************************</include part>************************ */

#include  "USART_interface.h"
#include  "USART_private.h"
#include  "USART_config.h"
#include  "BIT_MATH.h"






void HAL_USART_init(void){

    /* Set baud rate */
    UBRRH  = (uint_8)(USART_BAUD_RATE >> 8);
    USART->UBRRL = (uint_8)(USART_BAUD_RATE);

    /* Enable receiver and transmitter */
    USART->UCSRB = (1<<UCSRB_RXEN) | (1<<UCSRB_TXEN) ;

    /* Set frame format*/
    #if   USART_CHAR_SIZE == 5
    UCSRC = (1 << UCSRC_URSEL);

    #elif USART_CHAR_SIZE == 6
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ0) ;
    
    #elif USART_CHAR_SIZE == 7
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) ;
    
    #elif USART_CHAR_SIZE == 8
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
    
    #elif USART_CHAR_SIZE == 9
    UCSRC = (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
    SET_BIT(USART->UCSRB,UCSRB_UCSZ2);

    #else 
    #error "invalid choise !"

    #endif /*< USART_CHAR_SIZE*/
    
}


////////////////////////////////////////////////////////////////<_0_0______/\/\/\/\/\/


 void HAL_USART_transmitData(uint_16 data){

    

 }