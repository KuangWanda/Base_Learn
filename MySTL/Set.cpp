#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++set容器
1.set的本质是集合，不会存储重复元素
2.set中的元素无法修改，因此如果需要引用，只能进行常量引用
3.set是有序集合，默认按照升序存储数据
*/

template<typename T>
void Print(std::set<T>& s)
{
    for (const T&  val : s)  // 常量引用
        std::cout << "value = " << val << std::endl;
}

int main()
{
    std::set<int> mys;
    mys.insert(1);
    mys.insert(5);
    mys.insert(2);

    LOG(mys.count(2));

    std::set<int>::iterator it = mys.lower_bound(2);  // 使用二分法查找第一个不小于某一个值的值，返回相应的迭代器
    LOG(*it);

    Print(mys);
}