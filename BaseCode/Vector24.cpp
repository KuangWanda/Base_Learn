#include <iostream>
#include <string>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++动态数组及其优化
1.创建vector数组之后，每次push_back新元素时，如果vector的容量不够大，就需要重新分配内存，将原有内容复制到新的位置，
  然后删除旧位置的内存，这个过程就会拖慢速度
2.
  第一次复制拷贝：push_back第一组元素时，创建Vertex对象{1.f, 2.f, 3.f}，然后把这个对象复制进入vector中 +1
  第二次复制拷贝：push_back第二组元素时，创建Vertex对象{4.f, 5.f, 6.f}，同时原本的空间不够，因此新申请了一部分空间，将{4.f, 5.f, 6.f}
                送入新空间，同时把原空间的{1.f, 2.f, 3.f}复制到新空间 1 +2 
  第三次复制拷贝：同理，push_back第二组元素时，创建Vertex对象{7.f, 8.f, 9.f}，同时原本的空间不够，因此新申请了一部分空间，
               将{4.f, 5.f, 6.f}送入新空间，同时把原空间的{1.f, 2.f, 3.f}和{4.f, 5.f, 6.f}和复制到新空间 1 + 2 + 3
------------------创建新对象1 2 3
执行拷贝构造函数1 2 3
------------------创建新对象4 5 6
执行拷贝构造函数4 5 6
------------------创建新对象1 2 3
执行拷贝构造函数1 2 3
------------------创建新对象7 8 9
执行拷贝构造函数7 8 9
------------------创建新对象1 2 3
执行拷贝构造函数1 2 3
------------------创建新对象4 5 6
执行拷贝构造函数4 5 6

3.基于上述内容的vector优化策略包括：
  （1）.告诉vector，我们希望它的容量是3
  （2）.添加新的元素时，不要先在main()函数中创建在复制，直接在指定位置生成
*/
struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) 
    {}

    Vertex(const Vertex &vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "------------------创建新对象" << vertex.x << " " <<  vertex.y << " " << vertex.z << std::endl;
        std::cout << "执行拷贝构造函数" << this->x << " " <<  this->y << " " << this->z << std::endl;
    }
};

std::ostream &operator<<(std::ostream &stream, Vertex &v)
{
    std::cout << "x = " << v.x << ", y = " << v.y << ", z = " << v.z << std::endl;
    return stream;
}

int main()
{
    // Vertex *v1 = new Vertex[5]; // 固定大小分配

    //  没有任何优化手段，执行了6次拷贝复制
    // std::vector<Vertex> v2; // 动态数组
    // v2.push_back({1.f, 2.f, 3.f});
    // v2.push_back({4.f, 5.f, 6.f});
    // v2.push_back({7.f, 8.f, 9.f});


    // 申请足够大的内存，执行三次拷贝函数
    // std::vector<Vertex> v2;
    // v2.reserve(3);  // 直接指明所需要的空间大小，如果超出了申请的范围，还是会执行之前的步骤，即申请新的空间，把现有的内容复制到新的空间
    // v2.push_back({1.f, 2.f, 3.f});
    // v2.push_back({4.f, 5.f, 6.f});
    // v2.push_back({7.f, 8.f, 9.f});
    // v2.push_back({10.f, 11.f, 12.f});  // 计划之外的内容

    // 直接在指定位置生成对象，不需要现在main()中生成再复制
    std::vector<Vertex> v2;
    v2.reserve(3);  // 直接指明所需要的空间大小，如果超出了申请的范围，还是会执行之前的步骤，即申请新的空间，把现有的内容复制到新的空间
    v2.emplace_back(1.f, 2.f, 3.f);
    v2.emplace_back(4.f, 5.f, 6.f);
    v2.emplace_back(7.f, 8.f, 9.f);

    for (Vertex &v : v2) // 避免不必要的复制
        std::cout << v;
}