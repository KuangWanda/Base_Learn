#include <iostream>
#include "Static_test.cpp"

#define LOG(x) std::cout << x << std::endl;

// 学习内容： C++中的静态

/* 
  任何变量、函数被声明为static类型时，只会在被声明的C++文件中被“看到”
*/

int global = 10;  // 1.如果相互关联的两个cpp文件中出现了相同的全局变量，会引起链接错误
extern int ex_global;  // 2.如果加入extern关键词，在连接过程中就会自动寻找其他地方定义的同名全局变量
int static_global = 7;  // 3.如果加入static关键词，类似于私有成员变量，其他地方会自动忽略

int main()
{
    LOG(global);
    LOG(ex_global);
    LOG(static_global);
}