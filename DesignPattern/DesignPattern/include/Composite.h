/*!
*@file    Composite.h
*@brief   ���ģʽ
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

// �ļ��г�����
class FolderCompoent
{
public:
    FolderCompoent(const std::string& name) : m_name(name), m_depth(0) {}

    ~FolderCompoent() {}

    virtual void Show() = 0;
    virtual void Add(FolderCompoent* pCompoent) {}
    virtual void Remove(FolderCompoent* pCompoent) {}

    int GetDepth() {return m_depth;}
    virtual void SetDepth(int depth) {m_depth = depth;}
protected:
    std::string m_name;
    int m_depth;
};

// �ļ�
class File : public FolderCompoent
{
public:
    File(const std::string& name) : FolderCompoent(name) {}

    ~File() {}

    void Show()
    {
        for (int i = 0; i < m_depth; ++i)
            cout << "...";
        cout<< m_name<< endl;
    }
};

class Folder : public FolderCompoent
{
public:
    Folder(const std::string& name) : FolderCompoent(name) {}

    ~Folder() {}

    void Add(FolderCompoent* pCompoent)
    {
        std::vector<FolderCompoent*>::iterator iter = find(m_pCompoents.begin(), m_pCompoents.end(), pCompoent);
        if (iter == m_pCompoents.end())
        {
            pCompoent->SetDepth(GetDepth() + 1); // �������
            m_pCompoents.push_back(pCompoent);
        }
    }

    void Remove(FolderCompoent* pCompoent)
    {
        std::vector<FolderCompoent*>::iterator iter = find(m_pCompoents.begin(), m_pCompoents.end(), pCompoent);
        if (iter != m_pCompoents.end())
            m_pCompoents.erase(iter);
    }

    void SetDepth(int depth)
    {
        FolderCompoent::SetDepth(depth);
        for (size_t i = 0; i < m_pCompoents.size(); ++i)
            m_pCompoents.at(i)->SetDepth(depth + 1);
    }

    void Show()
    {
        for (int i = 0; i < m_depth; ++i)
            cout << "...";
        cout<< m_name<< endl;

        for (size_t i = 0; i < m_pCompoents.size(); ++i)
            m_pCompoents.at(i)->Show();
    }

private:
    std::vector<FolderCompoent*> m_pCompoents;
};

void CompositeTest()
{
    FolderCompoent* pFolder = new Folder("ѧϰ�ļ���");
    FolderCompoent* pFolder2 = new Folder("C++ѧϰ�ļ���");
    FolderCompoent* pFolder3 = new Folder("Javaѧϰ�ļ���");
    FolderCompoent* pFolder4 = new Folder("C++���ģʽ�ļ���");

    FolderCompoent* pFile1 = new File("ѧϰ�б�.txt");
    FolderCompoent* pFile2 = new File("ѧϰ�ƻ�.txt");
    FolderCompoent* pFile3 = new File("C++ Primerѧϰ����.ppt");
    FolderCompoent* pFile4 = new File("Effective C++.pdf");
    FolderCompoent* pFile5 = new File("Java����.pdf");
    FolderCompoent* pFile6 = new File("����ģʽ.cpp");
    FolderCompoent* pFile7 = new File("�Ž�ģʽ.cpp");
    FolderCompoent* pFile8 = new File("���ģʽ.cpp");

     std::cout<<"---��������ļ�---"<<std::endl;
    // ����������˳�� ����depth��ά��
    pFolder->Add(pFolder2);
    pFolder2->Add(pFile3);
    pFolder2->Add(pFile4);

    pFolder4->Add(pFile6);
    pFolder4->Add(pFile7);
    pFolder4->Add(pFile8);

    pFolder2->Add(pFolder4);

    pFolder3->Add(pFile5);

    pFolder->Add(pFile1);
    pFolder->Add(pFile2);
    pFolder->Add(pFolder3);

    pFolder->Show();

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"---����ɾ���ļ�---"<<std::endl;
    

    // ����ɾ���ļ�
    pFolder2->Remove(pFolder4);
    pFolder->Remove(pFile2);
    pFolder->Show();

    delete pFile8;
    delete pFile7;
    delete pFile6;
    delete pFile5;
    delete pFile4;
    delete pFile3;
    delete pFile2;
    delete pFile1;
    delete pFolder4;
    delete pFolder3;
    delete pFolder2;
    delete pFolder;
}

#endif // COMPOSITE_H