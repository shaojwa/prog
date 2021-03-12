


#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
    Shape() {
        cout << "Shape::Shape()" << endl;
    }
    ~Shape() {
        cout << "Shape::~Shape()" << endl;
    }
    virtual double GetArea() = NULL;
};

class Circle: public Shape
{
public:
    Circle() {
        cout << "Circle::Circle()" << endl;
    };
    Circle(double radius): m_radius(radius) {
        cout << "Circle::Circle(radius)" << endl;
    }
    ~Circle() {
        cout << "Circle::~Circle()" << endl;
    };
    virtual double GetArea() {
        cout << "Circle::GetArea()" << endl;
        return m_radius * m_radius * 3.14 / 2;
    }
    virtual double GetPerimeter()
    {
        double tmp = 2 * 3.14 * m_radius;
        cout << "Square::GetPerimeter() = " << tmp << endl;
        return tmp;
    }
private:
    double m_radius;
};



class Rectangle : public Shape
{
public:
    Rectangle(): m_length(0), m_width(0) {
        cout << "Rectangle::Rectangle()" << endl;
    };
    Rectangle(double length, double width): m_length(length), m_width(width) {
        cout << "Rectangle(length, width)" << endl;
    }

    virtual double GetArea(){
        double tmp = m_length * m_width;
        cout << "Rectangle::GetArea() = " << tmp << endl;
        return tmp;
    }

    double GetPerimeter() {
        double tmp = 2 * (m_length + m_width);
        cout << "Rectangle::GetPerimeter() = " << tmp << endl;
        return tmp;
    }

private:
    double m_length;
    double m_width;

};



class Square: public Rectangle
{
public:
    Square(): m_edge (0) {
        cout << "Square::Square()" << endl;
    };
    Square(double edge): Rectangle(edge, edge), m_edge(edge) {
        cout << "Square::Square(edge)" << endl;
    }
    ~Square() {
        cout << "Square::~Square()" << endl;
    };

    double GetArea() {
        double tmp = m_edge * m_edge;
        cout << "Square::GetArea() = " << tmp << endl;
        return tmp;
    }

    double GetPerimeter() {
        double tmp = 4 * m_edge;
        cout << "Square::GetPerimeter() = " << tmp << endl;
        return tmp;
    }

private:
    double m_edge;
};