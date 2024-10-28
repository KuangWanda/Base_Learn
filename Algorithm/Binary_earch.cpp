#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：二分查找
1.二分查找只适用于有序序列
2.递归一定要有结束的条件
*/

void BinarySearch(std::vector<int> &v, int &target) // 非递归方式进行二分查找
{
    int size = v.size();
    int left = 0;
    int right = size - 1;
    int mid = (right - left) / 2;
    while (left <= right)
    {
        if (v[mid] == target)
        {
            std::cout << "第" << mid + 1 << "个数是目标值";
            break;
        }
        else if (v[mid] < target)
        {
            left = mid + 1;
            mid = left + (right - left) / 2;
        }
        else if (v[mid] > target)
        {
            right = mid - 1;
            mid = left + (right - left) / 2;
        }
        else
        {
            std::cout << "未找到目标值" << std::endl;
        }
    }
}

int BinarySearch_Recursion(std::vector<int> &v, int &target, int left, int right) // 递归方法
{
    int mid = (right - left) / 2 + left;
    int x;
    if (right <= left)
    {
        std::cout << "未找到目标值" << std::endl;
        return -1;
    }
    else
    {
        if (v[mid] == target)
        {
            std::cout << "第" << mid + 1 << "个数是目标值";
            return mid + 1;
        }
        else if (v[mid] < target)
            return BinarySearch_Recursion(v, target, mid + 1, right);
        else
            return BinarySearch_Recursion(v, target, left, mid - 1);
    }
}

int main()
{
    std::vector<int> array = {12, 25, 34, 39, 45, 57, 63, 78, 82, 96, 100};
    int target = 34;
    // BinarySearch(array, target);
    int index = BinarySearch_Recursion(array, target, 0, array.size() - 1);
}