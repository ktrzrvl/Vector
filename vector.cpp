#include <cmath>
#include <iostream>
using namespace std;

class Vector {
	double x, y, z;

public:
	Vector(double x1 = 0, double y1 = 0, double z1 = 0);

	void Print() const;
	void Read();
	
	Vector operator+(Vector v) const; // сложение векоров
	Vector operator-(Vector v) const; // вычитание векторов
	Vector operator^(Vector vec) const;
	bool operator==(Vector vec) const;
	
	double operator*(Vector v) const;
	double Length() const;
	
	void Normalization();

	friend ostream& operator<<(ostream& os, const Vector& vector);
	friend istream& operator>>(istream& is, Vector& vector);
};

Vector::Vector(double x1, double y1, double z1) {
	x = x1;
	y = y1;
	z = z1;
}

double Vector::Length() const {
	return sqrt(x * x + y * y + z * z);
}

void Vector::Print() const {
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

Vector Vector::operator+(Vector v) const {
	double x1 = x + v.x;
	double y1 = y + v.y;
	double z1 = z + v.z;
	return Vector(x1, y1, z1);
}

Vector Vector::operator-(Vector v) const {
	double x1 = x - v.x;
	double y1 = y - v.y;
	double z1 = z - v.z;
	return Vector(x1, y1, z1);
}

double Vector::operator*(Vector v) const {
	return x*v.x + y*v.y + z*v.z; 
}

void Vector::Normalization(){
	double len = Length();
	if (len == 0) {
		return;
	}
	x /= len;
	y /= len;
	z /= len;
}

void Vector::Read(){
	cout << "enter x, y, z" << endl;
	cin >> x >> y >> z;
}

ostream& operator<<(ostream& os, const Vector& vector) {
	os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")" << endl;
	return os;
}

istream& operator>>(istream &is, Vector& vector) {
	cout << "enter x, y, z" << endl;
	is >> vector.x >> vector.y >> vector.z;
	return is;
}

void swap(int &a, int b) {
	int tmp = a;
	a = b;
	b = tmp;

	cout << "a: " << a << ", b: " << b << endl;
}

Vector Vector::operator^(Vector vec) const {
	double x0 = y * vec.z - vec.y * z;
	double y0 = z * vec.x - vec.z * x;
	double z0 = x * vec.y - vec.x * y;
	return Vector(x0, y0, z0);
}

bool Vector::operator==(Vector vec) const {
	return x == vec.x && y == vec.y && z == vec.z;
}


int main()
{
	Vector a;
	Vector b;
	Vector c;

	cout << "enter a: ";
	cin >> a;
	cout << "enter b: ";
	cin >> b;
	cout << "enter c: ";
	cin >> c;

	Vector res = (b - a)^(c - a);
	cout << "(b - a)^(c - a) = " << res;
	// cin >> a >> b;
	
	// cout << "a: " << a << "b: " << b;
	// cout << "Length a: " << a.Length() << endl;
	// cout << "Length b: " << b.Length() << endl;

	// Vector c = a - b;
	// c.Print();

	// Vector d = a + b;
	// d.Print();

	// cout << "a*b: " << a.Scalar(b) << endl;
	
	// a.Normalization();
	// b.Normalization();

	// a.Print();
	// b.Print();
	
	// cout << "Length a: " << a.Length() << endl;
	// cout << "Length b: " << b.Length() << endl;
}