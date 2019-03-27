/*!
*@file    Decorator.h
*@brief   װ����ģʽ
*/

#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Drink  
{
public:

    Drink() : m_description("") {}

    virtual ~Drink() {}

    virtual void AddDescription(std::string str)  // �������
    {
        m_description += str;
    }

    void ShowDescription() // ��ȡ����
    {
        std::cout<< m_description <<std::endl;
    }  

private:
    std::string m_description;  // �����ϵ�����
};

// ����������
// ��֭
class Juice : public Drink 
{
public:
    Juice() : Drink()
    {
        AddDescription("��֭");
    }
};


// ����
class Cofffee : public Drink 
{
public:
    Cofffee() : Drink()
    {
        AddDescription("����");
    }
};

// װ������
class Decorator
{
public:
    Decorator(Drink* drink) : m_drink(drink) {}
    virtual ~Decorator() {}

    Drink* GetDrink() {return m_drink;}

    virtual void AddDecorate() = 0; // ���װ��

private:
    Drink* m_drink; // ��Ƕ��������, �ⲿ�ͷ�
};

// ��ӱ���
class Ice : public Decorator
{
public:
    Ice(Drink* drink) : Decorator(drink), m_decorate(", ��ӱ���")
    {
    }

    void AddDecorate() 
    {
        GetDrink()->AddDescription(m_decorate);
    }

private:
    std::string m_decorate;
};

// �����
class Sugar : public Decorator
{
public:
    Sugar(Drink* drink) : Decorator(drink), m_decorate(", �����") {}

    void AddDecorate() 
    {
        GetDrink()->AddDescription(m_decorate);
    }

private:
    std::string m_decorate;
};

void DecoratorTest()
{
    Drink* pJuice = new Juice();
    Ice* pDecoJuice = new Ice(pJuice);
    pDecoJuice->AddDecorate();
    pJuice->ShowDescription();

    Drink* pCoffee = new Cofffee();
    Sugar* pDecoCoffee1 = new Sugar(pCoffee);
    pDecoCoffee1->AddDecorate();
    Ice* pDecoCoffee2 = new Ice(pCoffee);
    pDecoCoffee2->AddDecorate();
    pCoffee->ShowDescription();

    delete pDecoCoffee2;
    delete pDecoCoffee1;
    delete pCoffee;
    delete pDecoJuice;
    delete pJuice;
}

#endif // DECORATOR_H