#include <iostream>
#include <Windows.h>
#include <vector>

class Figure
{
public:
    Figure()
    {
        _type = "Фигура";
        _countSides = 0;
    }

    Figure(std::string type, int countSides)
    {
        _type = type;
        _countSides = countSides;
    }

    void getType()
    {
        std::cout << _type << ":" << std::endl;
    };

    void getCountSides()
    {
        std::cout << "Количество сторон: " << _countSides << std::endl;
    }

    virtual void getSides() {};
    virtual void getUncle() {};

    void checkRight() 
    {
        if (_countSides == 0)
            std::cout << "Правильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    };

private:
    std::string _type;
    int _countSides;
};

class Triangle : public Figure
{
public:
    Triangle(int ta, int tb, int tc, int tA, int tB, int tC, std::string type = "Треугольник") : Figure(type, 3)
    {
        a = ta;
        b = tb;
        c = tc;
        A = tA;
        B = tB;
        C = tC;
    }

    void getSides() override
    {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    };

    void getUncle() override
    {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    };

    void checkRight() 
    {
        int result = A + B + C;
        if (result == 180)
            std::cout << "Правильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }

protected:
    int a, b, c, A, B, C;

};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Прямоугольный треугольник") { }

    void checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if(C == 90)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        }            
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Равнобедренный треугольник") {}

    void checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if (A == C && a == c)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        }
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class EqualateralTriangle : public Triangle
{
public:
    EqualateralTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Равносторонний треугольник") {}

    void checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if (A == 60 && B == 60 && C == 60 && a == c && a == b)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        }
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD, std::string type = "Четырехугольник") : Figure(type, 4)
    {
        a = ta;
        b = tb;
        c = tc;
        d = td;
        A = tA;
        B = tB;
        C = tC;
        D = tD;
    }

    void getSides() override
    {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    };

    void getUncle() override
    {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    };

    void checkRight() 
    {
        int result = A + B + C + D;
        if (result == 360)
            std::cout << "Правильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }

protected:
    int a, b, c, d, A, B, C, D;
};

class Rectangles : public Quadrangle
{
public:
    Rectangles(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Прямоугольник") {}

    void checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if(A ==90 && B == 90 && C == 90 && D == 90 && a == c && b ==d)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class Square : public Quadrangle
{
public:
    Square(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Квадрат") {}

    void checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == 90 && B == 90 && C == 90 && D == 90 && a == c && b == d && a == b)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Параллелограм") {}

    void checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == C && B == D && a == c && b == d)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }
};

class Rhomb : public Quadrangle
{
public:
    Rhomb(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Ромб") {}

    void checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == C && B == D && a == c && b == d && a == b)
                std::cout << "Правильная" << std::endl;
            else
                std::cout << "Неправильная" << std::endl;
        else
            std::cout << "Неправильная" << std::endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure fig0;

    Triangle fig1(10, 20, 30, 50, 60, 70);
    RightTriangle fig2(10, 20, 30, 50, 60, 90);
    RightTriangle fig(10, 20, 30, 50, 40, 90);
    IsoscelesTriangle fig3(10, 20, 30, 50, 60, 50);
    EqualateralTriangle fig4(30, 30, 30, 60, 60, 60);

    std::vector<Triangle> triangle;
    triangle.push_back(fig1);
    triangle.push_back(fig2);
    triangle.push_back(fig);
    triangle.push_back(fig3);
    triangle.push_back(fig4);

    Quadrangle fig5(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangles fig6(10, 20, 10, 20, 90, 90, 90, 90);
    Square fig7(20, 20, 20, 20, 90, 90, 90, 90);
    Parallelogram fig8(20, 30, 20, 30, 30, 40, 30, 40);
    Rhomb fig9(30, 30, 30, 30, 30, 40, 30, 40);

    std::vector<Quadrangle> quadrangle;
    quadrangle.push_back(fig5);
    quadrangle.push_back(fig6);
    quadrangle.push_back(fig7);
    quadrangle.push_back(fig8);
    quadrangle.push_back(fig9);

    fig0.getType();
    fig0.checkRight();
    fig0.getCountSides();
    std::cout << std::endl;

    for (auto element : triangle)
    {
        element.getType();
        element.checkRight();
        element.getCountSides();
        element.getSides();
        element.getUncle();
        std::cout << std::endl;
    }

    for (auto element : quadrangle)
    {
        element.getType();
        element.checkRight();
        element.getCountSides();
        element.getSides();
        element.getUncle();
        std::cout << std::endl;
    }    
}