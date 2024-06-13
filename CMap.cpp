#include "CMap.h"
#include"CMapBuilder.h"
CMap::CMap()
{
}

CMap::~CMap()
{
}

void CMap::Init(int mapNum)
{
    switch (mapNum)
    {
    case 1:
        Map1Builder=new CMapBuilder;
        Map1Builder->BuildMap1(this);
        break;
    
    default:
        break;
    }
}