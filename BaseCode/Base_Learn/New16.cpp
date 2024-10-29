#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++new关键字
1.new的目的主要是在堆上分配内存，因此使用new之后返回的是一个指针
*/

class Entity
{
private:
    std::string m_Name;
public:
    Entity() : m_Name("UnKnown") {}
    Entity(const std::string& name) : m_Name(name) {}

    const std::string& GetName() const
    {
        return m_Name;
    }
};

int main()
{
    int a = 5;
    int* b = new int;
    LOG(*b);
    int* array = new int[50];  // 创建数组

    Entity* e = new Entity("KWD");
    Entity* e1 = new Entity;
    *e1 = Entity("LZY");
    std::cout << e1->GetName() << std::endl;

    delete[] b;
    delete array;
    delete e;

}