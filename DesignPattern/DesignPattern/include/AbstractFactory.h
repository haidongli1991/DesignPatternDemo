/*!
*@file    AbstractFactory.h
*@brief   抽象工厂模式
*/

#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

using std::cout;
using std::endl;

namespace abstractfactory
{
    class Car//车类
    {
    public:
        virtual void run(void) = 0;
    };

    class WhiteCar : public Car //白车
    {
    public:
        virtual void run(void){}
    };

    class WhiteBenzCar : public WhiteCar //白奔驰
    {
    public:
        WhiteBenzCar()
        {
            cout<<"WhiteBenzCar::WhiteBenzCar()"<<endl;
        }

        ~WhiteBenzCar(){}

        void run(void)
        {
            cout<<"WhiteBenzCar::run()"<<endl;
        }
    };

    class WhiteBwmCar : public WhiteCar //白宝马
    {
    public:
        WhiteBwmCar()
        {
            cout<<"WhiteBwmCar::WhiteBwmCar()"<<endl;
        }

        ~WhiteBwmCar(){}

        void run(void)
        {
            cout<<"WhiteBwmCar::run()"<<endl;
        }

    };

    class BlackCar : public Car //黑车
    {
    public:
        virtual void run(void){}
    };

    class BlackBenzCar : public BlackCar //黑奔驰
    {
    public:
        BlackBenzCar()
        {
            cout<<"BlackBenzCar::BlackBenzCar()"<<endl;
        }

        ~BlackBenzCar(){}

        void run(void)
        {
            cout<<"BlackBenzCar::run()"<<endl;
        }
    };

    class BlackBwmCar : public BlackCar //黑宝马
    {
    public:
        BlackBwmCar()
        {
            cout<<"BlackBwmCar::BlackBwmCar()"<<endl;
        }

        ~BlackBwmCar()
        {

        }

        void run(void)
        {
            cout<<"BlackBwmCar::run()"<<endl;
        }
    };

    class Factory // 工厂
    {
    public:
        Factory(){}
        virtual ~Factory(){}

    public:
        virtual Car* createBlackCar() = 0;
        virtual Car* createWhiteCar() = 0;
    };

    class BenzCarFactory: public Factory //奔驰车厂
    {
    public:
        BenzCarFactory(){}
        ~BenzCarFactory(){}

    public:
        Car* createBlackCar()
        {
            return new BlackBenzCar;
        }

        Car* createWhiteCar()
        {
            return new WhiteBenzCar;
        }
    };

    class BwmCarFactory: public Factory //宝马车厂
    {
    public:
        BwmCarFactory(){}
        ~BwmCarFactory(){}

    public:
        Car* createBlackCar()
        {
            return new BlackBwmCar;
        }

        Car* createWhiteCar()
        {
            return new WhiteBwmCar;
        }
    };

    void AbstractFactoryTest()
    {
        Factory* pCarfacA = new BenzCarFactory;
        Factory* pCarfacB = new BwmCarFactory;

        Car* pCarA1 = pCarfacA->createBlackCar();
        Car* pCarA2 = pCarfacA->createWhiteCar();
        Car* pCarB1 = pCarfacB->createBlackCar();
        Car* pCarB2 = pCarfacB->createWhiteCar();

        pCarA1->run();
        pCarA2->run();
        pCarB1->run();
        pCarB2->run();

        delete pCarfacA;
        delete pCarfacB;
        delete pCarA1; 
        delete pCarA2; 
        delete pCarB1;
        delete pCarB2;
    }
}

#endif // ABSTRACTFACTORY_H