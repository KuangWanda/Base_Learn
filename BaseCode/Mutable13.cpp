#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：mutable关键字
1.与const关键字配合使用，即在const条件下也可以作出改变
2.在lanbda表达式中使用
*/

class Entity
{
private:
    std::string m_Name;
    mutable int count = 0;

public:
    const std::string &GetName() const
    {
        count++;  // 正常情况下是不可以执行这个操作的，只能声明为mutable属性
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();
}