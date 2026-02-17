/**************************** @author sherif osama abdelkareem   ********************* */
/**************************** @date     10Feb26                  ********************* */
/**************************** @file     std_types.h              ********************* */




#ifndef       _STD_TYPES_H_   
#define       _STD_TYPES_H_ 



#include "config.h"



typedef       unsigned int             uint_32 ;
typedef       unsigned short           uint_16 ;
typedef       unsigned char            uint_8  ;
typedef       unsigned  long long int  uint_64 ;



typedef        short                   int_16 ;
typedef        int                     int_32 ;
typedef        char                    int_8  ;
     
     
     
typedef        float                   f_32   ;
typedef        double                  f_64   ;
typedef        long double             f_128  ;



typedef struct {
    
    char day[3];
    char month[3];
    char year[5];

}date_of_birth;
  


typedef  struct 
{
    uint_8   Account_Status                               ;         
    uint_16   Age                                         ;         
    f_64     Balance                                      ;         
    uint_64  Bank_Account_ID                              ;       
    uint_32  Phone_Number                                 ;                                
    uint_64  National_ID                                  ;      
    uint_8   Password       [MAX_PASSWORD_SIZE]           ;            
    uint_8   Full_Name      [MAX_LETTERS_NAME_NUMBER]     ;           
    uint_8   Address        [MAX_LETTERS_ADDRESS_NUMBER]  ;    
    date_of_birth date                                    ;
    
} custmer_account ;







#endif  /*_STD_TYPES_H_*/  


