#ifndef DATA_H
#define DATA_H

#include <iostream>

using std::ostream;
using std::istream;

class Data
{
private:
	int m_dia;
	int m_mes;
	int m_ano;
public:
	Data(int dia_, int mes_, int ano_);
	~Data();
	int getDia();
	int getMes();
	int getAno();
	bool isValid();
	int diffData(Data outra);

	friend ostream& operator<< ( ostream& o, const Data& d);

	friend istream& operator>> ( istream& i, Data& d);
};

#endif