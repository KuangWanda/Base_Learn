#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++二叉堆
1.二叉堆逻辑上是一个完全二叉树，但是实际上使用数组进行存储
2.如果父节点的编号是i，那么左孩子的编号是2*i+1，右孩子的编号是2*i+2
3.在二叉堆的基础上衍生出了大根堆和小根堆，表明了父节点和子结点之间的大小关系
4.大（小）根堆可以根据数组大小获得第一个非叶子节点的下标，下标减小，可以获得其余非叶子节点
5.大（小）根堆如果插入元素的话，会造成元素的上浮，每次都与当前所处位置的父节点进行比较，直到2找到合适位置
6.大（小）根堆如果删除元素的话，首先要删除堆顶元素，然后将堆尾元素放在堆顶，然后进行下沉操作
*/

template <typename T>
class MaxHeap
{
public:
    // void Insert(T data)
    // {
    //     if (!maxheap.size()) // 为空直接插入
    //         maxheap.emplace_back(data);
    //     else
    //     {
    //         int pos = maxheap.size();  // 记录初始插入位置
    //         maxheap.emplace_back(data);
    //         if (!pos % 2 )  // 此时插入位置在某个节点的右边
    //         {
    //             while (pos)
    //             {
    //                 if (data > maxheap[(pos-2)/2])
    //                 {
    //                     int tmp = maxheap[(pos-2)/2];
    //                     maxheap[(pos-2)/2] = data;
    //                     maxheap[pos] = tmp;
    //                     pos = (pos - 2) / 2;
    //                 }
    //                 else
    //                     break;
    //             }
    //         }
    //         else
    //         {
    //             while(pos)
    //             {
    //                 if (data > maxheap[(pos-1) / 2])
    //                 {
    //                     int tmp = maxheap[(pos-1)/2];
    //                     maxheap[(pos-1)/2] = data;
    //                     maxheap[pos] = tmp;
    //                     pos = (pos - 1) / 2;
    //                 }
    //                 else
    //                     break;
    //             }
    //         }
    //     }
    // }

    bool isEmpty()
    {
        if (maxheap.size())
            return false;
        return true;
    }

    void Insert(T data)
    {
        maxheap.emplace_back(data);
        Swim(maxheap.size() - 1);
    }

    void Delete()
    {
        if (!maxheap.size())
        {
            LOG("大根堆为空，删除失败！");
            return;
        }
        else
        {
            std::cout << "最大值是：" << maxheap[0] << std::endl;
            maxheap[0] = maxheap[maxheap.size() - 1];
            maxheap.pop_back();  // 删除最后一个元素
            if (!isEmpty())
                Sink(0);
        }
    }

    void Print()
    {
        for (T &val : maxheap)
            std::cout << val << " ";
        LOG("\n");
    }

private:
    std::vector<T> maxheap;

    void Swim(int pos) // 控制新加入的堆元素的上浮
    {
        while (pos && maxheap[pos] > maxheap[(pos - 1) / 2])
        {
            std::swap(maxheap[pos], maxheap[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }

    void Sink(int pos)
    {
        int size = maxheap.size();
        while(2 * pos + 1 < size)  // 确保有左孩子
        {
            int j = 2 * pos + 1;  // 记录左孩子位置
            if (j + 1 < size && maxheap[j + 1] > maxheap[j])  // 有右孩子并且更大
                j++;  // 将待比较节点选为右孩子
            if (maxheap[pos] > maxheap[j])
                return;
            std::swap(maxheap[pos], maxheap[j]);
            pos = j;
        }
    }
};

int main()
{
    MaxHeap<int> *m = new MaxHeap<int>();
    m->Insert(4);
    m->Insert(5);
    m->Insert(6);
    m->Insert(1);
    m->Insert(10);
    m->Delete();
    m->Print();
}