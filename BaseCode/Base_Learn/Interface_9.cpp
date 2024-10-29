#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++接口（纯虚函数）
1.纯虚函数允许在基类中定义一个完全没有实现的函数，然后强制子类去实现该函数
2.类中的接口只包含未实现的方法，作为模板
3.父类中存在纯虚函数，子类必须对其进行实现才能完成实例化，因此，父类便无法实例化对象
4.因包含虚函数而不能实例化对象的类称为抽象类
*/

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Parent : public Printable
{
public:
    virtual std::string Getname() = 0;  // =0意味着这个函数设为纯虚函数

    std::string GetClassName() override
    {
        return "Parent";
    }
};

class Child : public Parent
{
private:
    std::string m_Name;

public:
    Child(const std::string& name) : m_Name(name) {}

    std::string Getname() override
    {
        return m_Name;
    }

    std::string GetClassName() override
    {
        return "Child";
    }
};

void Print(Printable* obj)  // 因为Printable是抽象类，因此不能实例化，传递的只能是指针变量
{
    LOG(obj->GetClassName());
}

int main()
{
    // Parent p;  // 无法实例化有虚函数的类的对象
    // Child c;  // 如果不改写父类中的纯虚函数，子类对象也不能实例化
    Child *c = new Child("kwd");
    Child c1("kkk");
    // LOG(c.Getname());
    Print(c);
    Print(&c1);
}