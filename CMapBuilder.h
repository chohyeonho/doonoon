#pragma once
#include"Game.h"
class CMap;
class CMapBuilder
{
private:

public:
    CMapBuilder(/* args */);
    ~CMapBuilder();
    void Garo(CMap * t,int y,int start,int end,int w);
    void Sero(CMap * t,int x,int start,int end,int w);
    void BuildMap1(CMap * t);
};