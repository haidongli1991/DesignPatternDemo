/*!
*@file    Proxy.h
*@brief   代理模式
*/

#ifndef PROXY_H
#define PROXY_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Person  
{
public:
    virtual void OrderFood() {}  // 点外卖
};

// 程序员
class Programmer : public Person 
{
public:
    void OrderFood()
    {
        std::cout << "程序员点外卖" << std::endl;
    }
};


// 外卖小哥
class TakeAwayBrother : public Person 
{
public:

    TakeAwayBrother(Person* person) : m_person(person) {}
    
    void OrderFood()
    {
        std::cout << "打开外卖app" << std::endl;
        std::cout << "程序员点外卖" << std::endl;
        std::cout << "外卖小哥接单送外卖" << std::endl;
    }

private:
    Person* m_person;   // 引用， 外部释放
};

void ProxyTest()
{
    Person* pProgrammer = new Programmer();
    TakeAwayBrother* pBrother = new TakeAwayBrother(pProgrammer);
    pBrother->OrderFood();

    delete pBrother;
    delete pProgrammer;
}

#endif // PROXY_H