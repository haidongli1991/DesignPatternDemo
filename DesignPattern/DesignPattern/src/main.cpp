#include "SimpleFactory.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "Singleton.h"
#include "Builder.h"
#include "Prototype.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Proxy.h"
#include "Facade.h"
#include "Bridge.h"
#include "Composite.h"
#include "Flyweight.h"

using namespace std;

#define BeginTest(c) cout <<"--------"<< c <<"��ʼ: --------"<< endl;
#define EndTest(c) {cout <<"--------"<< c <<"����! --------"<< endl;cout<<endl;cout<<endl;}

void TestSimpleFactory()
{
    BeginTest("�򵥹���ģʽ");
    simplefactory::SimpleFactoryTest();
    EndTest("�򵥹���ģʽ");
}

void TestFactoryMethod()
{
    BeginTest("��������ģʽ");
    factorymethod::FactoryMethodTest();
    EndTest("��������ģʽ");
}

void TestAbstractFactory()
{
    BeginTest("���󹤳�ģʽ");
    abstractfactory::AbstractFactoryTest();
    EndTest("���󹤳�ģʽ");
}

// ����ģʽ����
void TestSingleton()
{
    BeginTest("����ģʽ");
    SingletonTest();
    EndTest("����ģʽ");
}

void TestBuilder()
{
    BeginTest("������ģʽ");
    BuilderTest();
    EndTest("������ģʽ");
}

void TestPrototype()
{
    BeginTest("ԭ��ģʽ");
    PrototypeTest();
    EndTest("ԭ��ģʽ");
}

void TestAdapter()
{
    BeginTest("������ģʽ");
    AdapterTest();
    EndTest("������ģʽ");
}

void TestDecorator()
{
    BeginTest("װ����ģʽ");
    DecoratorTest();
    EndTest("װ����ģʽ");
}

void TestProxy()
{
    BeginTest("����ģʽ");
    ProxyTest();
    EndTest("����ģʽ");
}

void TestFacade()
{
    BeginTest("���ģʽ");
    FacadeTest();
    EndTest("���ģʽ");
}

void TestBridge()
{
    BeginTest("�Ž�ģʽ");
    BridgeTest();
    EndTest("�Ž�ģʽ");
}

void TestComposite()
{
    BeginTest("���ģʽ");
    CompositeTest();
    EndTest("���ģʽ");
}

void TestFlyweight()
{
    BeginTest("��Ԫģʽ");
    FlyweightTest();
    EndTest("��Ԫģʽ");
}

int main(int argc, char** argv)
{
    TestSimpleFactory();
    TestFactoryMethod();
    TestAbstractFactory();
    TestSingleton();
    TestBuilder();
    TestPrototype();
    TestAdapter();
    TestDecorator();
    TestProxy();
    TestFacade();
    TestBridge();
    TestComposite();
    TestFlyweight();

    return 0;
}