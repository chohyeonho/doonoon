#include "CMapBuilder.h"
#include"CMap.h"
CMapBuilder::CMapBuilder()
{
}

CMapBuilder::~CMapBuilder()
{
}

void CMapBuilder::Garo(CMap * t,int y, int start, int end, int w)
{
    for (int i = start; i <= end; i++)
    {
        t->map[y][i]=w;
    }
    
}

void CMapBuilder::Sero(CMap * t,int x, int start, int end,int w)
{
    for (int i = start; i <= end; i++)
    {
        t->map[i][x]=w;
    }
}

void CMapBuilder::BuildMap1(CMap * t)
{
    //맵 밖을 -1로 설정
    Garo(t,0,0,22,1);
    Garo(t,22,0,22,-1);
    Sero(t,0,0,22,-1);
    Sero(t,22,0,22,-1);
    //테두리 벽
    Garo(t,1,2,20,1);
    Garo(t,21,2,20,1);
    Sero(t,1,2,20,1);
    Sero(t,21,2,20,1);
    //꼭짓점 벽
    t->map[1][1]=2;
    t->map[1][21]=2;
    t->map[21][1]=2;
    t->map[21][21]=2;
}