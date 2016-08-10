#include<iostream>
using namespace std;

class Rational{
private:
	int num;
	int den;
	int findMin();
public:
	Rational(int numerator, int denumerator);
	Rational(int wholeNumber);
	Rational();
	void normalizeSigns();
	void normalizeNumbers();
	friend ostream& operator<<(ostream &out, const Rational &r);
	friend istream& operator>>(istream &in, Rational &r);
	friend bool operator==(Rational &a, Rational &b);
	friend bool operator<(Rational &a, Rational &b);
	friend bool operator<=(Rational &a, Rational &b);
	friend bool operator>(Rational &a, Rational &b);
	friend bool operator>=(Rational &a, Rational &b);
	friend Rational operator+(Rational &a, Rational &b);
	friend Rational operator-(Rational &a, Rational &b);
	friend Rational operator*(Rational &a, Rational &b);
	friend Rational operator/(Rational &a, Rational &b);
};

Rational::Rational(int numerator, int denumerator): num(numerator), den(denumerator) {}
Rational::Rational(int wholeNumber) : num(wholeNumber), den(1){}
Rational::Rational() : num(0), den(1){}

void Rational::normalizeSigns(){
	if (num < 0 && den < 0)
	{
		num = -num;
		den = -den;
	}
	else if (num > 0 && den < 0)
	{
		num = -num;
		den = -den;
	}
}

int Rational::findMin(){
	if (abs(num) <= abs(den)) return abs(num);
	else return abs(den);
}

void Rational::normalizeNumbers(){
	for (int i = findMin(); i > 0; i--)
	if (num%i == 0 && den%i == 0)
	{
		num /= i;
		den /= i;
		break;
	}
}



ostream& operator<<(ostream &out,const Rational &r)
{
	out << r.num << "/" << r.den;
	return out;
}

istream& operator>>(istream  &in, Rational &r)
{
	char c;
	do
	{
		in >> r.num >> c >> r.den;
		if (r.den == 0) cout << "Denuminator must not be 0. Try again." << endl;
		if (c != '/') cout << "Input must be in form a/b. Try again." << endl;
	} while (c != '/' || r.den == 0);
	r.normalizeSigns();
	return in;
}

bool operator==(Rational &a, Rational &b){
	return (a.num*b.den == b.num*a.den);
}

bool operator<(Rational &a, Rational &b){
	return (a.num*b.den < b.num*a.den);
}

bool operator>(Rational &a, Rational &b){
	return (a.num*b.den > b.num*a.den);
}

bool operator>=(Rational &a, Rational &b){
	if (a == b) return true;
	else if (a > b) return true;
	else return false;
}

bool operator<=(Rational &a, Rational &b){
	if (a == b) return true;
	else if (a < b) return true;
	else return false;
}

Rational operator+(Rational &a, Rational &b){
	Rational c;
	c.den = a.den*b.den;
	c.num = a.num*b.den + b.num*a.den;
	c.normalizeNumbers();
	return c;
}

Rational operator-(Rational &a, Rational &b){
	Rational c;
	c.den = a.den*b.den;
	c.num = a.num*b.den - b.num*a.den;
	c.normalizeNumbers();
	return c;
}

Rational operator/(Rational &a, Rational &b){
	Rational c;
	c.num = a.num*b.den;
	c.den = a.den*b.num;
	c.normalizeNumbers();
	return c;
}

Rational operator*(Rational &a, Rational &b){
	Rational c;
	c.num = a.num*b.num;
	c.den = a.den*b.den;
	c.normalizeNumbers();
	return c;
}

int main(){
	Rational g, h;
	cout << "Enter two rational numbers in the form a/b:" << endl;
	cin >> g;
	cin >> h;
	Rational a = g + h, b=g-h, c=g*h, d=g/h;
	cout << "(g == h): " << (g == h) << endl;
	cout << "(g > h): " << (g > h) << endl;
	cout << "(g >= h): " << (g >= h) << endl;
	cout << "(g < h): " << (g < h) << endl;
	cout << "(g <= h): " << (g <= h) << endl;
	cout << "Sum: " << a << endl;
	cout << "Difference: " << b << endl;
	cout << "Product: " << c << endl;
	cout << "Division: " << d << endl;
	system("Pause");
	return 0;
}