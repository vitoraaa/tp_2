#include "pch.h"
#include <iostream>
#include "Matriz.h"
#include <vector>
using namespace std;


Matriz::Matriz()
{
}

Matriz::Matriz(int linhas, int colunas, const double &valor = 0) {
	Linhas = linhas;
	Colunas = colunas;
	Dados = new double*[linhas];

	for (unsigned int i = 0; i < linhas; i++) {
		Dados[i] = new double[colunas];
	}

	inicializaValores(valor);

}

Matriz::Matriz(const Matriz &m) {

	Linhas = m.Linhas;
	Colunas = m.Colunas;
	Dados = m.Dados;
}

int Matriz::getRows() {
	return Linhas;
}

int Matriz::getCols() {
	return Colunas;
}

void Matriz::zeros() {

}

void Matriz::inicializaValores(const double valor) {
	for (unsigned i = 0; i < Linhas; i++) {

		for (unsigned j = 0; j < Colunas; j++) {

			Dados[i][j] = valor;
		}
		std::cout << "\n";
	}
}

Matriz::~Matriz()
{
	for (int i = 0; i < Linhas; ++i) {
		delete[] Dados[i];
	}
	delete[] Dados;
}
double Matriz::getDado(const int linha, const int coluna) const {
	return Dados[linha][coluna];
}
void Matriz::setDado(const int linha, const int coluna, const double valor) {
	Dados[linha][coluna] = valor;
}
void Matriz::imprimir()
{
	for (unsigned i = 0; i < Linhas; i++) {

		for (unsigned j = 0; j < Colunas; j++) {

			std::cout << Dados[i][j] << "   ";
		}
		std::cout << "\n";
	}

	std::cout << "\n\n";
}

Matriz Matriz::operator+(const Matriz a) {

	Matriz resultado = Matriz(Linhas, Colunas);

	for (unsigned i = 0; i < Linhas; i++) {

		for (unsigned j = 0; j < Colunas; j++) {

			resultado.setDado(i, j, getDado(i, j) + a.getDado(i, j));
		}
	}
	return resultado;
}
