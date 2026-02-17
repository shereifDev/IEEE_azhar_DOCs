/**************************** @author sherif osama abdelkareem   ********************* */
/**************************** @date     10Feb26                  ********************* */
/**************************** @file     interface_def.h          ********************* */





#ifndef      _INTERFACE_DEF_H_
#define      _INTERFACE_DEF_H_


#include <windows.h>

/**
 * @brief options which user can choose from them to do specific operation
 * @note used with switch statment
 */

#define        _1st_op             '1'
#define        _2nd_op             '2'
#define        _3rd_op             '3'
#define        _4th_op             '4'
#define        _5th_op             '5'
#define        _6th_op             '6'
 

/**
 * 
 * 
 * 
 * 
 * 
 */
        
#define        inf_loop             1
   
#define        starting_of_array    0
   
#define        NOT_FOUND            0 
#define        FOUND                1 


#define        WAIT_3SEC          Sleep(3000)

#define        PRE_ELEMENT(x)      x-1
#define        NEXT_ELEMENT(x)     x+1



enum status {
    
    dormant ,
    active  
};








#endif  /*_INTERFACE_DEF_H_*/


