#include<iostream>
using namespace std;

class Fraction
{
	int integer; //целая часть
	int numerator; //числитель
	int denominator; //знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denomirator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//  Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefoltConstrucrot:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstructor";
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//       Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_proper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

};

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
/*	Fraction result;
	result.set_numerator(left.get_numerator()*right.);*/

/*	Fraction result
	{
		left.get_numerator() * right.to_numerator();
	left.get_denominator() * right.get_denominator();
	}*/

	return Fraction
	{
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_denominator()
	}.to_proper();
}
Fraction operator / (const Fraction& left, const Fraction right)
{
	return left*right.inverted();
}

//#define CONSTRACTION_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRACTION_CHECK
	
	Fraction A; //default constructor
	A.print();

	Fraction B = 5; // single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3 , 4);	D.print();
#endif // CONSTRACTION_CHECK

	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	A.to_improper().print();

	Fraction C = A / B;
	C.print();

}