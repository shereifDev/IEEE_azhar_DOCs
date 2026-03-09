/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SPI_interface.h          ****************/
/****************************************************************************/



#ifndef   SPI_INTERFACE_H_
#define   SPI_INTERFACE_H_

/*________________include part______________*/

#include "STD_types.h"


#define      SPI_MASTER_MODE     0
#define      SPI_SLAVE_MODE      1


#define      F_OSC_DIV_4         0   // Normal Speed: fosc/4
#define      F_OSC_DIV_16        1   // Normal Speed: fosc/16
#define      F_OSC_DIV_64        2   // Normal Speed: fosc/64
#define      F_OSC_DIV_128       3   // Normal Speed: fosc/128
#define      F_OSC_DIV_2         4   // Double Speed: fosc/2
#define      F_OSC_DIV_8         5   // Double Speed: fosc/8
#define      F_OSC_DIV_32        6   // Double Speed: fosc/32




/**************************</Function Prototypes>************************ */

/**
 * @brief 
 * 
 * 
 * 
 * 
 */

void HAL_SPI_init(void);

/**
 * @brief 
 * 
 * 
 * 
 * 
 */

void HAL_SPI_MasterTransmit(uint_8 Data);

/**
 * @brief 
 * 
 * 
 * 
 * 
 */

uint_8 HAL_SPI_SlaveReceive(void);




#endif /*<SPI_INTERFACE_H_*/
