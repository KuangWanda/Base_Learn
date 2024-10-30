#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++快速排序
1.每次选择一个基准数，把小于基准数的数据放在基准数左边，反之放在右边。然后对基准数左边和右边的数进行相同的操作直到数组有序
2.关键在于基准数的选取，避免退化成冒泡排序
*/

template <typename T>
int GetPosition(std::vector<T> &v, int begin, int end)
{
    T base = v[begin]; // 选定基准数
    int l = begin;
    int r = end;
    while (l != r)
    {
        while (v[r] > base && r > l)
        {
            r--;
        }

        if (l < r)
        {
            v[l] = v[r];
            l++;
        }

        while (r > l && v[l] < base)
        {
            l++;
        }

        if (l < r)
        {
            v[r] = v[l];
            r--;
        }
    }
    v[l] = base;
    return l;
}

template <typename T>
void QuickSort(std::vector<T> &v, int begin, int end)
{
    if (begin > end)
        return;
    int pos = GetPosition(v, begin, end);
    QuickSort(v, begin, pos - 1);
    QuickSort(v, pos + 1, end);
}

int main()
{
    std::vector<float> array_f = {2.1f, 3.7f, 0.4f, 5.9f, 0.1f};
    QuickSort(array_f, 0, array_f.size() - 1);
    for (float val : array_f)
        LOG(val);
}