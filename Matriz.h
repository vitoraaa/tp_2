#pragma once
#include <vector>
using namespace std;
class Matriz
{
	int Linhas, Colunas;
	double** Dados;
public:
	Matriz();
	Matriz(int linhas, int colunas, const double &valor);
	Matriz( const Matriz &m);
	~Matriz();

	int getRows();
	Matriz operator+( Matriz a);
	int getCols();
	void zeros();
	void imprimir();
	void inicializaValores( double valor);
	double getDado( int linha,  int coluna) const ;
	void setDado( int linha,  int coluna,  double valor);

};

