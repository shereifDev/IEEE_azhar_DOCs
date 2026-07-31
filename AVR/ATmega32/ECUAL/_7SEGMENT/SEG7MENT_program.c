/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file     7SEG_program.h            ****************** */


#include  "SEG7MENT_interface.h"
#include  "SEG7MENT_private.h"
#include  "SEG7MENT_config.h"



#include "BIT_MATH.h"















ErrorState  ECUAL_SEVEN_SEGMENT_initialize(_7SEGMENT_CFG *ptr){

    ErrorState  checkErrorState = OK;
    if(NULL == ptr){
        checkErrorState = NOK ;
    }else {


        // MCAL_DIO_setPinDir(&(ptr->SEG7MENT[0]));
        // MCAL_DIO_setPinDir(&(ptr->SEG7MENT[1]));
        // MCAL_DIO_setPinDir(&(ptr->SEG7MENT[2]));
        // MCAL_DIO_setPinDir(&(ptr->SEG7MENT[3]));


        for(int i=0 ; i<4 ; ++i){
            MCAL_DIO_setPinDir(&(ptr->SEG7MENT[i]));
        }

    }

    return checkErrorState ;

}



/////////////////////////////////////////////////////////////////////////////_____+_+///



ErrorState  ECUAL_SEVEN_SEGMENT_displayNumber(_7SEGMENT_CFG *ptr , uint_8 number){

    ErrorState  checkErrorState = OK;
    if(NULL == ptr){
        checkErrorState = NOK ;
    }else {

    //    MCAL_DIO_setPinValue(&(ptr->SEG7MENT[0]),READ_BIT(number,0));
    //    MCAL_DIO_setPinValue(&(ptr->SEG7MENT[1]),READ_BIT(number,1));
    //    MCAL_DIO_setPinValue(&(ptr->SEG7MENT[2]),READ_BIT(number,2));
    //    MCAL_DIO_setPinValue(&(ptr->SEG7MENT[3]),READ_BIT(number,3));


        for(int i=0 ; i<4 ; ++i){
            MCAL_DIO_setPinValue(&(ptr->SEG7MENT[i]),READ_BIT(number,i));
        }
    
    }

    
return checkErrorState ;

}
