/*!
*@file    Prototype.h
*@brief   ������ģʽ
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// �������
class Monkey  
{
public:

    Monkey(): m_name(""), m_skill(""), m_master("") {}

    Monkey(const Monkey& monkey)
    {
        this->m_name = monkey.m_name;
        this->m_skill = monkey.m_skill;
        this->m_master = monkey.m_master;
    }

    ~Monkey() {}

    Monkey& operator =(const Monkey& monkey)
    {
        if (this != &monkey)
        {
            this->m_name = monkey.m_name;
            this->m_skill = monkey.m_skill;
            this->m_master = monkey.m_master;
        }

        return *this;
    }

    void SetName(std::string name) {m_name = name;}
    void SetSkill(std::string skill) {m_skill = skill;}
    void SetMaster(std::string master) {m_master = master;}
    std::string GetName() {return m_name;}
    std::string GetSkill() {return m_skill;}
    std::string GetMaster() {return m_master;}

    Monkey* Clone()
    {
        return new Monkey(*this);
    }

    void Show()
    {
        std::cout << "name = " << GetName() << " ,skill = "<< GetSkill() << " ,master = "<< GetMaster()<< std::endl;
    }

private:
    std::string m_name;    // ����
    std::string m_skill;   // ����
    std::string m_master;  // ʦ��
};


void PrototypeTest()
{
    //���������
    Monkey* monkey = new Monkey();
    monkey->SetName("�������");
    monkey->SetSkill("��ʮ����");
    monkey->SetMaster("��ɮ");
    monkey->Show();   

    //�ٱ����
    Monkey* monkeysub1 = monkey->Clone();
    monkeysub1->SetName("�����");
    monkeysub1->Show();   

    Monkey* monkeysub2 = monkey->Clone();
    monkeysub2->SetName("�ƺ���");
    monkeysub2->Show();   

    Monkey* monkeysub3 = monkey->Clone();
    monkeysub3->SetName("�̺���");
    monkeysub3->Show();   

    delete monkeysub3;
    delete monkeysub2;
    delete monkeysub1;
    delete monkey;
}

#endif // PROTOTYPE_H