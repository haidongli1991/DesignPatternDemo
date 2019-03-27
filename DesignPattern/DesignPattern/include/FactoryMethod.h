/*!
*@file    FactoryMethod.h
*@brief   ��������ģʽ
*/

#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

using std::cout;
using std::endl;

namespace factorymethod
{
    class Car//����
    {
    public:
        virtual void run(void) = 0;
    };

    class WhiteCar : public Car //�׳�
    {
    public:
        WhiteCar()
        {
            cout<<"WhiteCar::WhiteCar()"<<endl;
        }
        virtual void run(void)
        {
            cout<<"WhiteCar::run()"<<endl;
        }
        ~WhiteCar()
        {

        }
    };

    class BlackCar : public Car //�ڳ�
    {
    public:
        BlackCar()
        {
            cout<<"BlackCar::BlackCar()"<<endl;
        }
        virtual void run(void)
        {
            cout<<"BlackCar::run()"<<endl;
        }
    };

    class Factory // ����
    {
    public:
        Factory(){}
        virtual ~Factory(){}

    public:
        virtual Car* create() = 0;
    };

    class BlackCarFactory: public Factory //�ڳ���
    {
    public:
        BlackCarFactory(){}
        ~BlackCarFactory(){}

    public:
        Car* create()
        {
            return new BlackCar;
        }
    };

    class WhiteCarFactory: public Factory //�׳���
    {
    public:
        WhiteCarFactory(){}
        ~WhiteCarFactory(){}

    public:
        Car* create()
        {
            return new BlackCar;
        }
    };

    void FactoryMethodTest()
    {
        Factory* pCarfacA = new BlackCarFactory;
        Factory* pCarfacB = new WhiteCarFactory;

        Car* pCarA = pCarfacA->create();
        Car* pCarB = pCarfacB->create();

        pCarA->run();
        pCarB->run();

        delete pCarfacA;
        delete pCarfacB;
        delete pCarA; 
        delete pCarB;
    }   
}

#endif // FACTORYMETHOD_H

