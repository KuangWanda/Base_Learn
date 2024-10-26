#include <iostream>
#include <string>
#include <memory>
#include "LinkList.h"

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：测试C++链表的功能
*/

int main()
{
    LinkedList* l = new LinkedList();
    l->InsertTail(1);
    l->InsertTail(3);
    l->InsertTail(5);
    l->InsertTail(7);
    l->InsertTail(9);
    l->InsertTail(11);
    l->Find_Kth_From_Last(2);
    l->FindLoop();
    // l->Reverse();
    // l->GetData();
}