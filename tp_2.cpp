
#include "pch.h"
#include <iostream>
#include "Matriz.h"

int main()
{

	Matriz Y;
	Matriz X(3, 3, 7), A(3, 3, 5), C(3, 3, 3);
	Y = X;
	Matriz W = C;
	Matriz Z(A);
	int numeroLinhas = A.getLinhas();
	int numeroColunas = A.getColunas();
	cout << "A\n" << A;
	A.setDado(2, 1, 10); // altera o valor de uma posi��o de A
	Y.zeros(); // modifica todos os elementos de Y para o valor zero
	cout << "A\n" << A;
	C = A + A; // Soma
	cout << "C\n" << C;
	C -= A; // Subtra��o
	cout << "C\n" << C;
	A = C - A; // Subtra��o
	cout << "A\n" << A;
	A += A; // Soma
	cout << "A\n" << A;
	A = ~C; // A � igual a transposta de C
	cout << "A\n" << A;
	X = A;
	X *= 2; // multiplica��o por uma constante
	cout << "X\n" << X;
	C = A * X; // multiplica��o de matrizes
	cout << "C \n" << C;
	C *= A; // multiplica��o de matrizes
	cout << "C \n" << C;
	if (A == C) {
		printf("A e igual a C");
	}
	else printf("A e diferente de C");
	// verifica a igualdade entre A e C
	if (X != Y) {
		printf("X e diferente de Y");
	}
	else printf("X e igual Y"); // verifica a desigualdade entre A e C

	cout << C << endl; // Impress�o de matrizes
	cin >> Y;
	cout << "Y\n" << Y;

	return 0;
}

