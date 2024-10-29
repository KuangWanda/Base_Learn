#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++数组
1.数组指针的偏移与具体的数据类型相关
*/

int main()
{
    int example[5];
    
    for (int i = 0; i < 5; i++)
    {
        example[i] = i;
    }

    int* ptr = example; 

    LOG(example);  // 输出数组的地址
    LOG(*ptr);  // 输出0
    LOG(*(ptr+1));  // 输出1
    // *(int*)((char*)ptr + 8) = 10;
    LOG(*(int*)((char*)ptr + 8));


    // 使用new来创建数组
    int* array = new int[5];

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;
    }
    LOG(array[4]);

    delete[] array;
}