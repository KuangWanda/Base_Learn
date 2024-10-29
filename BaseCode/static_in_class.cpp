#include <iostream>

#define LOG(x) std::cout << x << std::endl;
// 学习内容：C++类和结构体中的静态
/*
  在类（结构体）中将变量声明为static变量，会使得这些变量在类（结构体）的所有实
  例中只有一个实例。所有的实例的静态变量指向了同一个地址
*/

/*
  作用：如果希望在类或者结构体中的全部实例中共享某些信息，可以使用静态变量的方法
*/

class Entity
{
public:
  int x, y;
  void print()
  {
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  }
};

class Entity_Static
{
public:
  static int x, y;
  int z;

  void print()
  {
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
  }

  static void Print()
  {
    // 静态函数中只能识别静态变量，因为静态方法没有具体实例
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
  }
};

int Entity_Static::x; // 类或者结构体中的静态变量需要在全局声明
int Entity_Static::y;

class Test
{
private:
  static int m;
public:
  void Print_Static()  // 私有静态变量不仅需要全局声明，而且不能直接调用，需要在类内设计相关函数
  {
    LOG(m);
  }
};

int Test::m = 1000;

int main()
{
  Entity e;
  e.x = 5;
  e.y = 6;
  // e.print();

  Entity_Static es1;
  es1.x = 10;
  es1.y = 20;
  es1.z = 30;

  Entity_Static es2;
  es2.x = 15;
  es2.y = 25;
  es2.z = 35;

  /*
    e2应该直接写成：
    Entity_Static::x = 15
    Entity_Static::y = 25
  */

  es1.print(); // 输出x = 15, y = 25, z = 30;
  es2.print();

  Entity_Static::Print();

  LOG(&es1.x);
  LOG(&es2.x); // 输出的结果是一致的

  Test t;
  t.Print_Static();
}