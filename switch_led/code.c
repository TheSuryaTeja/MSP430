#include <msp430.h>


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   	// stop Watch dog timer

    P1DIR |= BIT7; 			// P1.7 set as output
    P1DIR &= ~BIT6; 			// P1.6 set as input

while(1)
	
	{

    	if(P1IN & BIT6) {

            // uncomment the following delay to avoid debouncing errors.
           // __delay_cycles(20000);

        	while(P1IN & BIT6) 	// while the switch is pressed
            	 P1OUT |= BIT7; 	// set P1.7 as high
        }
        
    	else
        	P1OUT &= ~BIT7;    	// set P1.7 as low
	}
}
