#include "../include/vec4.h"

#include <cmath>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;

Vec4& Vec4::operator++() {
  *this += 1;  // use of += member operator
  return *this;
}

Vec4& Vec4::operator--() {
  *this -= 1;
  return *this;
}

Vec4 Vec4::operator++(int) {
  Vec4 temp(m_x, m_y, m_z, m_w);
  ++(*this);  // use of prefix ++ operator
  return temp;
}

Vec4 Vec4::operator--(int) {
  Vec4 temp(m_x, m_y, m_z, m_w);
  --(*this);
  return temp;
}

Vec4& Vec4::operator+=(const double& num) {
  *this = (*this) + num;  // use of binary + operator
  return *this;
}

Vec4& Vec4::operator+=(const Vec4& v) {
  *this = (*this) + v;
  return *this;
}

Vec4& Vec4::operator-=(const double& num) {
  *this = (*this) - num;
  return *this;
}

Vec4& Vec4::operator-=(const Vec4& v) {
  *this = (*this) - v;
  return *this;
}

Vec4& Vec4::operator*=(const double& num) {
  *this = (*this) * num;
  return *this;
}

Vec4& Vec4::normalize() {
  double norm = this->length();
  *this = (*this) / (norm + 1.E-30);
  return *this;
}

//--------------------------------------------
// Overloaded I/O operators (input, output)
//--------------------------------------------

istream& operator>>(istream& in, Vec4& v) {
  double x, y, z, w;
  in >> x >> y >> z >> w;
  v.setXYZW(x, y, z, w);
  return in;
}

ostream& operator<<(ostream& out, const Vec4& v) {
  out << "(" << v.x() << "," << v.y() << "," << v.z() << "," << v.w() << ")";
  return out;
}

//--------------------------------------------
// Overloaded operators as normal functions
// Binary operator (+, -, *)
//--------------------------------------------

Vec4 operator+(const Vec4& v1, const Vec4& v2) {
  return Vec4(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z(),
              v1.w() + v2.w());
}

Vec4 operator+(const Vec4& v, const double& num) {
  return Vec4(v.x() + num, v.y() + num, v.z() + num, v.w() + num);
}

Vec4 operator+(const double& num, const Vec4& v) { return v + num; }

Vec4 operator-(const Vec4& v1, const Vec4& v2) {
  return Vec4(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z(),
              v1.w() - v2.w());
}

Vec4 operator-(const Vec4& v, const double& num) {
  return Vec4(v.x() - num, v.y() - num, v.z() - num, v.w() - num);
}

Vec4 operator-(const double& num, const Vec4& v) { return v - num; }

Vec4 operator*(const Vec4& v1, const Vec4& v2) {
  return Vec4(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z(),
              v1.w() * v2.w());
}

Vec4 operator*(const Vec4& v, const double& num) {
  return Vec4(v.x() * num, v.y() * num, v.z() * num, v.w() * num);
}

Vec4 operator*(const double& num, const Vec4& v) { return v * num; }

Vec4 operator/(const Vec4& v1, const Vec4& v2) {
  if (v2.x() == 0. || v2.y() == 0. || v2.z() == 0. || v2.w() == 0.)
    throw "Division by zero!";
  return Vec4(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z(),
              v1.w() / v2.w());
}

Vec4 operator/(const Vec4& v, const double& num) {
  double e = 1.E-30;
  return Vec4(v.x() / (num + e), v.y() / (num + e), v.z() / (num + e),
              v.w() / (num + e));
}

// Comparison operators

bool operator==(const Vec4& v1, const Vec4& v2) {
  return (v1.x() == v2.x() && v1.y() == v2.y() && v1.z() == v2.z(),
          v1.w() == v2.w());
}

bool operator!=(const Vec4& v1, const Vec4& v2) { return !(v1 == v2); }

//--------------------------------------------
// General methods (dot product, magnitude)
//--------------------------------------------

double dot(const Vec4& v1, const Vec4& v2) {
  Vec4 v = v1 * v2;
  return v.x() + v.y() + v.z() + v.w();
}

double Vec4::length() const {
  return sqrt(x() * x() + y() * y() + z() * z() + w() * w());
}

Vec4 getUnitVectorOf(const Vec4& v) { return v / (v.length() + 1.E-30); }
