#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：构造函数初始化列表
1.如钩需要重载构造函数，最好把缺省的构造函数也一并写出
*/

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity()
        : m_Name("UnKnon"), m_Age(18) {}  // 需要按照顺序对成员变量进行初始化

    // Entity()
    // {
    //     m_Name = "UnKnown";
    // }

    Entity(const std::string& name) : m_Name(name) {}

    // Entity(const std::string& name)
    // {
    //     m_Name = name;
    // }

    const std::string& GetName() const
    {
        return m_Name;
    }

    const int& Get_age() const
    {
        return m_Age;
    }
};

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;
    LOG(e0.Get_age());

    Entity e1("KWD");
    std::cout << e1.GetName() << std::endl;
    LOG(e1.Get_age());
    
}