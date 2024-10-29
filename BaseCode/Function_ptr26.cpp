#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++函数指针
1.函数指针的存在可以使得一个函数作为另一个函数的参数传入
*/

void Print(int val)
{
    std::cout << "Hello:" << val << std::endl;
}

void PrintVector(std::vector<int>& v, void(*function)(int))
{
    for (int vals : v)
        function(vals);
}

int main()
{
    auto s = Print;  // 函数名称后面不加()，相当于直接获得函数地址，此时s的类型是void (*s)()
    void (*kwd)(int) = Print;

    s(2);
    kwd(10);

    std::vector<int> v = {1, 2, 3, 4, 5};
    PrintVector(v, Print);
}