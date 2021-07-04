#include "../include/vec2.h"

#include <cmath>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;

Vec2& Vec2::operator++() {
  *this += 1;  // use of += member operator
  return *this;
}

Vec2& Vec2::operator--() {
  *this -= 1;
  return *this;
}

Vec2 Vec2::operator++(int) {
  Vec2 temp(m_x, m_y);
  ++(*this);  // use of prefix ++ operator
  return temp;
}

Vec2 Vec2::operator--(int) {
  Vec2 temp(m_x, m_y);
  --(*this);
  return temp;
}

Vec2& Vec2::operator+=(const double& num) {
  *this = (*this) + num;  // use of binary + operator
  return *this;
}

Vec2& Vec2::operator+=(const Vec2& v) {
  *this = (*this) + v;
  return *this;
}

Vec2& Vec2::operator-=(const double& num) {
  *this = (*this) - num;
  return *this;
}

Vec2& Vec2::operator-=(const Vec2& v) {
  *this = (*this) - v;
  return *this;
}

Vec2& Vec2::operator*=(const double& num) {
  *this = (*this) * num;
  return *this;
}

Vec2& Vec2::normalize() {
  double norm = this->length();
  *this = (*this) / (norm + 1.E-30);
  return *this;
}

//--------------------------------------------
// Overloaded I/O operators (input, output)
//--------------------------------------------

istream& operator>>(istream& in, Vec2& v) {
  double x, y;
  in >> x >> y;
  v.setXY(x, y);
  return in;
}

ostream& operator<<(ostream& out, const Vec2& v) {
  out << "(" << v.x() << "," << v.y() << ")";
  return out;
}

//--------------------------------------------
// Overloaded operators as normal functions
// Binary operator (+, -, *)
//--------------------------------------------

Vec2 operator+(const Vec2& v1, const Vec2& v2) {
  return Vec2(v1.x() + v2.x(), v1.y() + v2.y());
}

Vec2 operator+(const Vec2& v, const double& num) {
  return Vec2(v.x() + num, v.y() + num);
}

Vec2 operator+(const double& num, const Vec2& v) { return v + num; }

Vec2 operator-(const Vec2& v1, const Vec2& v2) {
  return Vec2(v1.x() - v2.x(), v1.y() - v2.y());
}

Vec2 operator-(const Vec2& v, const double& num) {
  return Vec2(v.x() - num, v.y() - num);
}

Vec2 operator-(const double& num, const Vec2& v) { return v - num; }

Vec2 operator*(const Vec2& v1, const Vec2& v2) {
  return Vec2(v1.x() * v2.x(), v1.y() * v2.y());
}

Vec2 operator*(const Vec2& v, const double& num) {
  return Vec2(v.x() * num, v.y() * num);
}

Vec2 operator*(const double& num, const Vec2& v) { return v * num; }

Vec2 operator/(const Vec2& v1, const Vec2& v2) {
  if (v2.x() == 0. || v2.y() == 0.) throw "Division by zero!";
  return Vec2(v1.x() / v2.x(), v1.y() / v2.y());
}

Vec2 operator/(const Vec2& v, const double& num) {
  double e = 1.E-30;
  return Vec2(v.x() / (num + e), v.y() / (num + e));
}

// Comparison operators

bool operator==(const Vec2& v1, const Vec2& v2) {
  return (v1.x() == v2.x() && v1.y() == v2.y());
}

bool operator!=(const Vec2& v1, const Vec2& v2) { return !(v1 == v2); }

//--------------------------------------------
// General methods (dot product, magnitude)
//--------------------------------------------

double dot(const Vec2& v1, const Vec2& v2) {
  Vec2 v = v1 * v2;
  return v.x() + v.y();
}

double Vec2::length() const { return sqrt(x() * x() + y() * y()); }

Vec2 getUnitVectorOf(const Vec2& v) { return v / (v.length() + 1.E-30); }
