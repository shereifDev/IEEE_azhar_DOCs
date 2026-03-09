/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_private.h           ****************/
/****************************************************************************/



#ifndef    GPIO_PRIVATE_H_
#define    GPIO_PRIVATE_H_



/* REGISTERS FOR PORTA */
#define         PINA          (*(volatile unsigned char*) 0x39)
#define         DDRA          (*(volatile unsigned char*) 0x3A)
#define         PORTA         (*(volatile unsigned char*) 0x3B)

/* REGISTERS FOR PORTB */
#define         PINB          (*(volatile unsigned char*) 0x36)
#define         DDRB          (*(volatile unsigned char*) 0x37)
#define         PORTB         (*(volatile unsigned char*) 0x38)

/* REGISTERS FOR PORTC */
#define         PINC          (*(volatile unsigned char*) 0x33)
#define         DDRC          (*(volatile unsigned char*) 0x34)
#define         PORTC         (*(volatile unsigned char*) 0x35)

/* REGISTERS FOR PORTD */
#define         PIND          (*(volatile unsigned char*) 0x30)
#define         DDRD          (*(volatile unsigned char*) 0x31)
#define         PORTD         (*(volatile unsigned char*) 0x32)


#endif  /*< GPIO_PRIVATE_H_*/