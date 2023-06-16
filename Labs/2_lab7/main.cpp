///Лабораторная работа №7
//«Геометрические фигуры»
//Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами:
//Треугольник,Прямоугольник, Круг
//Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.
//Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур.
#include <iostream>
#include <vector>
#include <math.h>

class Shape
{
protected:
    std::string m_color;
    double m_square;
    std::vector <int> m_size; //Размеры фигуры
    int X, Y;                 //Координаты центра фигуры
public:
    Shape (const std::string& color, std::vector<int>* size, int x, int y) : m_color(color), m_size(*size), X(x), Y(y)
    {
        std::cout << "Shape constructor" << std::endl;
    }
    void Area()
    {
        std::cout << "The square of figure is " << m_square << std::endl;
    }
    virtual ~Shape()
    {
        std::cout << "Shape destructor" << std::endl;
    }
};
class Circle : public Shape
{
public:
    Circle(const std::string& color, std::vector<int>* size, int x, int y) : Shape(color, size, x, y)
    {
        std::cout << "Circle constructor" << std::endl;
    }
    virtual ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    }
    // пи * радиус в квадрате
    double getArea()
    {
        m_square = acos(-1)*pow(m_size[0],2);
        //std::cout << "The square of circle is " << m_square << std::endl;;
    }
};
class Triangle : public Shape
{
public:
    Triangle(const std::string& color, std::vector<int>* size, int x, int y) : Shape(color, size, x, y)
    {
        std::cout << "Triangle constructor" << std::endl;
    }
    virtual ~Triangle()
    {
        std::cout << "Triangle destructor" << std::endl;
    }
    //Площадь по формуле Герона
    double getArea()
    {
        double pp = (m_size[0] + m_size[1] + m_size[2]) / 2; //Полупериметр
        m_square = sqrt(pp*(pp - m_size[0])*(pp - m_size[1])*(pp - m_size[2]));
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(const std::string& color, std::vector<int>* size, int x, int y) : Shape(color, size, x, y)
    {
        std::cout << "Rectangle constructor" << std::endl;
    }
    virtual ~Rectangle()
    {
        std::cout << "Rectangle destructor" << std::endl;
    }
    double getArea()
    {
        m_square = m_size[0] * m_size[1];
    }
};
int main()
{
    std::vector<int> tr = {4,3,5};//стороны треугольника
    Triangle triangle("Blue", &tr, 12, 13);
    triangle.getArea();
    triangle.Area();
    /*std::vector<int> rec = {2,8};//стороны прямоугольника
    Rectangle rectangle("Red", &rec, - 1, 8);
    rectangle.getArea();
    rectangle.Area();
    std::vector<int> cir = {6};//радиус
    Circle circle("Green", &cir, 9, 0);
    circle.getArea();
    circle.Area();*/
}