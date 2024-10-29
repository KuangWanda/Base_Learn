#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++this关键字
1.通过this关键字，可以访问成员函数，其本质是一个指向当前对象实例的指针
2.this关键字只能在类的成员函数内使用
*/

void PrintEntity(const Entity &e);

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        // Entity* const e = this;
        this->x = x;
        this->y = y;

        PrintEntity(*this);
    };
};

void PrintEntity(const Entity &e)
{
    std::cout << e.x << std::endl;
}

int main()
{
}