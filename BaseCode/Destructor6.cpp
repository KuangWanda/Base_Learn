#include <iostream>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：析构函数
1.析构函数需要在函数名前添加一个~
2.一个对象将要被销毁时，析构函数就会运行
3.析构函数可以避免不必要的内存泄漏
4.析构函数也有缺省版本，但是针对特定化的资源，需要手动设计析构函数
*/

class Entity
{
public:
    int X;

    Entity()
    {
        LOG("执行构造函数！");
    }

    Entity(int x)  // 构造函数
    {
        X = x;
    }

    void Print()
    {
        LOG(X);
    }

    ~Entity()
    {
        LOG("执行析构函数！");
    }
};

int main()
{
    Entity e;
    e.Print();
}