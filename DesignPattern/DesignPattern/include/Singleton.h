/*!
*@file    Singleton.h
*@brief   ����ģʽ
*/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    //get ����
    static Singleton * getInstance(){
        if (NULL == instance) {
            //lock();  C++11���� vs2010��֧��
            //�жϵ�����
            if (NULL == instance) {
                instance = new Singleton();
            }
            //unlock();
        }
        //����һ��ʵ�����Ķ���
        return instance;
    }
    //c++ Ƕ�׵��ڲ��࣬������ɾ�����������Garbage������ΪSingleton��˽����Ƕ�࣬�Է����౻�������ط����á�
    class Garbage
    {
    public:
        ~Garbage(){
            if (Singleton::instance != NULL) {
                cout << "�������Ψһʵ����������" << endl;
                delete Singleton::instance;
            }
        }
    };

private:
    //�������ж���һ�������ľ�̬��Ա������������Ψһ��������������������ɾ���������ʵ�������ó����ڽ���ʱ����ȫ�ֱ��������ԣ�ѡ�����յ��ͷ�ʱ����
    static Garbage garbage;
    //����һ����̬��ʵ��
    static Singleton *instance;
    //�������˽�й��캯��
    Singleton(){
        cout << "�����˵�����Ĺ��캯��" << endl;
    }
    //�������˽����������
    ~Singleton(){
        cout << "�����˵��������������" << endl;
    }
    //�ѿ������캯������Ϊ˽�У��Ϳ��Խ�ֹ���˿�������Ҳ����ʵ����������˽�м���
    Singleton(const Singleton &copy);
    //�Ѹ�ֵ���������Ϊ˽�еģ���ֹ����֮��ĸ�ֵ����
    Singleton & operator=(const Singleton &other);
};
//��ʼ���ڲ�������ľ�̬������Ŀ��������ɾ���������������������ʼ�����Ͳ��ᱻ����
//�ڲ�����Է����ⲿ���˽�г�Ա���ⲿ�಻�ܷ����ڲ����˽�г�Ա��
Singleton::Garbage Singleton::garbage;
//��ʼ��instanceΪ null
Singleton * Singleton::instance = NULL;


void SingletonTest()
{
    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();
    Singleton *c = Singleton::getInstance();

    if (a == b) {
        cout << "a = b" << endl;
    }
}

#endif // SINGLETON_H
