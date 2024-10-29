#include <iostream>

#define LOG(x) std::cout << x << std::endl;
// 学习内容：C++中的类

class Log
{
public:
    enum Level
    {
        Error = 0,
        Warning,
        Infomation
    };
    /* const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2; */

private:
    // int m_LogLevel = Info;
    Level m_LogLevel = Infomation;

public:
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    void Err(const char *message)
    {
        if (m_LogLevel >= 0)
            std::cout << "[ERROR]:" << message << std::endl;
    }

    void Warn(const char *message)
    {
        if (m_LogLevel >= 1)
            std::cout << "[WARNING]:" << message << std::endl;
    }

    void Info(const char *message)
    {
        if (m_LogLevel >= 2)
            std::cout << "[INFO]:" << message << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(Log::Warning);  // 参数也可以是log.Warning
    log.Warn("Hello!");
    log.Err("SSS");
}