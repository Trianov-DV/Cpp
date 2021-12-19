#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

void Point3D::moveVector(const Vector3D& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}

void Point3D::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}