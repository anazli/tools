#pragma once

template <class T>
class Point3 {
 public:
  Point3(const T &x = T(), const T &y = T(), const T &z = T())
      : m_x(x), m_y(y), m_z(z) {}

 private:
  T m_x, m_y, m_z;
};
