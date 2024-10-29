#include <iostream>
#include <string>
#include <memory>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++模板
1.如果创建的函数大部分内容相同，只是可以接受的参数类型不一样，就可以时用木板
2.模板函数不是一个真正的函数，而是在调用的时候才会真正创建相应的函数
*/

template <typename T, int size>
class Array
{
private:
    T array[size]; // 由于是在栈上创建数组。因此不能直接把一个变量赋值给数组大小
public:
    int GetSize() const // 也可以把函数返回类型替换成为T
    {
        return size;
    }
};

template <typename T>
void Print(T val)
{
    LOG(val);
}

template <size_t size>
void PrintArr(std::array<int, size>& arr)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    // Print(5);
    Print<int>(5);  // <>中的内容可以理解为模板“函数”的参数

    Array<int, 5> array;
    LOG(array.GetSize());
}