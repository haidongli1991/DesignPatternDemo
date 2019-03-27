/*!
*@file    SimpleFactory.h
*@brief   �򵥹���ģʽ
*/

#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <iostream>

using std::cout;
using std::endl;

namespace simplefactory
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
        virtual Car* create(int type) = 0;
    };

    class CarFactory: public Factory //����
    {
    public:
        Car* create(int type)
        {
            switch(type)
            {
            case 0://�����׳�
                return (new WhiteCar());
                break;
            case 1://�����ڳ�
                return (new BlackCar());
                break;
            default:
                return NULL;
                break;
            }
        }
    };

    void SimpleFactoryTest()
    {
        Factory* pCarfac = new CarFactory;
        Car* pCarA = pCarfac->create(0);
        Car* pCarB = pCarfac->create(1);

        pCarA->run();
        pCarB->run();

        delete pCarfac;
        delete pCarA; 
        delete pCarB;
    }
  
}

#endif // SIMPLEFACTORY_H