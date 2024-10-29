#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++中的隐式构造函数和explicit关键字
1.expilct关键字禁止隐式构造函数的使用
*/

class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    Entity(const std::string& name) 
        : m_Name(name), m_Age(-1) {}

    explicit Entity(int age)
        : m_Name("UnKnown"), m_Age(age) {}

    void PrintInfo()
    {
        std::cout << m_Name << std::endl;
        std::cout << m_Age << std::endl;
    }
};

void PrintEntity(const Entity& e)
{

}

int main()
{
    // 直接赋值
    Entity e1("KWD");
    Entity e2(24);

    // 隐式构造函数
    Entity e3 = (std::string)"LZY";  // 直接使用"LZY"，编译器会理解为const char*类型
    // Entity e4 = 25;  // explict关键字使得这个隐式构造函数失效

    // PrintEntity(25);  // 虽然PrintEntity这个函数的参数是Entity的对象，但是传递一个int类型的数据后，编译器会自动调用相应的构造函数进行一次隐式转换
    // PrintEntity((std::string)"LZY");  // 编译器只能进行一次隐式转换
    PrintEntity(Entity("LZY"));
}