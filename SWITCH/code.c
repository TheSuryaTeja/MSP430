#include <msp430.h>


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop Watch dog timer

    P1DIR |= BIT7; 				// P1.7 set as output
    P1DIR &= ~BIT6; 			// P1.6 set as input

while(1)
	
	{

    	if(P1IN & BIT6) 
        	while(P1IN & BIT6) 		// while the switch is pressed
            	 P1OUT |= BIT7; 	// P1.7 is high
    	else
        	P1OUT &= ~BIT7;    		// P1.7 is low
	}
}
