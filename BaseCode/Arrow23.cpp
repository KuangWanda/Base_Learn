#include <iostream>
#include <string>
#include <memory>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：箭头操作符
1.除了获得类内信息，->还可以获得类内变量的偏移值
*/

class Entity
{
public:
    void Print() const
    {
        std::cout << "hello" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity *m_Obj;

public:
    ScopedPtr(Entity *entity)
        : m_Obj(entity) {}

    void Print()
    {
        std::cout << "ScopedPtr Hello" << std::endl;
    }

    const Entity *GetObj() const { return m_Obj; }

    ~ScopedPtr()
    {
        delete m_Obj;
    }
};

struct Vector
{
    float x, y, z;
};


int main()
{
    Entity e1;
    e1.Print();

    Entity *e2 = new Entity();
    e2->Print();

    ScopedPtr s1 = new Entity(); // 可以这样理解new Entity()返回了一个Entity类型的指针，然后将这个指针作为ScopedPtr构造函数的参数传入
    ScopedPtr s2(new Entity());  // 更推荐这种写法

    s1.GetObj()->Print();

    // long offset = (long)&((Vector*)nullptr)->x;  // 使用long避免精度丢失
    // uintptr_t offset = (uintptr_t)&((Vector*)nullptr)->x;
    uintptr_t offset = offsetof(Vector, x);  // 系统自带宏定义
    LOG(offset);
}