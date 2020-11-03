#include <msp430.h>


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;          // stop Watch dog timer

    P1DIR |= BIT7; 			//P1.7 set as output

while(1){

    volatile unsigned long i;

    P1OUT |= BIT7; 			// P1.7 set to high
    for(i=0;i<1000;i++); 		// delay

    P1OUT &= ~BIT7;    			// P1.7 set to low
    for(i=0;i<1000;i++); 		//delay
    
    }
