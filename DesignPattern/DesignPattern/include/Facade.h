/*!
*@file    Facade.h
*@brief   外观模式
*/

#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// 开关机系统
class OnOffSystem
{
public:
    void On()
    {
        std::cout << "手机开机." << std::endl;
    }

    void Off()
    {
        std::cout << "手机关机." << std::endl;
    }
};

// 照相系统
class PhotoSystem
{
public:
    void Photo()
    {
        std::cout << "拍照." << std::endl;
    }

    void Viedo()
    {
        std::cout << "录制视频." << std::endl;
    }
};

// 打接电话系统
class CallSystem
{
public:
    void Call()
    {
        std::cout << "打电话." << std::endl;
    }

    void Pick()
    {
        std::cout << "接电话." << std::endl;
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
    OnOffSystem* m_onOffSystem;   // 外部引用，不需释放
    PhotoSystem* m_photoSystem;   // 按需装载， 可以没有，功能也没有
    CallSystem* m_callSystem;
};

void FacadeTest()
{
    Phone* pFacade = new Phone;
    OnOffSystem* pOnOffSystem = new OnOffSystem;
    PhotoSystem* pPhotoSystem = new PhotoSystem;
    CallSystem* pCallSystem = new CallSystem;

    pFacade->SetOnOff(pOnOffSystem);
    //pFacade->SetPhoto(pPhotoSystem);  // 不装载此功能
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