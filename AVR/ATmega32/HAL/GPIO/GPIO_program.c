/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_program.c           ****************/
/****************************************************************************/


/***////**********************</INCLUDE PART>******************************* */

#include      "GPIO_private.h"
#include      "STD_types.h"
#include      "BIT_MATH.h"

#include      "GPIO_interface.h"






void HAL_GPIO_setPinDirection(PIN_CFG_t *ptr){

    STD_Return_Type RET = E_OK ; 
    if((NULL == ptr) || (ptr -> GPIO_PORT > GPIO_PORT_MAX-1) || (ptr -> GPIO_PIN > GPIO_PIN_MAX-1) ){
      RET = E_NOK ;
    }else{
      switch (ptr->GPIO_PORT){

        case 'A':
        case 'a':
         if(ptr->GPIO_PIN_DIR == 1) SET_BIT(DDRA,ptr->GPIO_PIN);
         else CLR_BIT(DDRA,ptr->GPIO_PIN);
         break;

        case 'B':
        case 'b':
         if(ptr->GPIO_PIN_DIR == 1) SET_BIT(DDRB,ptr->GPIO_PIN);
         else CLR_BIT(DDRB,ptr->GPIO_PIN);
         break;


         /*
         
         .
         .
         .
         .

         .
         
         
         */
        


        default:
         RET = E_NOK ; 
         break;
    }
}

///////////////////////////////////////////////////////////////////////////____0_0_///////////


void HAL_GPIO_setPinValue(PIN_CFG_t *ptr){

    
    switch (ptr->GPIO_PORT){
        case 'A':
        case 'a':
         if(ptr->GPIO_PIN_DIR == 1) SET_BIT(PORTA,ptr->GPIO_PIN);
         else CLR_BIT(PORTA,ptr->GPIO_PIN);
         break;

        case 'B':
        case 'b':
         if(ptr->GPIO_PIN_DIR == 1) SET_BIT(PORTB,ptr->GPIO_PIN);
         else CLR_BIT(PORTB,ptr->GPIO_PIN);
         break;


         /*
         
         .
         .
         .
         .
         
         */
        


        default:
        break;
    }  

}

