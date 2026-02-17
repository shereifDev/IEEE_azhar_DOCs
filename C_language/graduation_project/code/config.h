/********************* @author sherif osama abdelkareem              ********************* */
/********************* @date     10Feb26                             ********************* */
/********************* @file     config.h                            ********************* */
/********************* @brief header file for system configuarations ********************* */
/********************* @version   0x00                               ********************* */







#ifndef      _CONFIG_H_
#define      _CONFIG_H_



#define       ADMIN_ID                           100200UL
#define       ADMIN_PASS                       "hello@890"
     
#define       MAX_PASSWORD_SIZE                    20
#define       MAX_LETTERS_NAME_NUMBER              50
#define       MAX_LETTERS_ADDRESS_NUMBER           60
#define       MAX_NUMBERS_PHONE_NUMBER             11


#define       ACCOUNT_DEFUALT_PASSWORD           "1234"
#define       DEFAULT_BALANCE                     0.00f               

#define       ACCOUNT_ID_OFFSET                 100000UL
#define       DEFAULT_ACCOUNT_ID(N_ID)       (((N_ID) * 3) + ACCOUNT_ID_OFFSET)      

#define       MAX_CUSTOMERS_NUMBER                 50






#endif  /*__CONFIG_H_*/
