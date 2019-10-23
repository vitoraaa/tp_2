
#include "pch.h"
#include <iostream>
#include "Matriz.h"

int main()
{
    
	Matriz A = Matriz(3,3,1);
	Matriz B = Matriz(3, 3, 2);
	A.imprimir();
	B.imprimir();
	A = A + B;
	A.imprimir();
	B.imprimir();
	return 0;
}

