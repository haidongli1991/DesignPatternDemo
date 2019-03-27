/*!
*@file    Composite.h
*@brief   组合模式
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

// 文件夹抽象类
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

// 文件
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
            pCompoent->SetDepth(GetDepth() + 1); // 更新深度
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
    FolderCompoent* pFolder = new Folder("学习文件夹");
    FolderCompoent* pFolder2 = new Folder("C++学习文件夹");
    FolderCompoent* pFolder3 = new Folder("Java学习文件夹");
    FolderCompoent* pFolder4 = new Folder("C++设计模式文件夹");

    FolderCompoent* pFile1 = new File("学习列表.txt");
    FolderCompoent* pFile2 = new File("学习计划.txt");
    FolderCompoent* pFile3 = new File("C++ Primer学习分享.ppt");
    FolderCompoent* pFile4 = new File("Effective C++.pdf");
    FolderCompoent* pFile5 = new File("Java基础.pdf");
    FolderCompoent* pFile6 = new File("工厂模式.cpp");
    FolderCompoent* pFile7 = new File("桥接模式.cpp");
    FolderCompoent* pFile8 = new File("组合模式.cpp");

     std::cout<<"---测试添加文件---"<<std::endl;
    // 故意打乱添加顺序， 测试depth的维护
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
    std::cout<<"---测试删除文件---"<<std::endl;
    

    // 测试删除文件
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