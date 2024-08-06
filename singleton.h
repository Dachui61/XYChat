#ifndef SINGLETON_H
#define SINGLETON_H
/******************************************************************************
 *
 * @file       singleton.h
 * @brief      单例模式
 *
 * @version    1.0
 * @date       2024/07/31
 * @history
 *             - 2024/07/31: 创建文件，XiaoYu
 *****************************************************************************/
#include <global.h>
template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator= (const Singleton<T>& st) = delete;

    static std::shared_ptr<T> _instance;

public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag flag;
        std::call_once(flag , [&](){
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }

    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }

    ~Singleton(){
        std::cout << "this is singleton destruct" << std::endl;
    }
};

// 静态成员变量定义
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;


#endif // SINGLETON_H
