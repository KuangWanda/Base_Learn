#include <iostream>
#include <string>
#include <memory>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++智能指针
1.共享指针通过引用计数的方式管理，当引用计数为0时，指针才会销毁
2.弱指针可以通过共享指针进行赋值，但是不会增加引用数
*/

class Entity
{
private:
    int age;
public:
    Entity()
    {
        LOG("创建类成功");
    }

    Entity(int x) 
        : age(x) {}

    void Print()
    {
        LOG(age);
    }

    ~Entity()
    {
        LOG("销毁类成功");
    }
};

int main()
{
    std::shared_ptr<Entity> share_test;
    std::weak_ptr<Entity> weak_test;
    {
        std::unique_ptr<Entity> e1 = std::make_unique<Entity>();  // 更加安全
        // std::unique_ptr<Entity> e(new Entity());
        // std::unique_ptr<Entity> e2 = e1;  // 不被允许的操作，因为原始指针被释放后，后续所有因此而产生的指针都将受到影响

        std::shared_ptr<Entity> e_share = std::make_shared<Entity>(20);  // 共享指针
        share_test = e_share;  // 可以进行赋值操作，且在这个作用域结束之后不会自动销毁
        weak_test = e_share;  // 在这个作用域结束之后会自动销毁
    }
    share_test->Print();
}