#pragma once
#include <vector>
using namespace std;
class Matriz
{
	int Linhas, Colunas;
	double** Dados;
public:
	Matriz();
	Matriz(int linhas, int colunas, const double &valor = 0);
	Matriz( const Matriz &m);
	~Matriz();
	int getColunas()const { return Colunas; };
	int getLinhas()const { return Linhas; };
	Matriz operator+(const Matriz a) const;
	Matriz operator-(const Matriz a) const ;
	void operator+=(const Matriz a);
	void operator-=(const Matriz a);
	Matriz operator*(const Matriz a) const;
	Matriz operator~();
	Matriz operator*(const double a) const;
	void operator*=(const double a);
	void operator*=(const Matriz &a);
	bool operator==(const Matriz &a) const;
	bool operator!=(const Matriz &a)const ;
	friend ostream& operator<<(ostream& out, const Matriz& a);
	friend istream& operator>>(istream& in, const Matriz& a);
	Matriz& operator=(const Matriz &a);
	void zeros();
	void inicializaValores( double valor);
	double getDado( int linha,  int coluna) const ;
	void setDado( int linha,  int coluna,  double valor);

};

