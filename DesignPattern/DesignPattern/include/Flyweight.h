/*!
*@file    Flyweight.h
*@brief   ��Ԫģʽ
*/

#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

enum GmomokuColor
{
    BLACK,
    WHITE
};

struct GmomokuPos
{
    int m_x;
    int m_y;
    GmomokuPos(int x, int y) : m_x(x), m_y(y) {}
};

// ��������
class Gomoku
{
public:
    Gomoku(GmomokuColor color) : m_color(color) {}

    ~Gomoku() {}

    void Show()
    {
        if (m_color == BLACK)
            std::cout<<"��һö����"<<std::endl;
        else
            std::cout<<"��һö����"<<std::endl;
    }

private:
    GmomokuColor m_color;
};


class GomokuFactory
{
public:
    GomokuFactory(): m_pBlackGomoku(nullptr), m_pWhiteGomoku(nullptr) {}

    ~GomokuFactory() 
    {
        if (m_pBlackGomoku)
        {
            delete m_pBlackGomoku;
            m_pBlackGomoku = nullptr;
        }

        if (m_pWhiteGomoku)
        {
            delete m_pWhiteGomoku;
            m_pWhiteGomoku = nullptr;
        }

        m_blackGomokuPoss.clear();
        m_whiteGomokuPoss.clear();
    }

    void SetGomoku(GmomokuColor color, GmomokuPos pos)
    {
        if (color == BLACK)
        {
            if (m_pBlackGomoku == nullptr)
                m_pBlackGomoku = new Gomoku(BLACK);

            m_blackGomokuPoss.push_back(pos);

            std::cout<<"��("<<pos.m_x<<','<<pos.m_y<<")��";
            m_pBlackGomoku->Show();
        }
        else
        {
            if (m_pWhiteGomoku == nullptr)
                m_pWhiteGomoku = new Gomoku(WHITE);

            m_whiteGomokuPoss.push_back(pos);

            std::cout<<"��("<<pos.m_x<<','<<pos.m_y<<")��";
            m_pWhiteGomoku->Show();
        }
    }

private:
    Gomoku* m_pBlackGomoku; // ����
    Gomoku* m_pWhiteGomoku; // ����
    std::vector<GmomokuPos> m_blackGomokuPoss;
    std::vector<GmomokuPos> m_whiteGomokuPoss;
};


void FlyweightTest()
{
    GomokuFactory* pGomokuFactory = new GomokuFactory;
    pGomokuFactory->SetGomoku(BLACK, GmomokuPos(1, 2));
    pGomokuFactory->SetGomoku(WHITE, GmomokuPos(2, 3));
    pGomokuFactory->SetGomoku(BLACK, GmomokuPos(1, 1));
    pGomokuFactory->SetGomoku(WHITE, GmomokuPos(3, 3));
    pGomokuFactory->SetGomoku(BLACK, GmomokuPos(0, 2));
    pGomokuFactory->SetGomoku(WHITE, GmomokuPos(2, 0));

    delete pGomokuFactory;
    pGomokuFactory = nullptr;
}

#endif // FLYWEIGHT_H