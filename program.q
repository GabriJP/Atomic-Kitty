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
	GT( 1 ); # Skip function in global code

L 2:						# Function: fibo
	R0 = I(R6 - 0); # Load id:1 param: n from stack
	R1 = 0; 
	R0 = R0 == R1; # Operation with id 2 and id 3
	IF(!R0) GT(3);			# Comprobación condición if
	R0 = 0; 
	R1 = 0; 
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R1; # Asign value id:6 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 8) = R0; # Saving INT(268) tuple sub-element
	R0 = I( R6 + 4 ); # Load return label 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 0) = R1; # Saving it 
	R2 = I(R6 - 4); # Loading INT(268)
	I(R6 + 4) = R2; # Saving it 
	GT( R0 ); # Return 
	R7 = R7 + 8; # Releasing stack because block ends
	GT  (4);		# Fin bloque y salida a fin del if
L 3:			# Label de este elif
	R0 = I(R6 - 0); # Load id:1 param: n from stack
	R1 = 1; 
	R0 = R0 == R1; # Operation with id 10 and id 11
	IF(!R0) GT(5);	# Si no se cumple la condición se va al siguiente elif
	R0 = 1; 
	R1 = 0; 
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R1; # Asign value id:14 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 8) = R0; # Saving INT(268) tuple sub-element
	R0 = I( R6 + 4 ); # Load return label 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 0) = R1; # Saving it 
	R2 = I(R6 - 4); # Loading INT(268)
	I(R6 + 4) = R2; # Saving it 
	GT( R0 ); # Return 
	R7 = R7 + 8; # Releasing stack because block ends
	GT(3);					# Ir a salida
L 5:						# Label del else
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R6; # Asign value id:18 R6 saved
	R7 = R7 - 4; # Add to stack
	I(R6 - 8) = 6; # Asign id:19 Return Label
	R0 = I(R6 - 0); # Load id:1 param: n from stack
	R1 = 1; 
	R0 = R0 - R1; # Operation with id 20 and id 21
	R7 = R7 - 4; # Add to stack
	I(R6 - 12) = R0; # Asign value id:22 Parameters
	R6 = R7 + 0; # Update R6 
	GT( 2 ); # Call fibo
L 6: # Return Label
	R6 = I(R6 + 8); # Loading register R6
	R7 = R6 - 16; # Update R7 = R6 - R6.size - returned.size 
	R7 = R7 - 8; # Add to stack
	R0 = I(R6 - 12); # Loading INT(268)
	I(R6 - 20) = R0; # Saving it 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 16) = R1; # Saving it 
	R2 = I(R6 - 20); # Load id:27 sub-element 0 of tuple tupla
	R7 = R7 - 4; # Add to stack
	I(R6 - 24) = R2; # Asign value id:28 i = id:27 
	R2 = I(R6 - 16); # Load id:29 sub-element 1 of tuple tupla
	R7 = R7 - 4; # Add to stack
	I(R6 - 28) = R2; # Asign value id:30 j = id:29 
	R2 = I(R6 - 24); # Load id:28 i from stack
	R3 = I(R6 - 28); # Load id:30 j from stack
	R2 = R2 + R3; # Operation with id 31 and id 32
	R3 = I(R6 - 24); # Load id:28 i from stack
	R7 = R7 - 4; # Add to stack
	I(R6 - 32) = R3; # Asign value id:34 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 36) = R2; # Saving INT(268) tuple sub-element
	R2 = I( R6 + 4 ); # Load return label 
	R3 = I(R6 - 36); # Loading INT(268)
	I(R6 - 0) = R3; # Saving it 
	R4 = I(R6 - 32); # Loading INT(268)
	I(R6 + 4) = R4; # Saving it 
	GT( R2 ); # Return 
	R7 = R7 + 36; # Releasing stack because block ends
L 4:						# Label salida if
	R7 = R7 + 0; # Releasing stack because block ends
L 1: # End of function

	R7 = R7 - 4; # Add to stack
	I(0x11ff8) = R6; # Asign value id:38 R6 saved
	R7 = R7 - 4; # Add to stack
	I(0x11ff4) = 7; # Asign id:39 Return Label
	R7 = R7 - 4; # Add to stack
	I(0x11ff0) = R6; # Asign value id:40 R6 saved
	R7 = R7 - 4; # Add to stack
	I(0x11fec) = 8; # Asign id:41 Return Label
	R0 = 10; 
	R7 = R7 - 4; # Add to stack
	I(0x11fe8) = R0; # Asign value id:43 Parameters
	R6 = R7 + 0; # Update R6 
	GT( 2 ); # Call fibo
L 8: # Return Label
	R6 = I(R6 + 8); # Loading register R6
	R7 = R6 - 24; # Update R7 = R6 - R6.size - returned.size 
	R0 = I(0x11fe8); # Load id:45 sub-element 0 of tuple returned by fibo
	R2 = R0; # Loading print argument
	R1 = 0x11FFC; # Adress of print format
	R0 = 7; # Return Address
	GT(putf_); # Call print
L 7: # Return Label

	GT( -1 ); # Breakpoint for debug


	R0 = 0; # Exit code
	GT( -2 ); # Program end
END