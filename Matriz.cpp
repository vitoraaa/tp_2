#include "pch.h"
#include <iostream>
#include "Matriz.h"
#include <vector>
using namespace std;



Matriz::Matriz(int linhas, int colunas, const double& valor) {

	if (linhas > 0 && colunas > 0) {
		Linhas = linhas;
		Colunas = colunas;
		Dados = new double* [linhas];

		for (int i = 0; i < linhas; i++) {
			Dados[i] = new double[colunas];
		}
		inicializaValores(valor);
	}
	else {
		Linhas = 0;
		Colunas = 0;
		Dados = new double* [Colunas];
	}
}
Matriz::Matriz() {
	Linhas = 0;
	Colunas = 0;
	Dados = new double* [Colunas];
}
Matriz::Matriz(const Matriz& m) {


	Linhas = m.Linhas;
	Colunas = m.Colunas;
	Dados = new double* [Linhas];

	for (int i = 0; i < Linhas; i++) {
		Dados[i] = new double[Colunas];
	}
	inicializaValores(0);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {
			Dados[i][j] = m.Dados[i][j];
		}
	}

}
void Matriz::zeros() {
	inicializaValores(0);
}
void Matriz::inicializaValores(const double valor) {
	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			Dados[i][j] = valor;
		}
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
	if (linha > 0 && coluna > 0)return Dados[linha - 1][coluna - 1];
	else return Dados[0][0];
}
void Matriz::setDado(const int linha, const int coluna, const double valor) {

	if (linha > 0 && coluna > 0)Dados[linha - 1][coluna - 1] = valor;

}
Matriz& Matriz::operator=(const Matriz& a) {
	Linhas = a.Linhas;
	Colunas = a.Colunas;
	Dados = new double* [Linhas];

	for (int i = 0; i < Linhas; i++) {
		Dados[i] = new double[Colunas];
	}
	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {
			Dados[i][j] = a.Dados[i][j];
		}
	}

	return(*this);
}
Matriz Matriz::operator+(Matriz a) const {

	if (Linhas != a.Linhas || Colunas != a.Colunas) return *this;

	Matriz resultado = Matriz(Linhas, Colunas, 0);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			resultado.Dados[i][j] = Dados[i][j] + a.Dados[i][j];
		}
	}
	return resultado;
}
Matriz Matriz::operator-(Matriz a) const {

	if (Linhas != a.Linhas || Colunas != a.Colunas) return *this;

	Matriz resultado = Matriz(Linhas, Colunas, 0);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			resultado.Dados[i][j] = Dados[i][j] - a.Dados[i][j];
		}
	}
	return resultado;
}
void Matriz::operator+=(const Matriz a) {
	if (Linhas == a.Linhas && Colunas == a.Colunas) {

		for (int i = 0; i < Linhas; i++) {

			for (int j = 0; j < Colunas; j++) {

				Dados[i][j] = Dados[i][j] + a.Dados[i][j];
			}
		}
	}
}
Matriz Matriz::operator~() {

	Matriz resultado = Matriz(Colunas, Linhas);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			resultado.Dados[i][j] = Dados[j][i];
		}
	}
	return resultado;

}
void Matriz::operator-=(const Matriz a) {
	if (Linhas == a.Linhas && Colunas == a.Colunas) {
		for (int i = 0; i < Linhas; i++) {

			for (int j = 0; j < Colunas; j++) {

				Dados[i][j] = Dados[i][j] - a.Dados[i][j];
			}
		}
	}
}
Matriz Matriz::operator*(Matriz a) const {

	if (Linhas != a.Colunas || Colunas != a.Linhas) return *this;

	Matriz resultado = Matriz(Linhas, Colunas, 0);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			for (int k = 0; k < Colunas; k++) {
				resultado.Dados[i][j] += Dados[i][k] * a.Dados[k][j];
			}

		}
	}
	return resultado;
}
Matriz Matriz::operator*(double a)const {

	Matriz resultado = Matriz(Linhas, Colunas, 0);

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			resultado.Dados[i][j] = Dados[i][j] * a;
		}
	}

	return resultado;
}
void Matriz::operator*=(double a) {

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			Dados[i][j] = Dados[i][j] * a;
		}
	}
}
void Matriz::operator*=(const Matriz& a) {



	if (Linhas == a.Colunas && Colunas == a.Linhas) {

		//for (int i = 0; i < Linhas; i++) {

		//	for (int j = 0; j < Colunas; j++) {

		//		for (int k = 0; k < Colunas; k++) {
		//			Dados[i][j] += Dados[i][k] * a.Dados[k][j];
		//		}
		//	}
		//}
		Matriz auxiliar = Matriz(a.Linhas, a.Colunas);
		auxiliar = *this * a;
		for (int i = 0; i < Linhas; i++) {

			for (int j = 0; j < Colunas; j++) {

				Dados[i][j] = auxiliar.Dados[i][j];
			}
		}
	}
}
bool Matriz::operator==(const Matriz& a) const {

	if (Colunas != a.getColunas() || Linhas != a.getLinhas())return false;

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			if (Dados[i][j] != a.getDado(i + 1, j + 1))return false;
		}
	}


	return true;
}
bool Matriz::operator!=(const Matriz& a)const {
	if (Colunas != a.getColunas() || Linhas != a.getLinhas())return true;

	for (int i = 0; i < Linhas; i++) {

		for (int j = 0; j < Colunas; j++) {

			if (Dados[i][j] != a.getDado(i + 1, j + 1))return true;
		}
	}
	return false;
}
ostream& operator<<(ostream& out, const Matriz& a) {
	for (int i = 0; i < a.getLinhas(); i++) {

		for (int j = 0; j < a.getColunas(); j++) {

			out << a.getDado(i + 1, j + 1) << "   ";
		}

		out << "\n";
	}
	out << "\n\n";
	return out;
}
istream& operator>>(istream& in, const Matriz& a) {

	for (int i = 0; i < a.getLinhas(); i++) {

		for (int j = 0; j < a.getColunas(); j++) {

			in >> a.Dados[i][j];
		}

	}

	return in;
}
