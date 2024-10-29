#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：类的继承
1.继承的存在允许使得程序有一个相互关联的类的层次结构，即存在一个包含公共功能的基类，避免代码重复
2.在子类中可以访问父类中全部的不是私有的内容
*/

class Parent // 父类
{
public:
    float X, Y;

    Parent()
    {

    }

    Parent(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

    void Print()
    {
        std::cout << "X = " << X << ", Y = " << Y << std::endl;
    }
};

class Child : public Parent // 子类，拥有父类拥有的所有东西
{
public:
    const char *Name;

    Child(const char* m)
    {
        Name = m;
    }

    Child(float x, float y, const char* m)
    {
        X = x;
        Y = y;
        Name = m;
    }

    void Print_Name()
    {
        LOG(Name);
    }
};

int main()
{
    Child c("kwd");
    c.Print_Name();
    c.Print();
}