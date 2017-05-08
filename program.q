L 1:						//Label de función: fact
	R0=I(73719);			//Se carga 3
	R1=I(73715);			//Se carga 4
	R0=R0<R1;				//Operación: <
	R2=U(73714);			//Se carga 5
	IF(!R2) GT(2);			//Comprobación condición if
//Aquí hay un RETURN
	GT(3);					//Ir a salida
L 2:						//Label del else
	R3=I(73719);			//Se carga 3
	R4=I(73715);			//Se carga 7
	R3=R3-R4;				//Operación: -
	R6=R7;
	R7=R7+8
	R6=4;
	R5=I(73719);
GT(4);
	GT(1);				//Ir a función: fact
L 5:					//Label para vuelta de funcion
	R6=I(73719);			//Se carga 3
	R0=I(73723);			//Se carga 2
	R6=R6*R0;				//Operación: *
//Aquí hay un RETURN
L 3:						//Label salida if
	R6=R7;
	R7=R7+8
	R6=6;
	R1=I(73724);
GT(6);
	GT(1);				//Ir a función: fact
L 7:					//Label para vuelta de funcion
	R2=I(73723);			//Se carga 2
	I(73716)=R2;
	R6=R7;
	R7=R7+4
	R6=8;
GT(8);
	GT(0);				//Ir a función: print
L 9:					//Label para vuelta de funcion
	R0=0;					//Código de salida
	GT(-2);					//Fin de programa