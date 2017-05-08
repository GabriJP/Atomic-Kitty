L 1:
	R0=I(73719);
	R1=I(73715);
	R0=R0<R1;
	R2=U(73714);
	IF(!R2) GT(2);
	GT(3);
L 2:
	R3=I(73719);
	R4=I(73715);
	R3=R3-R4;
	GT(1);
L 4:
	GT(1);
L 5:
	R5=I(73719);
	R6=I(73723);
	R5=R5*R6;
L 3:
	GT(1);
L 6:
	GT(1);
L 7:
	R0=I(73723);
	I(73716)=R0;
	GT(0);
L 8:
	GT(0);
L 9:
	R0=0;	//Código de salida
	GT(-2);	//Fin de programa