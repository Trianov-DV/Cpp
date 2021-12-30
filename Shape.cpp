#include <iostream>
#include <algorithm>
#include <vector>
#include <initializer_list>

class Shape
{
public:

    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<< (std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() {}

};

class Point
{
private:
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;

public:
    Point(int x, int y, int z)
        : m_x(x), m_y(y), m_z(z)
    {

    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
};

class Triangle : public Shape
{
protected:

    Point m_p1;
    Point m_p2;
    Point m_p3;

public:

    Triangle(const Point& point1, const Point& point2, const Point& point3)
        : m_p1(point1), m_p2(point2), m_p3(point3)
    {
    }
    
    virtual ~Triangle() {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle: (" << m_p1 << "; " << m_p2 << "; " << m_p3 << ")\n";
        return out;
    }

};

class Circle : public Shape
{
protected:

    Point m_point;
    int m_radius;

public:

    Circle(const Point& point, int radius)
        : m_point(point), m_radius(radius)
    {
    }
    
    virtual ~Circle() {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Circle: (" << m_point << " radius " << m_radius << "))\n";
        return out;
    }

    int& getRadius() { return m_radius; }
};


int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{ 0 };

    for (auto const& element : v)
    {
        if (Circle* c = dynamic_cast<Circle*>(element))
        {
            if (c->getRadius() > largestRadius)
            {
                largestRadius = c->getRadius();
            }
        }
    }

    return largestRadius;
}

int main()
{
    std::vector<Shape*> v;

    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 3));

    for (auto const& element : v)
    {
        std::cout << *element << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    for (auto const& element : v)
    {
        delete element;
    }
        
    return 0;
}
