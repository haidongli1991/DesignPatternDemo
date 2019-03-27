/*!
*@file    Facade.h
*@brief   ���ģʽ
*/

#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// ���ػ�ϵͳ
class OnOffSystem
{
public:
    void On()
    {
        std::cout << "�ֻ�����." << std::endl;
    }

    void Off()
    {
        std::cout << "�ֻ��ػ�." << std::endl;
    }
};

// ����ϵͳ
class PhotoSystem
{
public:
    void Photo()
    {
        std::cout << "����." << std::endl;
    }

    void Viedo()
    {
        std::cout << "¼����Ƶ." << std::endl;
    }
};

// ��ӵ绰ϵͳ
class CallSystem
{
public:
    void Call()
    {
        std::cout << "��绰." << std::endl;
    }

    void Pick()
    {
        std::cout << "�ӵ绰." << std::endl;
    }
};

class Phone  
{
public:
    Phone() : m_onOffSystem(nullptr), m_photoSystem(nullptr), m_callSystem(nullptr)
    {

    }

    void SetOnOff(OnOffSystem* system) 
    {
        m_onOffSystem = system;
    }

    void SetPhoto(PhotoSystem* system) 
    {
        m_photoSystem = system;
    }

    void SetCall(CallSystem* system) 
    {
        m_callSystem = system;
    }

    void On()
    {
        if (m_onOffSystem)
            m_onOffSystem->On();
    }

    void Off()
    {
        if (m_onOffSystem)
            m_onOffSystem->Off();
    }

    void Photo()
    {
        if (m_photoSystem)
            m_photoSystem->Photo();
    }

    void Vedio()
    {
        if (m_photoSystem)
            m_photoSystem->Viedo();
    }

    void Call()
    {
        if (m_callSystem)
            m_callSystem->Call();
    }

    void Pick()
    {
        if (m_callSystem)
            m_callSystem->Pick();
    }

private:
    OnOffSystem* m_onOffSystem;   // �ⲿ���ã������ͷ�
    PhotoSystem* m_photoSystem;   // ����װ�أ� ����û�У�����Ҳû��
    CallSystem* m_callSystem;
};

void FacadeTest()
{
    Phone* pFacade = new Phone;
    OnOffSystem* pOnOffSystem = new OnOffSystem;
    PhotoSystem* pPhotoSystem = new PhotoSystem;
    CallSystem* pCallSystem = new CallSystem;

    pFacade->SetOnOff(pOnOffSystem);
    //pFacade->SetPhoto(pPhotoSystem);  // ��װ�ش˹���
    pFacade->SetCall(pCallSystem);

    pFacade->On();
    pFacade->Photo();
    pFacade->Photo();
    pFacade->Vedio();
    pFacade->Call();
    pFacade->Call();
    pFacade->Pick();
    pFacade->Off();

    delete pCallSystem;
    delete pPhotoSystem;
    delete pOnOffSystem;
    delete pFacade;
}

#endif // PROXY_H