#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++选择排序
1.选择排序的思路是先找到一组数据中的最大（小）值，然后再找剩余数中的最大（小）值
2.选择排序的时间复杂度无论最好还是最坏的情况都是O(N^2)
*/

template <typename T>
void SelectSort(std::vector<T>& v)
{
    int size = v.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] < v[i])
            {
                T tmp = v[j];
                v[j] = v[i];
                v[i] = tmp;
            }
        }
    }
}


int main()
{
    std::vector<int> array = {7, 6, 5, 4, 3, 2, 1};
    std::vector<float> array_f = {2.1f, 3.7f, 0.4f, 5.9f, 0.1f};
    SelectSort(array_f);
    for (float val : array_f)
        LOG(val);
}