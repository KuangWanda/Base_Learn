#include <iostream>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：
1.构造函数是一种特殊类型的方法，每次构造类的对象时都会调用
2.构造函数没有返回类型，并且名称必须与类的名称相同
3.如果不创建构造函数，那么类原本有一个缺省的构造函数，但是完全为空
4.构造函数可以有多个，但是它们的参数不能相同
5.构造函数可以是私有方法，此时类不允许实例化对象
6.如果只有新设计的构造函数，没有默认的构造函数，即没有零参的构造函数，实例化对象就会失败
*/

class Entity
{
public:
    float X, Y;

    void Init() // 手动初始化
    {
        X = 0.f;
        Y = 0.f;
    }

    Entity() // 构造函数，如果只有下面这个构造函数而没有这个构造函数，Entity e; 这个声明操作非法
    {
        X = 1.5f;
        Y = 2.7f;
    }

    Entity(float x, float y) // 不同参数的构造函数
    {
        X = x;
        Y = y;
    }

    void Print()
    {
        std::cout << "X = " << X << ", Y = " << Y << std::endl;
    }
};

class Test
{
private:
    // Test() {}  // 如果私有的构造函数存在，则不允许实例化对象

public:
    Test() = delete;  // 可以删除构造函数，但是不影响重载的其他构造函数
    int X;
    Test(int x)
    {
        X = x;
    }
};

int main()
{
    Entity e(1.7, 3.2);
    // e.Init();
    e.Print();

    // Test t(4);  // 实例化失败

    Entity e1;
    e1.Print();
}