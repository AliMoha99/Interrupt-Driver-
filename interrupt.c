/*
 * interrupt.c
 *
 *  Created on: Jul 18, 2020
 *      Author: MeGa
 */

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

int main()
{
DDRD|=(1<<PD7);
GICR=0B01000000;   //  enable global interrupt ///// and rising edge // enable the kind of interrupt (int0 ,int1,int2)
MCUCR=0B00000011; //  enable global interrupt ///// and rising edge
GIFI=0B01000000;
SREG|=(1<<PD7);        //search the data sheet


while(1)
{
PORTD&=!(1<<PD7);
}
return 0;
}

ISR(INT0_vect)
{
	DDRD|=(1<<PD7);
	_delay_ms(1000);

}
