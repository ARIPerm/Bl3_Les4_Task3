#include <iostream>
#include <Windows.h>
#include <vector>
#include <initializer_list>

void isRight(bool isBool);
void printAngle(std::initializer_list<int> value);
void printSides(std::initializer_list<int> value);

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
    virtual void getAngle() {};

    bool checkRight() 
    {
        if (_countSides == 0)
            return true;
        else
            return false;
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

    int getSides(int index) const
    {
        switch (index)
        {
        case 1:
            return a;
            break;
        case 2:
            return b;
            break;
        case 3:
            return c;
            break;
        default:
            return -1;
            break;
        }
    };

    int getAngle(int index) const
    {
        switch (index)
        {
        case 1:
            return A;
            break;
        case 2:
            return B;
            break;
        case 3:
            return C;
            break;
        default:
            return -1;
            break;
        }
    };

    bool checkRight() 
    {
        int result = A + B + C;
        if (result == 180)
            return true;
        else
            return false;
    }

protected:
    int a, b, c, A, B, C;

};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Прямоугольный треугольник") { }

    bool checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if (C == 90)
                return true;
            else
                return false;
        }            
        else
            return false;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Равнобедренный треугольник") {}

    bool checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if (A == C && a == c)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

class EqualateralTriangle : public Triangle
{
public:
    EqualateralTriangle(int ta, int tb, int tc, int tA, int tB, int tC) : Triangle(ta, tb, tc, tA, tB, tC, "Равносторонний треугольник") {}

    bool checkRight()
    {
        int result = A + B + C;
        if (result == 180)
        {
            if (A == 60 && B == 60 && C == 60 && a == c && a == b)
                return true;
            else
                return false;
        }
        else
            return false;
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

    int getSides(int index) const
    {
        switch (index)
        {
        case 1:
            return a;
            break;
        case 2:
            return b;
            break;
        case 3:
            return c;
            break;
        case 4:
            return d;
            break;
        default:
            return -1;
            break;
        }
    };

    int getAngle(int index) const
    {
        switch (index)
        {
        case 1:
            return A;
            break;
        case 2:
            return B;
            break;
        case 3:
            return C;
            break;
        case 4:
            return D;
            break;
        default:
            return -1;
            break;
        }
    };

    bool checkRight() 
    {
        int result = A + B + C + D;
        if (result == 360)
            return true;
        else
            return false;
    }

protected:
    int a, b, c, d, A, B, C, D;
};

class Rectangles : public Quadrangle
{
public:
    Rectangles(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Прямоугольник") {}

    bool checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if(A ==90 && B == 90 && C == 90 && D == 90 && a == c && b ==d)
                return true;
            else
                return false;
        else
            return false;
    }
};

class Square : public Quadrangle
{
public:
    Square(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Квадрат") {}

    bool checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == 90 && B == 90 && C == 90 && D == 90 && a == c && b == d && a == b)
                return true;
            else
                return false;
        else
            return false;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Параллелограм") {}

    bool checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == C && B == D && a == c && b == d)
                return true;
            else
                return false;
        else
            return false;
    }
};

class Rhomb : public Quadrangle
{
public:
    Rhomb(int ta, int tb, int tc, int td, int tA, int tB, int tC, int tD) : Quadrangle(ta, tb, tc, td, tA, tB, tC, tD, "Ромб") {}

    bool checkRight()
    {
        int result = A + B + C + D;
        if (result == 360)
            if (A == C && B == D && a == c && b == d && a == b)
                return true;
            else
                return false;
        else
            return false;
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
    isRight(fig0.checkRight());
    fig0.getCountSides();
    std::cout << std::endl;

    for (auto element : triangle)
    {
        element.getType();
        isRight(element.checkRight());
        element.getCountSides();
        printSides({ element.getSides(1), element.getSides(2), element.getSides(3) });
        printAngle({ element.getAngle(1),element.getAngle(2),element.getAngle(3) });
        std::cout << std::endl;
    }

    for (auto element : quadrangle)
    {
        element.getType();
        isRight(element.checkRight());
        element.getCountSides();
        printSides({ element.getSides(1), element.getSides(2), element.getSides(3), element.getSides(4) });
        printAngle({ element.getAngle(1),element.getAngle(2),element.getAngle(3),element.getAngle(4) });
        std::cout << std::endl;
    }    
}

void isRight(bool isBool)
{
    if (isBool)
        std::cout << "Правильная" << std::endl;
    else
        std::cout << "Неправильная" << std::endl;
}

void printSides(std::initializer_list<int> value)
{
    std::cout << "Стороны:";
    if (value.size() == 3)
    {
        std::string string[3] = { " a=", " b=", " c=" };
        int index = 0;
        for (auto val : value)
        {
            std::cout << string[index] << val;
            index++;
        }
        std::cout << std::endl;
    }
    else if (value.size() == 4)
    {
        std::string string[4] = { " a=", " b=", " c=", " d=" };
        int index = 0;
        for (auto val : value)
        {
            std::cout << string[index] << val;
            index++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Ошибочное количество сторон!";
};

void printAngle(std::initializer_list<int> value)
{
    std::cout << "Углы:";
    if (value.size() == 3)
    {
        std::string string[3] = { " A=", " B=", " C=" };
        int index = 0;
        for (auto val : value)
        {
            std::cout << string[index] << val;
            index++;
        }
        std::cout << std::endl;
    }
    else if (value.size() == 4)
    {
        std::string string[4] = { " A=", " B=", " C=" , " D=" };
        int index = 0;
        for (auto val : value)
        {
            std::cout << string[index] << val;
            index++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Ошибочное количество углов!";
};