#include "Q.h" 
#define C R7    // cima de la pila 
#define B R6    // base del marco actual 

BEGIN 

L 0:
	R6 = R7;
STAT(0)
	STR( 0x11FFC, "%d\n");
CODE(0)
GT( -1 );
	R7 = R7 - 4; # Add to stack
	I(0x11ffc) = R6; # Asign value id:0 R6 saved
	R7 = R7 - 4; # Add to stack
	I(0x11ff8) = 1; # Asign id:1 Return Label
	R0 = 2; 
	R2 = R0; # Loading print argument
	R1 = 0x11FFC; # Adress of print format
	R0 = 1; # Return Address
	GT(putf_); # Call print
L 1: # Return Label

	GT( -1 ); # Breakpoint for debug


	R0 = 0; # Exit code
	GT( -2 ); # Program end
END