#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++多线程
1.使用多线程编程时，需要特别注意局部变量和全局变量的使用
  在test()中设置了一个局部变量a并将其引用传递给了Plus()函数，此时x正常执行+1操作
  但是由于Plus()中存在循环导致Plus()函数执行速度慢，所以test()函数先执行完毕。此
  时由于a是test()中的局部变量，因此a原本的地址存放的2被位置数据覆盖，导致x第二次输
  出的结果变成一个未知数据。
2.如果想消除上述问题，可以选择将a变成全局变量，也可以将t.join()放在test()中。
*/


std::thread t;

void Print(std::string msg)
{
    LOG(msg);
}

void Plus(int &x)
{
    x += 1;
    std::cout << "1st x = " << x << std::endl;
    int too = 0;
    for (int i = 0; i < 100000; i++)
        too++;
    std::cout << "x = " << x << std::endl;
}

void test()
{
    int a = 1;
    t = std::thread(Plus, std::ref(a));
    std::cout << "a = " << a << std::endl;
}

int main()
{
    // 创建线程
    std::thread thread1(Print, "LZY"); // 函数所需要的参数也作为thread对象的参数传入

    // 主程序等待线程执行完成后再结束
    if (thread1.joinable()) // 判断是否可以使用join()函数
        thread1.join();

    int a = 1;
    // std::thread thread2(Plus, a);  // a是临时变量
    std::thread thread2(Plus, std::ref(a));
    LOG(a); // 此时主程序跳过线程的执行过程，输出1
    thread2.join();
    LOG(a); // 线程执行完毕，输出2

    test();
    t.join();


    // thread1.detach();  // 分离子线程和主线程，主线程结束之后，子线程可以继续在后台运行
}