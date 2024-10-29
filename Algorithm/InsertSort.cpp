#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++插入排序
1.插入排序的原理是将新的元素从已经排好序的部分数组的后面向前遍历，找到第一个不大于的位置插入
2.插入排序的时间复杂度最好是O(N)，最坏是O(N^2),平均是O(N^2)
*/

template <typename T>
void InsertSort(std::vector<T>& v)
{
    int size = v.size();
    for (int i = 1; i < size; i++)
    {
        T tmp = v[i];  // 获取当前待排元素
        int j = i - 1; // 确定开始比较的位置
        while (j > -1 && v[j] > tmp)
        {
            v[j + 1] = v[j];
            v[j] = tmp; 
            j--;
        }
    }
}

int main()
{
    std::vector<float> array_f = {9.9f, 2.1f, 3.7f, 0.4f, 5.9f, 0.1f};
    InsertSort(array_f);
    for (auto val : array_f)
        LOG(val);
}