/*!
*@file    Builder.h
*@brief   ������ģʽ
*/

#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>

using std::cout;
using std::endl;

// �����߻���
class Builder  
{
public:
    virtual void BuildHost() {}
    virtual void BuildDisplay() {}
    virtual void BuildKeyBoard(){}
    virtual void BuildMouse() {}
};

// Mac����
class MacBuilder : public Builder
{
public:
    void BuildHost() { cout<<"build Mac Host"<<endl; }
    void BuildDisplay() { cout<<"build Mac Display"<<endl; }
    void BuildKeyBoard() { cout<<"build Mac KeyBoard"<<endl; }
    void BuildMouse() { cout<<"build Mac Mouse"<<endl; }
};

// Dell����
class DellBuilder : public Builder
{
public:
    void BuildHost() { cout<<"build Dell Host"<<endl; }
    void BuildDisplay() { cout<<"build Dell Display"<<endl; }
    void BuildKeyBoard() { cout<<"build Dell KeyBoard"<<endl; }
    void BuildMouse() { cout<<"build Dell Mouse"<<endl; }
};

// �����ָ�ӹ�
class Director  
{
private:
    Builder *m_pBuilder;
public:
    Director(Builder *builder) { m_pBuilder = builder; }
    
    void Build(){
        m_pBuilder->BuildHost();
        m_pBuilder->BuildDisplay();
        m_pBuilder->BuildKeyBoard();
        m_pBuilder->BuildMouse();
    }
};

void BuilderTest()
{
    DellBuilder mac;
    Director director1(&mac);
    director1.Build();

    cout<<endl;

    DellBuilder dell;
    Director director2(&dell);
    director2.Build();
}

#endif // BUILDER_H