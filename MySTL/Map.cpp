#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#define LOG(x) std::cout << x << std::endl
/*
学习内容：C++容器map
1.关于赋值：可以在初始化的时候直接使用{ {pair1}, {pair2} }的形式进行赋值
    
2.关于插入
    a.可以使用[key] = val 的形式进行赋值，key存在会直接进行覆盖
    b.使用insert()函数单值插入，此时插入的对象是std::pair<>，pair的类型和map一致，如果key已经存在，插入失败
    c.使用insert()函数指定位置插入，此时传入的参数是迭代器和待插入对象，但是需要使用std::advance()函数将迭代器转移到合适的位置
    d.列表形式插入，即使用{}的形式

3.关于conut(key& key)，可以返回对应的key的元素个数，对于map来说，非0即1

4.关于删除
    a.iterator erase(iterator pos)，删除指定迭代器位置的元素，并返回下一个位置的迭代器
    b.iterator erase(iterator pos1, iterator pos2)，删除指定范围内的元素，并返回下一个位置的迭代器，如果要选择中间的部分元素进行删除，那么需要创建两个迭代器对象分别从begin()处
    移动，同时需要注意的是删除的范围是左闭右开

5.顺序比较
    std::map有成员函数key_comp()来实现map内部两个函数key的比较，参与比较的两个key可以不实际存在于map对象中

6.查找
    map中使用find()函数通过key进行查找 iterator find (const key_type& k)，返回的类型是一个迭代器

其他：
    std::advance(it, 2)并不是返回一个新的迭代器，而是将传入的迭代器移动指定大小的位置
*/

void Print(std::map<std::string, int>& m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        std::cout << "key = " << it->first << " " << "value = " << it->second << std::endl;
    }
}

int main()
{
    // 初始化map之直接赋值
    std::map<std::string, int> mymap = {
        {"Mike", 24},
        {"John", 27},
        {"Hellen", 21}};

    // for (auto it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << "key = " << it->first << " " << "value = " << it->second << std::endl;
    //     /*
    //         输出的顺序是Hellen John Mike
    //         可以看出map是在初始化的过程中对key值进行了排序
    //     */
    // }

    mymap["Jack"] = 31;  // 没有的key值会直接添加
    mymap["Mike"] = 28;  // 已有的key值会覆盖

    mymap.insert(std::pair<std::string, int>("Green", 37));
    
    // 判断是否插入成功
    // std::pair<std::map<std::string, int>::iterator, bool> ret;

    // ret = mymap.insert(std::pair<std::string, int>("Jack", 500));
    // if (ret.second == false) {
    //     std::cout << "element Jack already existed";
    //     std::cout << " with a value of " << ret.first->second << '\n';
    // }

    std::map<std::string, int>::iterator it = mymap.begin();
    mymap.insert(mymap.begin(), std::pair<std::string, int>("Blue", 16));

    it = mymap.begin();
    std::advance(it, 3);  // 将迭代器向后移动三个位置
    mymap.insert(it, std::pair<std::string, int>("Candy", 19));

    mymap.insert({{"Jack", 34}});  // 插入已有key值不会覆盖
    
    std::cout << mymap.size() << std::endl;

    // std::cout<< mymap.count("Jack") << std::endl;

    // mymap.erase(it);

    std::map<std::string, int>::iterator pos1 = mymap.begin();
    std::map<std::string, int>::iterator pos2 = mymap.begin();

    // std::advance(pos1, 1);
    // std::advance(pos2, 3);

    // mymap.erase(pos1, pos2);

    // std::map<char, int>::key_compare 告诉编译器，我们要使用的是 std::map 类（其中键的类型是 char，值的类型是 int）内部定义的 key_compare 类型
    std::map<std::string, int>::key_compare compare = mymap.key_comp();
    LOG(compare("AA", "BB"));

    it = mymap.find("Jack");
    std::cout << it->second << std::endl;

    Print(mymap);
}