/*!
*@file    Bridge.h
*@brief   �Ž�ģʽ
*/

#ifndef BRIDGE_H
#define BRIDGE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// ����ϵͳ������
class System
{
public:
    virtual void InstallSysImp() = 0;
};

class WindowsSystem : public System
{
    void InstallSysImp()
    {
        cout<< "��װ Windows ϵͳ"<<endl;
    }
};

class UniuxSystem : public System
{
    void InstallSysImp()
    {
        cout<< "��װ Uniux ϵͳ"<<endl;
    }
};

// ���Գ�����
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
        cout <<"Dell����";
        Computer::InstallSys(sys);
    }
};

class LenovoComputer : public Computer
{
public:
    LenovoComputer() {}

    void InstallSys(System* sys)
    {
        cout <<"Lenovo����";
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