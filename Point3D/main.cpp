#include <iostream>
#include <vector>

#include "Vector3D.h"
#include "Point3D.h"

int main()
{
	Point3D point(3.0, 4.0, 5.0);
	Vector3D vector(3.0, 3.0, -2.0);

	point.print();
	point.moveVector(vector);
	point.print();

	return 0;
}