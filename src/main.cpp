#include <iostream>

#include "../include/tools.h"

using namespace std;

int main() {
  Vec2d v(1.5, 2.5);
  cout << v << endl;
  cout << v.normalize() << endl;

  Vec3d x_unit(1.5, 0., 0.);
  Vec3d y_unit(0., 1.5, 0.);
  Vec3d z_unit = cross(x_unit, y_unit);
  cout << z_unit << endl;

  Vec4d v4(1.4, 5.3, 56., 0.);
  cout << v4 << endl;

  Vec2d v2[2];
  v2[0].setXY(2.);
  v2[1].setXY(3.);
  cout << v2[0][0] << endl;
  cout << v2[1][1] << endl;

  Mat2<double> m(v2[0], v2[1]);
  cout << m[0][0] << endl;


  return 0;
}
