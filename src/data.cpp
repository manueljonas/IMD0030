#include <iostream>

#include "data.h"

using std::string;

Data::Data(int dia_, int mes_, int ano_):m_dia(dia_), m_mes(mes_), m_ano(ano_) {
	if (!isValid()) {
		dia_ = 1;
		mes_ = 1;
		ano_ = 1900;
	}
}

Data::~Data() {}

int 
Data::getDia() {
	return m_dia;
}

int 
Data::getMes() {
	return m_mes;
}

int 
Data::getAno() {
	return m_ano;
}

bool 
Data::isValid() {
	if (m_dia<=0 || m_mes<=0 || m_ano<=0 || m_mes>12 || m_dia>31) {
		return false;
	}
	if (m_dia ==31 && (m_mes==2 || m_mes==4 || m_mes==6 || m_mes==9 || m_mes==11)) {
		return false;
	}
	if ((m_dia==30 && m_mes==2)) {
		return false;
	}
	if ((m_dia==29) && !(m_ano%4==0)) {
		return false;
	}
	return true;
}

int 
Data::diffData(Data outra) {
	return 0;
}

ostream& operator<< ( ostream& o, const Data& d){
	o << d.m_dia << "/" << d.m_mes << "/" << d.m_ano;
	return o;
}

istream& operator>> ( istream& i, Data& d){
	string data_;
	i.ignore();
	getline(i, data_);
	d.m_dia = atoi(data_.substr(0, 2).c_str()); 
    d.m_mes = atoi(data_.substr(3, 2).c_str()); 
    d.m_ano = atoi(data_.substr(6, 4).c_str());
	return i;
}
