#include "Money.h"

Money::Money() : grn(0), kop(0)
{ }
Money::Money(const long x, const unsigned int y)
{
	long a = x;
		unsigned int b = y;
		while (b > 99)
		{
			b -= 100;
			a++;
		}
		while (b < -99)  
		{
			b += 100;
			a--;
		}
		setGrn(a);
		setKop(b);
}
Money::Money(double x)
{
	long a = (long)x;
	x -= a;
	x *= 100;
	unsigned long b = (unsigned long)x;
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money::Money(const Money& x)
{
	int a = x.getGrn();
	int b = x.getKop();
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}
	setGrn(a);
	setKop(b);
}
Money::~Money(void)
{}
Money operator -(const Money& x, const Money& y)
{
	Money t;
	if ((x.getGrn() < y.getGrn()) && (x.getKop() < y.getKop()))
	{
		t.setGrn(0);
		t.setKop(0);

		return t;
	}
	else
		if (x.getKop() < y.getKop())
		{
			t.setGrn((x.getGrn() - 1) - y.getGrn());
			t.setKop(100 - (y.getKop() - x.getKop()));
			return t;
		}
		else
		{
			t.setGrn(x.getGrn() - y.getGrn());
			t.setKop(x.getKop() - y.getKop());
			return t;
		}
}
Money operator *(const Money& x,const  double y)
{
	Money t;
	long a = (x.getGrn() * y);
	unsigned long b = (x.getKop() * y);

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}

Money& Money::operator ++()
{
	int x = this->getGrn();
	int y = this->getKop();
	x++;
	y++;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
Money& Money::operator --()
{
	int x = this->getGrn();
	int y = this->getKop();
	x--;
	y--;
	this->setGrn(x);
	this->setKop(y);

	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x++;
	y++;

	this->setGrn(x);
	this->setKop(y);

	return t;
}
Money Money::operator --(int)
{
	Money t(*this);

	int x = this->getGrn();
	int y = this->getKop();

	x--;
	y--;

	this->setGrn(x);
	this->setKop(y);

	return t;
}
string format(unsigned long x)
{
	stringstream ss;
	if (x < 10)
	{
		ss << "0";
	}
	ss << x;
	return ss.str();
}
Money::operator string() const
{
	stringstream ss;
	ss << getGrn() << ", " << format(getKop()) << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Money& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, Money& x)
{
	long a;
	unsigned long b;
	cout << "Grn = "; in >> a;
	cout << "Kop = "; in >> b;
	x.setGrn(a);
	x.setKop(b);
	return in;
}
bool Money::operator==(const Money& x)
{
	return this->getGrn() == x.getGrn() && this->getKop() == x.getKop();
}
bool Money::operator >(const Money& x)
{
	if (this->getGrn() > x.getGrn())
		return 1;
	else
		if ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop()))
			return 1;
		else
			return 0;
}
bool Money::operator <(const Money& x)
{
	if (this->getGrn() < x.getGrn())
		return 1;
	else
		if ((this->getGrn() == x.getGrn()) && (this->getKop() < x.getKop()))
			return 1;
		else 
			return 0;
}