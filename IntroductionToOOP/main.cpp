﻿#include<iostream>
using namespace std;
#define delimiter "\n----------------------------------------------\n"

//Объявляя структуру или класс мы создаем новый тип данных (пользовательский тип данных)
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	/*Point()
	{
		x = y = 0;
		cout << "DefoltConstructor: \t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor: \t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t \t" << this << endl;
	}

	//Operators:
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: \t\t" << this << endl;
		return *this;
	}

	Point& operator++() //префиксный инкремент
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	// Methods д/з от 04.06.24:
	double distance(Point& other) //передаем объект в ф-цию по ссылке
								  //double distance(Point other
								  //- передаем объект в ф-цию по значению
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt() - Square Root (Квадратный корень)
		return distance;
	}


	void print()const
	{
		cout << "X = " << x << "\ty = " << y << endl;
	}
};

	double distance(Point& A, Point& B) //передаем объект в ф-цию по ссылке
									    //double distance(Point A, Point B) 
									    //- передаем объект в ф-цию по значению
	{
		double x_distance = A.get_x() - B.get_x();
		double y_distance = A.get_y() - B.get_y();
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

std::ostream& operator << (std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef   STRUCT_POINT
	//cout << "Hello OOP" << endl;
	int a;       //Объявление переменной 'a' типа 'int'
	Point A;     //Объявление переменной 'A' типа 'Point'
	             //Создание объекта 'A' типа 'Point'
	             //Создание экземпляра 'A' типа 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif //   STRUCT_POINT
#ifdef CONSTRUCTORS_CHECK

	Point A;
	//A.set_x(2);
	//A.get_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; //Copy constructor
	D.print();

	Point E;     //Copy assignment
	E = D;
	E.print();

	A.distance(B);

#endif // CONSTRUCTORS_CHECK
	
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A': " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;

	cout << delimiter << endl;
	A = B = C = Point(2, 3); //Point(2, 3) - явно вызываем конструктор
							 // и создаем временный безымянный объект
							 // этот объект и передается как параметр
							 // в первый CopyAssignment
	cout << delimiter << endl;

	A.print();
	B.print();
	C.print();


#endif // ASSIGNMENT_CHECK

#if ARIFMETICAL_OPERATORS_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3;);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();

	Point D = C++;
	C.print();
	D.print();
#endif // ARIFMETICAL_OPERATORS_CHECK
#ifdef COMPARISON_OPERATORS_CHECK

	//cout << (2 == 3) << endl;
	Point A(2, 3);
	Point B(2, 3);
	//cout << (A == B) << endl;
	cout << (Point (7, 8) == Point (7, 8)) << endl;
#endif	//COMPARISON_OPERATORS_CHECK

	/*Point A(2, 3);
	cout << A << endl;*/

}