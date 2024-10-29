#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：虚函数
1.虚函数允许在子类中重写方法，即父类中标记为virtual的函数可以在子类中被重写实现不同的功能
2.虚函数引入了一种名叫动态联编的东西，通过虚函数表实现编译
3.如果想覆写（override）一个函数，就必须将父类中的基函数标记为虚函数
4.虚函数不是无成本运行的，一方面需要额外的内存来存储虚表，其次执行时需要遍历虚表确定执行哪个虚函数
5.虚函数不能是静态的
*/

class Parent
{
public:
    // std::string GetName()
    // {
    //     return "Parent";
    // }

    virtual std::string GetName()
    {
        return "Parent";
    }
};

class Child : public Parent
{
private:
    std::string m_Name;

public:
    Child(const std::string &name) : m_Name(name) {}

    // std::string GetName()
    // {
    //     return m_Name;
    // }

    std::string GetName() override
    {
        return m_Name;
    }
};

void PrintName(Parent* p)  
{
    // 这个函数传入的参数是parent类型的指针，意味着会从Parent类的内部寻找对应函数
    LOG(p->GetName());
}

int main()
{
    Parent* p = new Parent();
    LOG(p->GetName());  // 输出Parent
    PrintName(p);  //输出Parent

    Child* c = new Child("kwd");
    LOG(c->GetName());  // 输出kwd
    PrintName(c);// 如果不使用虚函数，输出Parent，而不是kwd

    Parent* parent = c;  // 创建一个父类的指针指向子类
    LOG(parent->GetName());  // 如果不使用虚函数，输出内容Parent，不是kwd
    // LOG(parent->m_Name);  // 显示Parent类成员变量没有成员m_Name
}