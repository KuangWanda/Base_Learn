#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++运算符及其重载
1.运算符可以理解为函数，但不一定具有函数名
2.尽量减少运算符重载的情况，避免引起歧义
3.运算符重载主要目的是简化操作，实现共性的功能
4.常见的运算符重载包括+-*➗ == << 
5.尽量既有运算符的重载，又有相应的函数实现相同的功能
*/

class Vector
{
public:
    int X, Y;

    Vector() {}

    Vector(int x, int y)
        : X(x), Y(y) {}

    Vector Add_Vector(const Vector& v) const
    {
        Vector result;
        result.X = X + v.X;
        result.Y = Y + v.Y;
        return result;
    }

    Vector operator+(const Vector& v) const
    {
        // return Vector(X + v.X, Y + v.Y);
        return Add_Vector(v);  // 既有重载，又有实现相同功能的函数
    }
    
};

std::ostream& operator<<(std::ostream& stream, const Vector& v)  // 重载输出流运算符
{
    stream << "X = " << v.X << ", Y = " << v.Y;
    return stream;
}

int main()
{
    Vector v1(1, 2);
    Vector v2(3, 4);

    v1.Add_Vector(v2);
    Vector add = v1 + v2;  // 在“+”没有重载的情况下，直接相加是不允许的

    LOG(add.Y);
    std::cout<< v1 << std::endl;
}