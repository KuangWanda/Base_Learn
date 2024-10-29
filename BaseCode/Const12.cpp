#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++ const关键字
1.const是一种规则，表示不希望变量的值发生改变，但这种规则可以不被遵守，如第59行
2.对于const类型的指针，即const int*，指针本身所代表的地址值是可以被修改的，但是地址指向的变量是不可以被修改的
3.对于int* const类型的变量，指针所指向的变量是可以修改的，但是指针本身代表的地址值是不能修改的
4.可以简单理解为const修饰的是左边最近的关键字，const int* a就是修饰变量a；int* const a就是修饰int*
5.int const* = const int*
6.总结一下，const修饰什么内容主要是看const左边是什么内容，无论是变量声明还是函数声明都遵循这个规则
*/

class Entity
{
private:
    int X;
    int* Y;
    int Z;

public:
    int Get_X() const  // 表示承诺这个函数不修改任何类的内容
    {
        // X = 2; // 修改不被允许
        return X; 
    }

    const int* const Get_Y() const  // 三个const表示返回一个不可修改的指针、指针指向的内容不可修改、这个函数承诺不修改类的任何变量
    /*
    第一个const表示返回的指针所指向的内容不可更改
    第二个const表示返回的指针本身代表的地址值不可更改
    第三个const表示这个函数是一个成员方法，并且不修改任何成员变量
    需要注意的是，第一个const和函数返回的类型没有关系，函数返回的是int类型的指针，const的作用还是遵循左手原则（详见学习内容）
    */
    {
        return Y;
    }

    int Get_Z()
    {
        return Z;
    }
};

void PrintEntity(const Entity& e)  // 传递的参数是Entity对象的常量引用，任何对这个对象的修改都是不允许的
{
    std::cout << e.Get_X() << std::endl;  // Get_X()声明为const，可以通过编译
    // std::cout << e.Get_Z() << std::endl;  // Get_Z没有声明为const，可能会引起e的内容的修改，因此编译不通过
}


int main()
{
    const int LARGE_NUM = 100; // 一个不可更改的常量

    int *a = new int; // 非常量指针可以直接修改指向的地址所存储的值
    *a = 2;
    LOG(*a);

    a = (int *)&LARGE_NUM; // 可以这样修改，但是通常情况下不推荐，注意取地址符号'&'
    LOG(*a);

    const int *b = new int;
    b = (int *)&LARGE_NUM; // 程序也会崩溃
    LOG(*b);               // 可以对b本身的值（其所代表的地址）进行修改
    // *b = 10;  // 对常量指针所指向的地址存储的值进行修改是不被允许的

    int *const c = new int;
    // c = a;  // 直接修改c的值，也就是指针本身的地址值是不被允许的
    *c = 10;
    LOG(*c);

    Entity e;
    PrintEntity(e);
}