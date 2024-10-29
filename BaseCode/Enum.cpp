#include <iostream>

#define LOG(x) std::cout << x << std::endl;
// 学习内容：C++的枚举
/*
  枚举将一组数值集合作为类型，而不是仅仅用整数作为类型
  枚举中的变量必须是整形
  枚举本身不是一个命名空间，而是一个枚举类
*/

enum Example : char  // 可以使用char来减少内存的占用
{
    A,
    B,
    C // 默认是按照1、2、3的初始值
};

int main()
{
    Example value = B; // 枚举类型的实例的值只能是枚举内部的变量
    LOG(value);
}