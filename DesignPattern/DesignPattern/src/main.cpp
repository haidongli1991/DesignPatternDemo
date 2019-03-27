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

#define BeginTest(c) cout <<"--------"<< c <<"开始: --------"<< endl;
#define EndTest(c) {cout <<"--------"<< c <<"结束! --------"<< endl;cout<<endl;cout<<endl;}

void TestSimpleFactory()
{
    BeginTest("简单工厂模式");
    simplefactory::SimpleFactoryTest();
    EndTest("简单工厂模式");
}

void TestFactoryMethod()
{
    BeginTest("工厂方法模式");
    factorymethod::FactoryMethodTest();
    EndTest("工厂方法模式");
}

void TestAbstractFactory()
{
    BeginTest("抽象工厂模式");
    abstractfactory::AbstractFactoryTest();
    EndTest("抽象工厂模式");
}

// 单例模式测试
void TestSingleton()
{
    BeginTest("单例模式");
    SingletonTest();
    EndTest("单例模式");
}

void TestBuilder()
{
    BeginTest("建造者模式");
    BuilderTest();
    EndTest("建造者模式");
}

void TestPrototype()
{
    BeginTest("原型模式");
    PrototypeTest();
    EndTest("原型模式");
}

void TestAdapter()
{
    BeginTest("适配器模式");
    AdapterTest();
    EndTest("适配器模式");
}

void TestDecorator()
{
    BeginTest("装饰器模式");
    DecoratorTest();
    EndTest("装饰器模式");
}

void TestProxy()
{
    BeginTest("代理模式");
    ProxyTest();
    EndTest("代理模式");
}

void TestFacade()
{
    BeginTest("外观模式");
    FacadeTest();
    EndTest("外观模式");
}

void TestBridge()
{
    BeginTest("桥接模式");
    BridgeTest();
    EndTest("桥接模式");
}

void TestComposite()
{
    BeginTest("组合模式");
    CompositeTest();
    EndTest("组合模式");
}

void TestFlyweight()
{
    BeginTest("享元模式");
    FlyweightTest();
    EndTest("享元模式");
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