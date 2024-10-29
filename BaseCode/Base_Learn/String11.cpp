#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++字符串和字符串字面量
1.字符串字面量的本质就是一种特殊的指针或者引用
*/

int main()
{
    const char* name = "KWD";  // 从C++11开始，只支持这种写法，表明是不可修改的字符元素，或者char* name = (char*)"kwd"，但还是推荐标准写法
    // name[2] = 's';  // 不被允许的修改

    char s[4] = {'k', 'w', 'd', '\0'};  // 如果一定要修改char类型的元素，最好使用数组形式

    LOG(s);  // C++对char*进行了特殊处理，会直接输出对应地址的内容而不是地址值

    std::string s_name = "kwd";  // 鼠标放在kwd上可以看到它本身是一个const char[4]的类型，因此不能修改变量内容

    char name1 = 'k';  // char类型的变量一次最好只放一个字符

    
    
}