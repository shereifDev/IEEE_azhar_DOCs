/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     MOTOR_program.c           ****************** */

#include "MOTOR_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"




ErrorState ECUAL_MOTOR_init(MOTOR_CFG *ptr){

ErrorState checkErrorState = OK ;
if(NULL == ptr){
    checkErrorState = NOK ;
}else {

    
    checkErrorState = MCAL_DIO_setPinDir(&(ptr->MOTOR_PIN[motor_pin1]));
    checkErrorState = MCAL_DIO_setPinDir(&(ptr->MOTOR_PIN[motor_pin2]));

}

return checkErrorState ; 

}


//__________________________-------------------------_________________________________------------- 



ErrorState ECUAL_MOTOR_turn_right(MOTOR_CFG *ptr){
ErrorState checkErrorState = OK ;
if(NULL == ptr){
    checkErrorState = NOK ;
}else {

   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin1]), GPIO_LOGIC_HIGH);
   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin2]), GPIO_LOGIC_LOW) ;

}

return checkErrorState ;
}



//__________________________--------------------_________________________________----------------



ErrorState ECUAL_MOTOR_turn_left(MOTOR_CFG *ptr){
ErrorState checkErrorState = OK ;
if(NULL == ptr){
    checkErrorState = NOK ;
}else {

   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin1]), GPIO_LOGIC_LOW);
   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin2]), GPIO_LOGIC_HIGH) ;

}

return checkErrorState ;
}

//__________________________--------------------_________________________________----------------

ErrorState ECUAL_MOTOR_turn_off(MOTOR_CFG *ptr){
ErrorState checkErrorState = OK ;
if(NULL == ptr){
    checkErrorState = NOK ;
}else {

   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin1]), GPIO_LOGIC_LOW);
   checkErrorState =  MCAL_DIO_setPinValue( &(ptr->MOTOR_PIN[motor_pin2]), GPIO_LOGIC_LOW) ;

}

return checkErrorState ;
}
