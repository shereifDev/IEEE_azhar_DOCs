/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     BUZZER_interface.h        ****************** */






#ifndef        BUZZER_INTERFACE_H
#define        BUZZER_INTERFACE_H


/*_______________inc_part________________*/

#include "DIO_interface.h"






/*____________user_def_data_types_______________*/


typedef struct {

    GPIO_PIN_CNFG MOTOR_PIN[2];
    
}MOTOR_CFG;



typedef enum {
    motor_pin1 , 
    motor_pin2
}motor_pins ;












/**
 * @brief   this func take jodsjfosdfisodhfiodhsoih
 * 
 * @return 
 * 
 *  
 * 
 * */

ErrorState ECUAL_MOTOR_init(MOTOR_CFG *ptr);
/**
 * @brief   this func take jodsjfosdfisodhfiodhsoih
 * 
 * @return 
 * 
 *  
 * 
 * */
ErrorState ECUAL_MOTOR_turn_right(MOTOR_CFG *ptr);
/**
 * @brief   this func take jodsjfosdfisodhfiodhsoih
 * 
 * @return 
 * 
 *  
 * 
 * */
ErrorState ECUAL_MOTOR_turn_left(MOTOR_CFG *ptr);
/**
 * @brief   this func take jodsjfosdfisodhfiodhsoih
 * 
 * @return 
 * 
 *  
 * 
 * */
ErrorState ECUAL_MOTOR_turn_off(MOTOR_CFG *ptr);

















#endif /*< BUZZER_INTERFACE_H*/

