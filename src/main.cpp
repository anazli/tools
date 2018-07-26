#include<iostream>
#include "../include/vec3.h"

using namespace std;

int main()
{
	Vec3 x_unit(1.,0.,0.);
	Vec3 y_unit(0.,1.,0.);
	Vec3 z_unit = cross(x_unit, y_unit);
	cout << z_unit << endl;	
	return 0;
}
