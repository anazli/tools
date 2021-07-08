#ifndef MAT3_H
#define MAT3_H

#include "vec3.h"

template <class T>
class Mat3 {
 public:
  Mat3<T>() {}
  Mat3<T>(const T& num) {
    m_vec[0].setXY(num);
    m_vec[1].setXY(num);
    m_vec[2].setXY(num);
  }
  Mat3<T>(const Vec3<T>& row1, const Vec3<T>& row2, const Vec3<T>& row3) {
    m_vec[0] = row1;
    m_vec[1] = row2;
    m_vec[2] = row3;
  }

  Mat3<T>& operator=(const Mat3<T>& c) {
    m_vec[0] = c[0];
    m_vec[1] = c[1];
    m_vec[2] = c[2];
    return *this;
  }

  Mat3<T>& operator+=(const Mat3<T>& c) {
    m_vec[0] += c[0];
    m_vec[1] += c[1];
    m_vec[2] += c[2];
    return *this;
  }

  Mat3<T>& operator+=(const T& num) {
    m_vec[0] += num;
    m_vec[1] += num;
    m_vec[2] += num;
    return *this;
  }

  Mat3<T>& operator-=(const Mat3<T>& c) {
    m_vec[0] -= c[0];
    m_vec[1] -= c[1];
    m_vec[2] -= c[2];
    return *this;
  }

  Mat3<T>& operator-=(const T& num) {
    m_vec[0] -= num;
    m_vec[1] -= num;
    m_vec[2] -= num;
    return *this;
  }

  Mat3<T>& operator*=(const T& num) {
    m_vec[0] *= num;
    m_vec[1] *= num;
    m_vec[2] *= num;
    return *this;
  }

  Vec3<T> operator[](int i) const {
    assert(i >= 0 && i <= 1);
    if (i == 0) return m_vec[0];
    if (i == 1) return m_vec[1];
    return m_vec[2];
  }

  Vec3<T>& operator[](int i) {
    assert(i >= 0 && i <= 1);
    if (i == 0) return m_vec[0];
    if (i == 1) return m_vec[1];
    return m_vec[2];
  }

  double Determinant();
  const

      private : Vec3<T>
                    m_vec[3];
};

template <typename T>
double Mat3<T>::Determinant() {
  double r1 =
      m_vec[0][0] * (m_vec[1][1] * m_vec[2][2] - m_vec[1][2] * m_vec[2][1]);
  double r2 =
      m_vec[0][1] * (m_vec[1][0] * m_vec[2][2] - m_vec[1][2] * m_vec[2][0]);
  double r3 =
      m_vec[0][2] * (m_vec[1][0] * m_vec[2][1] - m_vec[1][1] * m_vec[2][0]);

  return r1 - r2 + r3;
}

template <typename T>
Mat3<T> operator+(const Mat3<T>& m1, const Mat3<T>& m2) {
  return Mat3<T>(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2]);
}

template <typename T>
Mat3<T> operator-(const Mat3<T>& m1, const Mat3<T>& m2) {
  return Mat3<T>(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2]);
}

template <typename T>
Mat3<T> operator*(const Mat3<T>& m1, const Mat3<T>& m2) {
  Mat3<T> ret;
  ret[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0];
  ret[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1];
  ret[0][2] = m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2];

  ret[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0];
  ret[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1];
  ret[1][2] = m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2];

  ret[2][0] = m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0];
  ret[2][1] = m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1];
  ret[2][2] = m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2];

  /* OR
  Vec3<T> row1 = m1[0];
  Vec3<T> row2 = m1[1];
  Vec3<T> row3 = m1[2];

  Vec3<T> col1 = Vec3<T>(m2[0][0], m2[0][1], m2[0][2];
  Vec3<T> col2 = Vec3<T>(m2[0][1], m2[1][1], m2[2][1];
  Vec3<T> col3 = Vec3<T>(m2[0][2], m2[1][2], m2[2][2];

  Vec3<T> retRow1 = Vec3<T>(dot(row1, col1), dot(row1, col2), dot(row1, col3));
  Vec3<T> retRow2 = Vec3<T>(dot(row2, col1), dot(row2, col2), dot(row2, col3));
  Vec3<T> retRow3 = Vec3<T>(dot(row3, col1), dot(row3, col2), dot(row3, col3));
  */

  /* 00 01 02
   * 10 11 12
   * 20 21 22*/

  return ret;
}

#endif  // MAT3