/*!
*@file    Proxy.h
*@brief   ����ģʽ
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
    virtual void OrderFood() {}  // ������
};

// ����Ա
class Programmer : public Person 
{
public:
    void OrderFood()
    {
        std::cout << "����Ա������" << std::endl;
    }
};


// ����С��
class TakeAwayBrother : public Person 
{
public:

    TakeAwayBrother(Person* person) : m_person(person) {}
    
    void OrderFood()
    {
        std::cout << "������app" << std::endl;
        std::cout << "����Ա������" << std::endl;
        std::cout << "����С��ӵ�������" << std::endl;
    }

private:
    Person* m_person;   // ���ã� �ⲿ�ͷ�
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