//vector2.h
#ifndef _VECTOR_2
#define _VECTOR_2

#include <iostream>
#include <cmath>

class Vector2 {
public:
	double X;
	double Y;
	
	Vector2();
	Vector2(double x, double y);
	Vector2(const Vector2& otherVec);

	~Vector2();

	//Vector addition
	Vector2 operator+(const Vector2& otherVec);

	Vector2& operator+=(const Vector2& otherVec);

	Vector2 operator+(double s);

	Vector2& operator+=(double s);


	//Vector subtraction
	Vector2 operator-(const Vector2& otherVec);

	Vector2& operator-=(const Vector2& otherVec);

	Vector2 operator-(double s);

	Vector2& operator-=(double s);


	//Vector multiplication
	Vector2 operator*(double s);

	Vector2& operator*=(double s);


	//Vector division
	Vector2 operator/(double s);

	Vector2& operator/=(double s);

	//Useful Vector Operations
	double Length() const;

	Vector2& Normalize();

	double Distance(Vector2 otherVec) const;

	static double Dot(Vector2 v1, Vector2 v2);

	static double Cross(Vector2 v1, Vector2 v2);

private:
	
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

std::ostream& operator<<(std::ostream& os, const Vector2& v);

//Vector comperison operators
bool operator<(const Vector2& lhs, const Vector2& rhs);

bool operator==(const Vector2& lhs, const Vector2& rhs);

bool operator<=(const Vector2& lhs, const Vector2& rhs);

bool operator>(const Vector2& lhs, const Vector2& rhs);

bool operator>=(const Vector2& lhs, const Vector2& rhs);

#endif