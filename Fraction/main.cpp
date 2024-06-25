#include<iostream>
using namespace std;
//#define delimiter "\n-------------------------------------n\"

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
	void set_denominator(int denominator)
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
	/*explicit*/ Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstructor:" << this << endl;
	}

	/*Fraction(double decimal)
	{
		integer = decimal; //decimal - десятичный
		decimal -= integer; //убираем целую часть из десятичной дроби
		denominator = 1e+9; //записываем максимально-возможный знаменатель
		numerator = decimal * denominator;

		cout << "DoubleConstructor:\t" << this << endl;
	}*/

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

	/*	Fraction(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyConstructor: \t" << this << endl;
		}*/
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//                     Type - cast operators:
	//type name(parameters)
	/*explicit operator int()
	{
		return to_proper().integer;
		//to_proper();
		//return integer;
	}*/

	/*	explicit operator double()const
		{
			return integer + (double)numerator / denominator;
		}*/

		//                          Methods:
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
		/*Fraction inverted()const
		{
			Fraction inverted = *this;
			inverted.to_proper();
			swap(inverted.numerator, inverted.denominator);
			return inverted;
		}*/

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
	Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());
	return result;

}
	/*	Fraction result;
		result.set_numerator(left.get_numerator()*right.);*/

		/*	Fraction result
			{
				left.get_numerator() * right.to_numerator();
			left.get_denominator() * right.get_denominator();
			}*/

			/*return Fraction
			{
				left.get_numerator() * right.get_denominator(),
				left.get_denominator() * right.get_denominator()
			}.to_proper();
		}*/
		/*Fraction operator / (const Fraction& left, const Fraction right)
		{
			return left*right.inverted();
		}*/

//#define CONSTRUCTORS_CHECK
//#define CONVERTION_FROM_OTHER_TO_CLASS
//#define CONVERSION_HOME_WORK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	Fraction A; //default constructor
	A.print();

	Fraction B = 5; // single-argument constructor
	B.print();

	Fraction C(1, 2); //обычный параметризованный конструктор
	C.print();

	Fraction D(2, 3, 4);
	D.print();

#endif // CONSTRUCTORS_CHECK

#ifdef CONVERSION_HOME_WORk
	Fraction A = 2.75; //Conversion from 'double' to 'Fraction'
	cout << A << endl;
#endif // CONVERSION_HOME_WORK

	/*	Fraction A(2, 3, 4);
		A.to_improper();
		cout << A << endl;

		int a = A;
		cout << a << endl;
		double da = A;
		cout << da << endl;*/

	    Fraction A(2, 3, 4);
		A.print();
		Fraction B(3, 4, 5);
		B.print();
		A.to_improper().print();
		A.to_proper().print();

		Fraction C = A * B;
		C.print();
		/*cout << delimiter << endl;*/

		/*Fraction A = (Fraction)5;

		cout << A << endl;
		cout << delimiter << endl;

		Fraction B;  //Default constractor
		B = Fraction(8);       //Convertion from less to more
					 //CopyAssignment
		cout << delimiter << endl;
		cout << B << endl;
		cout << delimiter << endl;*/

}