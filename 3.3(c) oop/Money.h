#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Object.h"

using namespace std;

class Money : public Object
{
private:
	long grn;
	unsigned int kop;
public:
	Money();
	Money(const long grn, const unsigned int cop);
	Money(const double x);
	Money(const Money& x);
	~Money();

	long getGrn() const { return grn; }
	unsigned int getKop() const { return kop; }
	
	void setGrn(long grn) { this->grn = grn; }
	void setKop(unsigned int kop) { this->kop = kop; }
	
	operator string() const;
	
	friend Money operator -(const Money&, const Money&);
	friend Money operator *(const Money&, const double);
	
	bool operator ==(const Money&);
	bool operator <(const Money&);
	bool operator >(const Money&);
	
	friend ostream&	operator <<(ostream&, const Money&);
	friend istream&	operator >>(istream&, Money&);
	
	Money& operator ++();
	Money operator ++(int);	
	Money& operator --();
	Money operator --(int);
};

