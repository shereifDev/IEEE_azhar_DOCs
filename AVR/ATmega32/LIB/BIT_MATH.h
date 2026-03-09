/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  BIT_MATH.h               ****************/
/****************************************************************************/









#ifndef   BIT_MATH_H_
#define   BIT_MATH_H_


#define        SET_BIT(reg , bit)	    reg|=(1<<bit)
#define        CLR_BIT(reg , bit)	    reg&=(~(1<<bit)) 
#define        READ_BIT(reg , bit)     (reg&(1<<bit))>>bit    
#define        TOGG_BIT(reg , bit)	    reg^=(1<<bit)



#endif  /*<BIT_MATH_H_*/


