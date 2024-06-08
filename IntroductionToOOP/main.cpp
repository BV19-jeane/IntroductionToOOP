#include<iostream>
using namespace std;

//ќбъ€вл€€ структуру или класс мы создаем новый тип данных (пользовательский тип данных)
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
	~Point()
	{
		cout << "Destructor: \t \t" << this << endl;
	}

	// Methods:
	double distance(Point other)
	{
		double x_distence = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distence * x_distence + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\ty = " << y << endl;
	}
};
//#define STRUCT_POINT
//#defined CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef   STRUCT_POINT
	//cout << "Hello OOP" << endl;
	int a;
	Point A;
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

	A.distance(B);

#endif // CONSTRUCTORS_CHECK

	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << endl;
	cout << "–ассто€ние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	
}