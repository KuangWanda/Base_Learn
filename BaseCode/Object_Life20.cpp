#include <iostream>
#include <string>
#include <memory>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++对象的生存期和作用域指针
1.使用new可以为变量在堆上分配内存，需要注意手动销毁
2.使用作用域指针，不仅能实现在堆上分配内存，而且在作用域之后可以自动销毁
*/

class Entity
{
public:
    Entity()
    {
        LOG("创建类成功");
    }

    ~Entity()
    {
        LOG("销毁类成功");
    }
};

class ScopePtr
{
private:
    Entity* m_Ptr;
public:
    ScopePtr(Entity* ptr)
        : m_Ptr(ptr) {}
    
    ~ScopePtr()
    {
        LOG("销毁ScopePtr");
        delete m_Ptr;
    }
};

int* CreatArray()
{
    // 在函数体中分配的内存在函数结束之后释放
    int array[50];
    array[25] = 666;
    return array;  // warning: address of local variable 'array' returned [-Wreturn-local-addr]
}

int* CreatArray_Heap()
{
    // 在堆上创建数组
    int* arrray = new int[50];
    arrray[25] = 666;
    return arrray;
}


int main()
{
    // 直接执行main()函数，会输出创建类成功、创建类成功、销毁类成功，表明基于栈分配的对象，在作用域结束后销毁；基于堆分配的对象，在作用域后保持存在
    {
        Entity e1;  // 基于栈分配的对象，在作用域结束后销毁

        Entity* e2 = new Entity();  // 基于堆分配的对象，在作用域后保持存在
    }

    int* a = CreatArray();
    // LOG(a[25]);  // core dump

    int* a_heap = CreatArray_Heap();
    LOG(a_heap[25]);  // 输出666

    delete a_heap;


    {
        ScopePtr e = new Entity();  // 即使使用了new，但是作用域结束后的析构函数会帮助释放内存
    }
}