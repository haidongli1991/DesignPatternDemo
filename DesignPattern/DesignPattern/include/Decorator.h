/*!
*@file    Decorator.h
*@brief   装饰器模式
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

    virtual void AddDescription(std::string str)  // 添加描述
    {
        m_description += str;
    }

    void ShowDescription() // 获取描述
    {
        std::cout<< m_description <<std::endl;
    }  

private:
    std::string m_description;  // 对饮料的描述
};

// 具体饮料类
// 果汁
class Juice : public Drink 
{
public:
    Juice() : Drink()
    {
        AddDescription("果汁");
    }
};


// 咖啡
class Cofffee : public Drink 
{
public:
    Cofffee() : Drink()
    {
        AddDescription("咖啡");
    }
};

// 装饰器类
class Decorator
{
public:
    Decorator(Drink* drink) : m_drink(drink) {}
    virtual ~Decorator() {}

    Drink* GetDrink() {return m_drink;}

    virtual void AddDecorate() = 0; // 添加装饰

private:
    Drink* m_drink; // 内嵌饮料引用, 外部释放
};

// 添加冰块
class Ice : public Decorator
{
public:
    Ice(Drink* drink) : Decorator(drink), m_decorate(", 添加冰块")
    {
    }

    void AddDecorate() 
    {
        GetDrink()->AddDescription(m_decorate);
    }

private:
    std::string m_decorate;
};

// 添加糖
class Sugar : public Decorator
{
public:
    Sugar(Drink* drink) : Decorator(drink), m_decorate(", 添加糖") {}

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