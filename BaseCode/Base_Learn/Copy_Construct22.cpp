#include <iostream>
#include <cstring>
#include <memory>

#define LOG(x) std::cout << x << std::endl;
/*
学习内容：C++拷贝与复制构造函数
1.在main()函数中进行的复制称为浅拷贝，只是把所有的值进行了复制，因此，两个String的对象拥有相同的m_BUffer
  的值，即两个指针指向了同一处地址空间，但是由于析构函数的存在，这块地址空间在作用域结束之后被释放了两次，因此
  会出现程序崩溃
2.深拷贝会复制整个对象，实现深拷贝可以通过拷贝构造函数。
3.拷贝构造函数是一种构造函数，C++默认情况下会有一个拷贝构造函数
*/

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *s)
    {
        m_Size = strlen(s);
        m_Buffer = new char[m_Size + 1];
        for (int i = 0; i < m_Size; i++)
        {
            m_Buffer[i] = s[i];
        }
        // memcpy(m_Buffer, s, m_Size + 1);
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &s); // 声明为友元函数

    char &operator[](const int index) // 重载[]运算符
    {
        return m_Buffer[index]; // 返回类型是字符引用
    }

    /* String(const String& other)  // 默认的拷贝构造函数，进行浅拷贝
        : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {} */
    String(const String &other) // 自定义深拷贝函数，接受外来的String类型的变量
        : m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }
};

std::ostream &operator<<(std::ostream &stream, const String &s)
{
    stream << s.m_Buffer;
    return stream;
}

int main()
{
    String s("LYORVTE");
    String s_copy = s;
    s_copy[2] = 'K'; // 因为重载之后返回的类型是字符引用，因此可以直接更改字符串数组相应位置的值

    LOG(s);
    LOG(s_copy); // 只进行浅拷贝之后core dump
}