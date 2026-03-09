/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SPI_config.h             ****************/
/****************************************************************************/



#ifndef   SPI_CONFIG_H_
#define   SPI_CONFIG_H_


/**************************</include part>************************ */

#include  "SPI_interface.h"



/**
 * @brief  use this macro to select the op of the device 
 *         u have two choise 
 *                         1- set as a 'MASTER'
 *                         2- set as a 'SLAVE'
 */

#define         SPI_MODE        SPI_MASTER_MODE 



#if SPI_MODE  ==   SPI_MASTER_MODE 

/**
 * @brief  Use this Macro to Select the Master CLK Rate 
 * @note   U have Seven Choice:
 * 1- F_OSC_DIV_4   2- F_OSC_DIV_16   3- F_OSC_DIV_64 
 * 4- F_OSC_DIV_128  5- F_OSC_DIV_2    6- F_OSC_DIV_8   7- F_OSC_DIV_32
 * 
 */

#define          CLK_RATE         F_OSC_DIV_64      






#endif /*<_SPI_MODE_*/








#endif /*<SPI_CONFIG_H_*/
