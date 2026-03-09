/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_interface.h         ****************/
/****************************************************************************/




#ifndef   GPIO_INTERFACE_H_
#define   GPIO_INTERFACE_H_

#include     "STD_types.h"






typedef struct  {

    uint_8  GPIO_PORT:3       ;
    uint_8  GPIO_PIN:3        ;
    uint_8  GPIO_PIN_DIR:1    ;
    uint_8  GPIO_PIN_LOGIC:1  ;

}PIN_CFG_t;




#define GPIO_PORT_MAX    4
#define GPIO_PIN_MAX     8



/**
 * @brief 
 * 
 *  
 */

void HAL_GPIO_setPinDirection(PIN_CFG_t *ptr);



/**
 * @brief 
 * 
 * 
 * 
 * 
 * 
 */ 

void HAL_GPIO_setPinValue(PIN_CFG_t *ptr);











#endif  /*< GPIO_INTERFACE_H_*/