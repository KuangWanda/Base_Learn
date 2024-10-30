#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++归并排序
1.采用分治的思想，先进行序列划分，再进行元素的有序合并
2.需要开辟额外的内存空间存储有序的小的数据集合
*/

template <typename T>
void Merge(std::vector<T> &v, int begin, int mid, int end)
{
    std::vector<T> array;
    array.reserve(end - begin + 1);

    int l = begin;
    int m = mid + 1;

    while (l <= mid && m <= end)
    {
        if (v[l] < v[m])
        {
            array.emplace_back(v[l++]); // 学习一下这个简便写法
        }
        else
        {
            array.emplace_back(v[m++]);
        }
    }
    while (l <= mid)
    {
        array.emplace_back(v[l++]);
    }
    while (m <= end)
    {
        array.emplace_back(v[m]);
        m++;
    }
    for (int i = begin, j = 0; i <= end; i++, j++)
    {
        v[i] = array[j];
    }
}

template <typename T>
void MergeSort_Recursion(std::vector<T> &v, int begin, int end) // 递归实现归并排序
{
    // if (begin == end)  // 递归结束不一定是要return，也可以直接不执行
    // {
    //     return;
    //     int mid = (begin + end) / 2;

    //     // 先递分解
    //     MergeSort_Recursion(v, begin, mid);
    //     MergeSort_Recursion(v, mid + 1, end);

    //     // 再归合并，把两个有序小段合并成一个大段
    //     Merge(v, begin, mid, end);
    // }

    if (begin == end) // 递归结束不一定是要return，也可以直接不执行
    {
        return;
    }
    int mid = (begin + end) / 2;

    // 先递分解
    MergeSort_Recursion(v, begin, mid);
    MergeSort_Recursion(v, mid + 1, end);

    // 再归合并，把两个有序小段合并成一个大段
    Merge(v, begin, mid, end);
}

int main()
{
    std::vector<float> array_f = {9.9f, 2.1f, 3.7f, 0.4f, 5.9f, 0.1f};

    MergeSort_Recursion(array_f, 0, array_f.size() - 1);

    for (auto val : array_f)
        LOG(val);
}
