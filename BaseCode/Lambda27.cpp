#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++lambda函数
1.本质是一个匿名函数，用完即弃
2.只要有一个函数指针，就可以在C++中使用lambda
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
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto lambda = [](int value) {std::cout << "hello:" << value << std::endl;};
    PrintVector(v, lambda);
}