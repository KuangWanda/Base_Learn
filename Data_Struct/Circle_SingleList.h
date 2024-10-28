#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "LinkList.h"

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：c++循环单链表
*/

// class Node
// {
// public:
//     int data;
//     Node *next;

// public:
//     Node(int val)
//         : data(val), next(nullptr) {}
// };

class CircleSingleList
{
private:
    Node *head;
    Node *tail; // 尾指针
public:
    CircleSingleList()
    {
        head = new Node(0);
        tail = head;
        head->next = head;
    }

    void InsertHead(int val)
    {
        Node *node = new Node(val);
        if (head->next == head)
        {
            head->next = node;
            node->next = head;
            tail = node;
        }
        else
        {
            node->next = head->next;
            head->next = node;
        }
    }

    void InsertTail(int val)
    {
        if (head == tail)
        {
            Node *node = new Node(val);
            head->next = node;
            node->next = head;
            tail = node;
        }
        else
        {
            Node *node = new Node(val);
            tail->next = node;
            node->next = head;
            tail = node;
        }
    }

    void GetVal()
    {
        Node *current = head->next;
        if (head == tail)
        {
            std::cout << "hhhh" << std::endl;
            std::cout << "[GETVAL_ERROR]:循环单链表为空！" << std::endl;
        }
        else
        {
            current = head->next;
            while (current != tail)
            {
                std::cout << current->data << "->";
                current = current->next;
            }
            std::cout << current->data << std::endl;
        }
    }

    void Delete(int val)
    {
        bool flag = false;
        if (head == tail)
            std::cout << "[DELETE_ERROE]:链表为空，删除失败！" << std::endl;
        else
        {
            Node *current = head->next;
            Node *after = head;
            while (current != tail)
            {
                if (current->data == val)
                {
                    after->next = current->next;
                    flag = true;
                    delete current;
                    break;
                }
                current = current->next;
                after = after->next;
            }
            if (tail->data == val) // 尾指针需要特殊处理
            {
                after->next = head;
                tail = after;
                flag = true;
            }
        }
        if (!flag)
            std::cout << "[DELETE_ERROE]:未找到目标节点，删除失败！" << std::endl;
    }

    bool Find(int val)
    {
        if (head == tail)
            std::cout << "[FIND_ERROE]:链表为空，查找失败！" << std::endl;
        else
        {
            Node *current = head->next;
            while (current != tail)
            {
                if (current->data == val)
                {
                    std::cout << "[FIND_SUCCESS]:查找成功！" << std::endl;
                    return true;
                }
                else
                {
                    current = current->next;
                }
            }
            if (current->data == val)
            {
                std::cout << "[FIND_SUCCESS]:查找成功！" << std::endl;
                return true;
            }
        }
        std::cout << "[FIND_ERROR]:未找到相应节点，查找失败！" << std::endl;
        return false;
    }

    void Josephus(int k, int m) // 约瑟夫环问题
    {
        Node *node = head;
        Node *slow = head;
        int count = 0;
        while (node != tail)
        {
            count++;
            node = node->next;
        }
        if (count < k)
            std::cout << "[Josephus_ERROR]:链表个数不足" << k << "个！" << std::endl;
        else
        {
            LinkList *l = new LinkList();
            node = head->next;
            int i = 1;
            while (i < k) // 先找起始节点
            {
                node = node->next;
                slow = slow->next;
                i++;
            }
            int num = 0;
            while (num < count)
            {
                i = 1;
                while (i < m)
                {
                    if (node == tail)
                    {
                        node = node->next->next;
                        slow = slow->next->next;
                        i++;
                    }
                    else
                    {
                        node = node->next;
                        slow = slow->next;
                        i++;
                    }
                }
                l->InsertTail(node->data);
                if (node == tail)
                {
                    slow->next = node->next;
                    node = head->next;
                    tail = slow;
                    slow = head;
                }
                else
                {
                    slow->next = node->next;
                    node = slow->next;
                }
                num++;
            }
            l->GetData();
        }
    }

    ~CircleSingleList()
    {
    }
};
