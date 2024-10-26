#include <iostream>
#include <string>
#include <memory>
#include "Circle_SingleList.h"

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：
*/

int main()
{
    CircleSingleList* csl = new CircleSingleList();
    csl->InsertHead(1);
    csl->InsertHead(2);
    csl->InsertTail(3);
    // csl->Delete(200);
    csl->Find(2);
    csl->GetVal();
}