/*!
*@file    Prototype.h
*@brief   建造者模式
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// 孙悟空类
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
    std::string m_name;    // 名字
    std::string m_skill;   // 技能
    std::string m_master;  // 师傅
};


void PrototypeTest()
{
    //孙悟空真身
    Monkey* monkey = new Monkey();
    monkey->SetName("悟空真身");
    monkey->SetSkill("七十二变");
    monkey->SetMaster("唐僧");
    monkey->Show();   

    //再变分身
    Monkey* monkeysub1 = monkey->Clone();
    monkeysub1->SetName("红猴子");
    monkeysub1->Show();   

    Monkey* monkeysub2 = monkey->Clone();
    monkeysub2->SetName("黄猴子");
    monkeysub2->Show();   

    Monkey* monkeysub3 = monkey->Clone();
    monkeysub3->SetName("绿猴子");
    monkeysub3->Show();   

    delete monkeysub3;
    delete monkeysub2;
    delete monkeysub1;
    delete monkey;
}

#endif // PROTOTYPE_H