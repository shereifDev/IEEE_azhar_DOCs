/************************ @author  sherif osama abdle kareem  ****************** */
/************************ @version    0x01                    ****************** */
/************************ @file    7SEG_interface.h           ****************** */





#ifndef         _7SEG_INTERFACE_H
#define         _7SEG_INTERFACE_H



#include "DIO_interface.h"



/**
 * @brief Configuration structure for the 7-Segment Display.
 * 
 * This structure holds the GPIO configuration for the 4 pins 
 * used to control the 7-segment (typically connected via a BCD decoder).
 */
typedef struct {
    GPIO_PIN_CNFG  SEG7MENT[4] ; /**< Array of 4 GPIO pins representing BCD inputs */
}_7SEGMENT_CFG;

/**
 * @brief Initializes the 7-Segment pins.
 * 
 * Sets up the direction and initial state of the 4 pins specified in the 
 * configuration structure.
 * 
 * @param[in] ptr Pointer to the 7-segment configuration structure.
 * @return ErrorState Status of the initialization (e.g., SUCCESS or ERROR).
 */
ErrorState  ECUAL_SEVEN_SEGMENT_initialize(_7SEGMENT_CFG *ptr);

/**
 * @brief Displays a specific number on the 7-Segment.
 * 
 * Outputs the binary equivalent of the given number on the 4 configured pins.
 * 
 * @param[in] ptr Pointer to the 7-segment configuration structure.
 * @param[in] number The number to display (typically from 0 to 9).
 * @return ErrorState Status of the operation.
 */
ErrorState  ECUAL_SEVEN_SEGMENT_displayNumber(_7SEGMENT_CFG *ptr , uint_8 number);

#endif  /*<  _7SEG_INTERFACE_H*/


