/*!
*@file    Adapter.h
*@brief   ������ģʽ
*/

#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>

using std::cout;
using std::endl;

class ComputerNew  
{
public:
    virtual void Open() = 0;
};

class ComputerOld 
{
public:
    void SpecialOpen() {std::cout << "oldcomputer is opening..." << std::endl;}
};

// ��������
class ComputerClassAdapter : public ComputerNew, public ComputerOld
{
public:

    ComputerClassAdapter()
    {
        std::cout << "���������� " << std::endl;
    }

    void Open()
    {
        DoConvert();
        SpecialOpen();
    }

private:
    void DoConvert()
    {
        std::cout << "oldcomputer convert to newcomputer" << std::endl;
    }
};


// ����������
class ComputerObjectAdapter : public ComputerNew
{
public:
    ComputerObjectAdapter(const ComputerOld& computer)
    {
        std::cout << "������������ " << std::endl;
        std::cout << "oldcomputer convert to newcomputer" << std::endl;
        m_computer = computer;
    }

    ~ComputerObjectAdapter()
    {
    }

    void Open()
    {
        m_computer.SpecialOpen();
    }

private:
    ComputerOld m_computer;
};



void AdapterTest()
{
    ComputerNew* computer1 = new ComputerClassAdapter();
    computer1->Open();

    std::cout << std::endl;

    ComputerOld* computerold = new ComputerOld();
    ComputerNew* computernew = new ComputerObjectAdapter(*computerold);
    computernew->Open();

    delete computer1;
    delete computerold;
    delete computernew;
}

#endif // ADAPTER_H