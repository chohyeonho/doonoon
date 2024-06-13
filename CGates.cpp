#include "CGates.h"
#include"CScene.h"
CGates::CGates()
{
    tick=respawn=GATECOOLTIME;
    isWarp=false;
    y=x=0;
}

CGates::~CGates()
{
}

void CGates::Update(CScene *Scene)
{
    tick++;
    if(tick>=respawn)
    {
        tick=0;
        
        if(!isWarp)
        {
            Refresh(Scene);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        int a,b;
        a=gates[i].first;
        b=gates[i].second;
        Scene->SetMapW(a,b,7,i);
    }
    Scene->SetMapW(1,1,isWarp+1);
}

void CGates::Refresh(CScene *Scene)
{
    for (int i = 0; i < 2; i++)
    {
        int a,b;
        a=1+rand()%21;
        b=1+rand()%21;
        while (Scene->GetMapW(a,b)!=1)
        {
            a=1+rand()%21;
            b=1+rand()%21;
        }
        gates[i]={a,b};
    }
}

pair<pair<int,int>, int> CGates::Collision(CScene * Scene,int num,int dir)
{
    int w,d;
    isWarp=true;
    y=gates[1-num].first;
    x=gates[1-num].second;
    switch (dir)
    {
    case KEY_UP:
        if(!isWall(Scene->GetMapW(y-1,x)))
        {
            y=y-1;
            d=KEY_UP;
        }
        else if(!isWall(Scene->GetMapW(y,x+1)))
        {
            x=x+1;
            d=KEY_RIGHT;
        }
        else if(!isWall(Scene->GetMapW(y,x-1)))
        {
            x=x-1;
            d=KEY_LEFT;
        }
        else if(!isWall(Scene->GetMapW(y+1,x)))
        {
            y=y+1;
            d=KEY_DOWN;
        }
        else
        {
            Scene->SetDie(true);
        }
        break;
    case KEY_DOWN:
        if(!isWall(Scene->GetMapW(y+1,x)))
        {
            y=y+1;
            d=KEY_DOWN;
        }
        else if(!isWall(Scene->GetMapW(y,x-1)))
        {
            x=x-1;
            d=KEY_LEFT;
        }
        else if(!isWall(Scene->GetMapW(y,x+1)))
        {
            x=x+1;
            d=KEY_RIGHT;
        }
        else if(!isWall(Scene->GetMapW(y-1,x)))
        {
            y=y-1;
            d=KEY_UP;
        }
        else
        {
            Scene->SetDie(true);
        }
        break;
    case KEY_LEFT:
        if(!isWall(Scene->GetMapW(y,x-1)))
        {
            x=x-1;
            d=KEY_LEFT;
        }
        else if(!isWall(Scene->GetMapW(y-1,x)))
        {
            y=y-1;
            d=KEY_UP;
        }
        else if(!isWall(Scene->GetMapW(y+1,x)))
        {
            y=y+1;
            d=KEY_DOWN;
        }
        else if(!isWall(Scene->GetMapW(y,x+1)))
        {
            x=x+1;
            d=KEY_RIGHT;
        }
        else
        {
            Scene->SetDie(true);
        }
        break;
    case KEY_RIGHT:
        if(!isWall(Scene->GetMapW(y,x+1)))
        {
            x=x+1;
            d=KEY_RIGHT;
        }
        else if(!isWall(Scene->GetMapW(y+1,x)))
        {
            y=y+1;
            d=KEY_DOWN;
        }
        else if(!isWall(Scene->GetMapW(y-1,x)))
        {
            y=y-1;
            d=KEY_UP;
        }
        else if(!isWall(Scene->GetMapW(y,x-1)))
        {
            x=x-1;
            d=KEY_LEFT;
        }
        else
        {
            Scene->SetDie(true);
        }
        break;
    
    default:
        break;
    }
    return {{y,x},d};
}

bool CGates::isWall(int w)
{
    if(w==-1||w==1||w==2||w==7)
    {
        return true;
    }
    return false;
}

void CGates::SetWarp(bool isWarp)
{
    this->isWarp=isWarp;
}
