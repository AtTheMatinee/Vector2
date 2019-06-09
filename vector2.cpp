//vector2.cpp

#include "vector2.h"

Vector2::Vector2() = default;
Vector2::Vector2(double x, double y) : X(x), Y(y) {}
Vector2::Vector2(const Vector2& otherVec) : X(otherVec.X), Y(otherVec.Y) {}

Vector2::~Vector2() = default;

//Vector addition
Vector2 Vector2::operator+(const Vector2& otherVec) {
	Vector2 temp;
	temp.X = X + otherVec.X;
	temp.Y = Y + otherVec.Y;
	return temp;
}

Vector2& Vector2::operator+=(const Vector2& otherVec) {
	X += otherVec.X;
	Y += otherVec.Y;
	return *this;
}

Vector2 Vector2::operator+(double s) {
	Vector2 temp;
	temp.X = X + s;
	temp.Y = Y + s;
	return temp;
}

Vector2& Vector2::operator+=(double s) {
	X += s;
	Y += s;
	return *this;
}


//Vector subtraction
Vector2 Vector2::operator-(const Vector2& otherVec) {
	Vector2 temp;
	temp.X = X - otherVec.X;
	temp.Y = Y - otherVec.Y;
	return temp;
}

Vector2& Vector2::operator-=(const Vector2& otherVec) {
	X -= otherVec.X;
	Y -= otherVec.Y;
	return *this;
}

Vector2 Vector2::operator-(double s) {
	Vector2 temp;
	temp.X = X - s;
	temp.Y = Y - s;
	return temp;
}

Vector2& Vector2::operator-=(double s) {
	X -= s;
	Y -= s;
	return *this;
}


//Vector multiplication
Vector2 Vector2::operator*(double s) {
	Vector2 temp;
	temp.X = X*s;
	temp.Y = Y*s;
	return temp;
}

Vector2& Vector2::operator*=(double s) {
	X *= s;
	Y *= s;
	return *this;
}


//Vector division
Vector2 Vector2::operator/(double s) {
	Vector2 temp;
	temp.X = X/s;
	temp.Y = Y/s;
	return temp;
}

Vector2& Vector2::operator/=(double s) {
	X /= s;
	Y /= s;
	return *this;
}

//Useful Vector Operations
double Vector2::Length() const {
	return std::sqrt(X*X + Y*Y);
}

Vector2& Vector2::Normalize() {
	double magnitude = Length();
	if (magnitude == 0) return *this;
	return (*this)/=magnitude;
}

double Vector2::Distance(Vector2 otherVec) const {
	Vector2 d(otherVec.X-X, otherVec.Y-Y);
	return d.Length();
}

double Vector2::Dot(Vector2 v1, Vector2 v2) {
	return (v1.X * v2.X )+ (v1.Y * v2.Y);
}

double Vector2::Cross(Vector2 v1, Vector2 v2) {
	return (v1.X * v2.Y) - (v1.Y * v2.X);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	os << "(" << v.X << ", " << v.Y << ")";
}

bool operator<(const Vector2& lhs, const Vector2& rhs) {
	return ((lhs.X < rhs.X) || (lhs.X == rhs.X && lhs.Y < rhs.Y));
}

bool operator>(const Vector2& lhs, const Vector2& rhs) {
	return operator<(rhs, lhs);
}

bool operator==(const Vector2& lhs, const Vector2& rhs) {
	return (lhs.X == rhs.X && lhs.Y == rhs.Y);
}

bool operator!=(const Vector2& lhs, const Vector2& rhs) {
	return !operator==(lhs,rhs);
}

bool operator<=(const Vector2& lhs, const Vector2& rhs) {
	return !operator>(lhs, rhs);
}

bool operator>=(const Vector2& lhs, const Vector2& rhs) {
	return !operator<(lhs,rhs);
}