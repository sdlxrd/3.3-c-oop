#include <iostream>
#include "Money.h"
using namespace std;
int main()
{
	Money a(0, 0), b(0, 0);
	double x;
	
	cout << "First:" << endl; cin >> a;
	cout << endl;
	cout << "Second:" << endl; cin >> b;
	cout << "x = "; cin >> x;
	cout<< endl << "a - b = "  << a- b;
	cout << "a * x = " << a * x;
	cout << "b * x = " << b * x << endl;
	
	if (a==b)
		cout << a.getGrn() << ", " << a.getKop()  << " = " << b.getGrn() << ", " << b.getKop() << endl;
	if (a < b)
		cout << a.getGrn() << ", " << a.getKop()  << " < " << b.getGrn() << ", " << b.getKop() << endl;
	if (a > b)
		cout << a.getGrn() << ", " << a.getKop()  << " > " << b.getGrn() << ", " << b.getKop() << endl;
	cout << "Count of objects = " << Object::getCount() << endl << endl;
	cin.get();
	cin.get();
	system("cls");
	cout << "a++: " << a++;
	cout << "result = " << a << endl;
	cout << "++a: " << ++a << endl; 
	
	cout << "a--: " << a--;
	cout << "result = " << a << endl;
	
	cout << "--a: " << --a << endl;

}