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
	R7 = R6 - 16; # Update R7 = R6 - R6.size - returned.size 
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

	GT( 7 ); # Skip function in global code

L 8:						# Function: f
	R0 = I(R6 - 4); # Load id:38 sub-element 0 of tuple param: s
	R7 = R7 - 4; # Add to stack
	I(R6 - 8) = R0; # Asign value id:39 m = id:38 
L 10:
	R0 = I(R6 - 8); # Load id:39 m from stack
	R1 = 10; 
	R0 = R0 != R1; # Operation with id 40 and id 41
	IF( !R0 ) GT(9);
	R1 = I(R6 - 8); # Load id:39 m from stack
	R2 = 1; 
	R1 = R1 - R2; # Operation with id 42 and id 43
	I(R6 - 8) = R1; # Asign value id:39 m = id:42 
	GT(10);
L 9:
	R1 = I(R6 - 8); # Load id:39 m from stack
	R2 = I(R6 - 0); # Load id:45 sub-element 1 of tuple param: s
	R3 = 1; 
	R2 = R2 + R3; # Operation with id 45 and id 46
	R7 = R7 - 4; # Add to stack
	I(R6 - 12) = R2; # Asign value id:47 tuple init
	R7 = R7 - 4; # Update size for tuple
	I(R6 - 16) = R1; # Saving INT(268) tuple sub-element
	R1 = I( R6 + 4 ); # Load return label 
	R2 = I(R6 - 16); # Loading INT(268)
	I(R6 - 0) = R2; # Saving it 
	R3 = I(R6 - 12); # Loading INT(268)
	I(R6 + 4) = R3; # Saving it 
	GT( R1 ); # Return 
L 7: # End of function

	GT( 11 ); # Skip function in global code

L 12:						# Function: bucle
	R0 = 2; 
	R1 = 6; 
	R7 = R7 - 4; # Add to stack
	I(R6 - 4) = R0; # Asign value id:52 
	R7 = R7 - 4; # Add to stack
	I(R6 - 8) = R1; # Asign value id:53 
	R7 = R7 - 4; # Add to stack
	I(R6 - 12) = 1; # Asign id:54 
	R7 = R7 - 4; # Add to stack
	R0 = I(R6 - 4); # Load id:52  from stack
	R1 = I(R6 - 4); # Load id:52  from stack
	I(R6 - 16) = R1; # Asign value id:55 id loop iterator = id:52 
	GT( 15 ); # dont update iterator the first time
L 13: # for loop tag
	R1 = I(R6 - 12); # Load id:54  from stack
	R2 = I(R6 - 16); # Load id:55 id loop iterator from stack
	R2 = R2 + R1; # Update for range
	I(R6 - 16) = R2; # Asign value id:55 id loop iterator
L 15: # for condition label 
	R4 = I(R6 - 8); # Load id:53  from stack
	R5 = I(R6 - 16); # Load id:55 id loop iterator from stack
	R3 = R5 == R4; # Check for end
	IF( R3 ) GT( 14 ); # Update for range
	R7 = R7 - 4; # Add to stack
	R0 = I(R6 - 0); # Load id:51 param: m from stack
	R7 = R7 - 4; # Add to stack
	R1 = I(R6 - 16); # Load id:55 id loop iterator from stack
	R0 = R0 + R1; # Operation with id 63 and id 64
	I(R6 - 0) = R0; # Asign value id:51 param: m = id:63 
	GT(13);
L 14:
	R0 = I(R6 - 0); # Load id:51 param: m from stack
	R1 = I( R6 + 4 ); # Load return label 
	I( R6 + 4 ) = R0; # Saving return id:65
	GT( R1 ); # Return 
L 11: # End of function

	R7 = R7 - 4; # Add to stack
	I(0x11ffc) = R6; # Asign value id:67 R6 saved
	R7 = R7 - 4; # Add to stack
	I(0x11ff8) = 16; # Asign id:68 Return Label
	R0 = 0; 
	R7 = R7 - 4; # Add to stack
	I(0x11ff4) = R0; # Asign value id:70 Parameters
	R6 = R7 + 0; # Update R6 
	GT( 12 ); # Call bucle
L 16: # Return Label
	R6 = I(R6 + 8); # Loading register R6
	R7 = R6 - 8; # Update R7 = R6 - R6.size - returned.size 
	R7 = R7 - 4; # Add to stack
	R0 = I(0x11ff8); # Load id:71 returned by bucle from stack
	I(0x11ff4) = R0; # Asign value id:72 g = id:71 

	GT( -1 ); # Breakpoint for debug


	R0 = 0; # Exit code
	GT( -2 ); # Program end
END