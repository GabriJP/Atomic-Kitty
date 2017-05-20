#include "Q.h" 
#define C R7    // cima de la pila 
#define B R6    // base del marco actual 

BEGIN 

L 0:
	R6 = R7;
	GT( 1 ); # Skip function in global code

L 2:						# Function: fibo
	R0 = I(R6 - 0); # Load id:0 param: n from stack
	R1 = 0; 
	R0 = R0 == R1; # Operation with id 1 and id 2
	IF(!R0) GT(3);			# Comprobación condición if
	R0 = 0; 
	R1 = 0; 
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R1; # Asign value id:5 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 8) = R0; # Saving INT(268) tuple sub-element
	R0 = I( R6 + 4 ); # Load return label 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 0) = R1; # Saving it 
	R2 = I(R6 - 4); # Loading INT(268)
	I(R6 + 4) = R2; # Saving it 
	GT( R0 ); # Return 
	GT  (4);		# Fin bloque y salida a fin del if
L 3:			# Label de este elif
	R0 = I(R6 - 0); # Load id:0 param: n from stack
	R1 = 1; 
	R0 = R0 == R1; # Operation with id 9 and id 10
	IF(!R0) GT(5);	# Si no se cumple la condición se va al siguiente elif
	R0 = 1; 
	R1 = 0; 
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R1; # Asign value id:13 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 8) = R0; # Saving INT(268) tuple sub-element
	R0 = I( R6 + 4 ); # Load return label 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 0) = R1; # Saving it 
	R2 = I(R6 - 4); # Loading INT(268)
	I(R6 + 4) = R2; # Saving it 
	GT( R0 ); # Return 
	GT(3);					# Ir a salida
L 5:						# Label del else
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R6; # Asign value id:17 R6 saved
	R7 = R7 - 4; # Add to stack
	I(R6 - 8) = 6; # Asign id:18 Return Label
	R0 = I(R6 - 0); # Load id:0 param: n from stack
	R1 = 1; 
	R0 = R0 - R1; # Operation with id 19 and id 20
	R7 = R7 - 4; # Add to stack
	I(R6 - 12) = R0; # Asign value id:21 Parameters
	R6 = R7 + 0; # Update R6 
	GT( 2 ); # Call fibo
L 6: # Return Label
	R6 = I(R6 + 8); # Loading register R6
	R7 = R6 - 12; # Update R7 = R6 - R6.size - returned.size 
	R7 = R7 - 8; # Add to stack
	R0 = I(R6 - 12); # Loading INT(268)
	I(R6 - 20) = R0; # Saving it 
	R1 = I(R6 - 8); # Loading INT(268)
	I(R6 - 16) = R1; # Saving it 
	R2 = I(R6 - 20); # Load id:26 sub-element 0 of tuple tupla
	R7 = R7 - 4; # Add to stack
	I(R6 - 24) = R2; # Asign value id:27 i = id:26 
	R2 = I(R6 - 16); # Load id:28 sub-element 1 of tuple tupla
	R7 = R7 - 4; # Add to stack
	I(R6 - 28) = R2; # Asign value id:29 j = id:28 
	R2 = I(R6 - 24); # Load id:27 i from stack
	R3 = I(R6 - 28); # Load id:29 j from stack
	R2 = R2 + R3; # Operation with id 30 and id 31
	R3 = I(R6 - 24); # Load id:27 i from stack
	R7 = R7 - 4; # Add to stack
	I(R6 - 32) = R3; # Asign value id:33 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 36) = R2; # Saving INT(268) tuple sub-element
	R2 = I( R6 + 4 ); # Load return label 
	R3 = I(R6 - 36); # Loading INT(268)
	I(R6 - 0) = R3; # Saving it 
	R4 = I(R6 - 32); # Loading INT(268)
	I(R6 + 4) = R4; # Saving it 
	GT( R2 ); # Return 
L 4:						# Label salida if
L 1: # End of function

	R7 = R7 - 4; # Add to stack
	I(0x11ffc) = R6; # Asign value id:37 R6 saved
	R7 = R7 - 4; # Add to stack
	I(0x11ff8) = 7; # Asign id:38 Return Label
	R0 = 40; 
	R7 = R7 - 4; # Add to stack
	I(0x11ff4) = R0; # Asign value id:40 Parameters
	R6 = R7 + 0; # Update R6 
	GT( 2 ); # Call fibo
L 7: # Return Label
	R6 = I(R6 + 8); # Loading register R6
	R7 = R6 - 12; # Update R7 = R6 - R6.size - returned.size 
	R7 = R7 - 8; # Add to stack
	R0 = I(0x11ff4); # Loading INT(268)
	I(0x11fec) = R0; # Saving it 
	R1 = I(0x11ff8); # Loading INT(268)
	I(0x11ff0) = R1; # Saving it 

	GT( -1 ); # Breakpoint for debug


	R0 = 0; # Exit code
	GT( -2 ); # Program end
END