/*!
*@file    Singleton.h
*@brief   单例模式
*/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    //get 方法
    static Singleton * getInstance(){
        if (NULL == instance) {
            //lock();  C++11特性 vs2010不支持
            //判断单例否
            if (NULL == instance) {
                instance = new Singleton();
            }
            //unlock();
        }
        //返回一个实例化的对象
        return instance;
    }
    //c++ 嵌套的内部类，作用是删除单例类对象，Garbage被定义为Singleton的私有内嵌类，以防该类被在其他地方滥用。
    class Garbage
    {
    public:
        ~Garbage(){
            if (Singleton::instance != NULL) {
                cout << "单例类的唯一实例被析构了" << endl;
                delete Singleton::instance;
            }
        }
    };

private:
    //单例类中定义一个这样的静态成员变量，而它的唯一工作就是在析构函数中删除单例类的实例，利用程序在结束时析构全局变量的特性，选择最终的释放时机；
    static Garbage garbage;
    //声明一个静态的实例
    static Singleton *instance;
    //单例类的私有构造函数
    Singleton(){
        cout << "调用了单例类的构造函数" << endl;
    }
    //单例类的私有析构函数
    ~Singleton(){
        cout << "调用了单例类的析构函数" << endl;
    }
    //把拷贝构造函数声明为私有，就可以禁止外人拷贝对象，也不用实现它，声明私有即可
    Singleton(const Singleton &copy);
    //把赋值运算符重载为私有的，防止对象之间的赋值操作
    Singleton & operator=(const Singleton &other);
};
//初始化内部似有泪的静态变量，目睹是启动删除的析构函数，如果不初始化，就不会被析构
//内部类可以访问外部类的私有成员，外部类不能访问内部类的私有成员！
Singleton::Garbage Singleton::garbage;
//初始化instance为 null
Singleton * Singleton::instance = NULL;


void SingletonTest()
{
    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();
    Singleton *c = Singleton::getInstance();

    if (a == b) {
        cout << "a = b" << endl;
    }
}

#endif // SINGLETON_H
