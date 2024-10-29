#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：创建并初始化C++对象
1.如果对象太大，或者需要显式地控制对象的生存期，就要在堆上创建，反之可以在栈上创建
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
    Entity e;  // 在栈上创建对象

    Entity* e1;
    {
        Entity e_tmp("KWd");
        e1 = &e_tmp;
    }  // 此时e_tmp已经被释放掉了
    std::cout << e1->GetName() << std::endl;

    Entity* e2 = new Entity("LZY");  // new会返回e2在堆上被分配的内存

    delete e2;

}