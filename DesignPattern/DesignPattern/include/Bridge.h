/*!
*@file    Bridge.h
*@brief   桥接模式
*/

#ifndef BRIDGE_H
#define BRIDGE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// 操作系统抽象类
class System
{
public:
    virtual void InstallSysImp() = 0;
};

class WindowsSystem : public System
{
    void InstallSysImp()
    {
        cout<< "安装 Windows 系统"<<endl;
    }
};

class UniuxSystem : public System
{
    void InstallSysImp()
    {
        cout<< "安装 Uniux 系统"<<endl;
    }
};

// 电脑抽象类
class Computer
{
public:
    Computer() {}

    virtual void InstallSys(System* sys)
    {
        sys->InstallSysImp();
    }
};

class DellComputer : public Computer
{
public:
    DellComputer() {}

    void InstallSys(System* sys)
    {
        cout <<"Dell电脑";
        Computer::InstallSys(sys);
    }
};

class LenovoComputer : public Computer
{
public:
    LenovoComputer() {}

    void InstallSys(System* sys)
    {
        cout <<"Lenovo电脑";
        Computer::InstallSys(sys);
    }
};

void BridgeTest()
{
    System* pWindowSys = new WindowsSystem;
    System* pUniuxSys = new UniuxSystem;
    
    Computer* pDellComputer = new DellComputer;
    Computer* pLenovoComputer = new LenovoComputer;

    pDellComputer->InstallSys(pUniuxSys);
    pLenovoComputer->InstallSys(pWindowSys);

    delete pLenovoComputer;
    delete pDellComputer;
    delete pUniuxSys;
    delete pWindowSys;
}

#endif // BRIDGE_H