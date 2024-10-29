#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++希尔排序
1.希尔排序是对直接插入排序的改良，将原本的数组分成若干组之后，在组内进行直接插入排序，然后不断缩小组内元素的间隔直到1
*/
template <typename T>
void ShellSort(std::vector<T> &v)
{
    int size = v.size();
    for (int gap = size / 2; gap > 0; gap /= 2)  // 设置选择的数据的间隔大小
    {
        for (int i = gap; i < size; i++)  
        {
            // 这里后面两个条件不变是因为这个过程实际上是选择每一个分组的头的过程，之后每一个数据都是新分组的头
            // 直到遇到第一个分组的第二个元素
            int j = i - gap;
            T tmp = v[i];
            while (j > -1 && v[j] > tmp)
            {
                v[j + gap] = v[j];
                v[j] = tmp;
                j-=gap;
            }
        }
    }
}

int main()
{
    std::vector<float> array_f = {2.1f, 3.7f, 0.4f, 5.9f, 0.1f};
    ShellSort(array_f);
    for (float val : array_f)
        LOG(val);
}