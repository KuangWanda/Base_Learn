#include <iostream>

// 定义节点类
class Node
{
public:
    int data;   // 节点存储的数据
    Node *next; // 指向下一个节点的指针

    // 构造函数
    Node(int data) : data(data), next(nullptr) {}
};

// 定义链表类
class LinkedList
{
private:
    Node *head; // 链表的头指针
public:
    LinkedList()
        : head(new Node(0)) {}

    void InsertTail(int val) // 尾插法
    {
        Node *New_Node = new Node(val);
        Node *current = head;

        while (current->next)
        {
            current = current->next;
        }
        current->next = New_Node;
    }

    void InsertHead(int val) // 头插法
    {
        Node *New_Node = new Node(val);
        New_Node->next = head->next;
        head->next = New_Node;
    }

    void GetData()
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
            std::cout << current->data << "->";
        }
        std::cout << "NULL" << std::endl;
    }

    void DeleteTail()
    {
        Node *current = head;
        Node *n = head;
        if (!head->next)
            std::cout << "[TAIL_ERROR]:链表为空，删除失败！" << std::endl;
        while (current->next)
        {
            n = current;
            current = current->next;
        }
        n->next = nullptr;
        delete current;
    }

    void DeleteSingle(int val) // 删除第一个data=val的节点
    {
        bool flag = true;
        if (!head->next)
            std::cout << "[SINGLE_ERROR]:链表为空，删除失败！" << std::endl;
        else
        {
            Node *current = head->next;
            Node *before = head;
            while (current)
            {
                if (current->data == val)
                {
                    before->next = current->next;
                    flag = false;
                    delete current;
                    break;
                }
                else
                {
                    before = current;
                    current = current->next;
                }
            }
        }
        if (flag)
            std::cout << "[SINGLE_ERROR]:未找到对应数据，删除失败！" << std::endl;
    }

    void DeleteAll(int val) // 删除所有data=val的节点
    {
        int count = 0; // 记录删除个数
        if (!head->next)
            std::cout << "[ALL_ERROR]:链表为空，删除失败！" << std::endl;
        else
        {
            Node *current = head->next;
            Node *before = head;
            while (current)
            {
                if (current->data == val)
                {
                    count++;
                    before->next = current->next;
                    current = before->next;
                }
                else
                {
                    before = current;
                    current = current->next;
                }
            }
        }
        if (!count)
            std::cout << "[ALL_ERROR]:未找到对应数据，删除失败！" << std::endl;
        else
        {
            std::cout << "[ALL_INFO]:共删除" << count << "个数据！" << std::endl;
        }
    }

    void Reverse() // 使用头插法重新将链表元素插入
    {
        if (!head->next)
            std::cout << "[REVERSE_ERROR:]链表为空，翻转失败！" << std::endl;
        Node *New_Head = new Node(0);
        New_Head->next = head->next;
        head->next = nullptr;
        while (New_Head->next)
        {
            Node *current = New_Head->next;
            Node *node = new Node(current->data);
            node->next = head->next;
            head->next = node;
            New_Head->next = current->next;
            delete current;
        }
        std::cout << "[REVERSE_SUCCESS:]链表翻转成功！" << std::endl;
        delete New_Head;
    }

    Node *Find_Kth_From_Last(int k) // 返回链表的倒数第k个元素
    {
        int count = 0;
        Node *pre = head->next;
        Node *last = head->next;
        while (count < k && pre)
        {
            pre = pre->next;
            count++;
        }
        if (count < k)
        {
            std::cout << "[FKFL_ERROR]:链表元素不足" << k << "个，返回失败！" << std::endl;
            return pre;
        }
        else
        {
            while (pre)
            {
                pre = pre->next;
                last = last->next;
            }
        }
        std::cout << "[FKFL_SUCCESS]:链表倒数第" << k << "个元素的值是：" << last->data << std::endl;
        return last;
    }

    Node* FindLoop() // 查看链表内部是否存在环
    {
        // 如果存在环，快慢指针一定会相遇，且相遇的时候快指针的总步长是满指针的两倍
        bool flag = true;
        Node *slow = head->next;
        Node *fast = (head->next)->next;
        Node *n = new Node(0); 
        if (!head->next || !(head->next)->next)
            flag = false;
        else
        {
            while (flag)
            {
                if (slow != fast)
                {
                    if (!fast->next || !(fast->next)->next)
                        flag = false;
                    else
                    {
                        slow = slow->next;
                        fast = (fast->next)->next;
                    }
                }
                else
                    flag = false;
            }
        }

        if (flag)
        {
            std::cout << "[LOOP_ERROR]:链表存在环!" << std::endl;
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            n = slow;
        }
        else
        {
            std::cout << "[LOOP_SUCCESS]:链表不存在环!" << std::endl;
            n = nullptr;
        }
        return n;
    }
    ~LinkedList()
    {
        if (!head->next)
            delete head;
        else
        {
            Node *current = head->next;
            while (current)
            {
                head->next = current->next;
                current = head->next;
            }
        }
        delete head;
    }
};
