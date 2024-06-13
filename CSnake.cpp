#include "CSnake.h"
#include "CScene.h"
CSnake::CSnake()
{
}

CSnake::CSnake(int yy, int xx)
{
    lastInput=KEY_LEFT;
    this->y=yy;
    this->x=xx;
    body.push_back({y,x});
    body.push_back({y,x+1});
    body.push_back({y,x+2});
}

CSnake::~CSnake()
{
}

void CSnake::Update(CScene *Scene, int input)
{
    //이전 입력과 반대로 이동하면 죽는다
    if
    (
        (input==KEY_UP&&lastInput==KEY_DOWN)||
        (input==KEY_DOWN&&lastInput==KEY_UP)||
        (input==KEY_LEFT&&lastInput==KEY_RIGHT)||
        (input==KEY_RIGHT&&lastInput==KEY_LEFT)
    )
    {
        //죽는다
        Scene->SetDie(true);
        return;
    }
    if(input==KEY_UP||input==KEY_DOWN||input==KEY_LEFT||input==KEY_RIGHT)
    {
        lastInput=input;
    }

    switch (lastInput)
    {
    case KEY_UP:
        --y;
        break;
    case KEY_DOWN:
        ++y;
        break;
    case KEY_LEFT:
        --x;
        break;
    case KEY_RIGHT:
        ++x;
        break;
    default:
        break;
    }
    currentMapW=Scene->GetMapW(y,x);
    if(currentMapW==1)
    {
        // 벽에 부딪히면 죽는다
        Scene->SetDie(true);
        return;
    }
    GoSnake(Scene);
}

void CSnake::GoSnake(CScene *Scene)
{
    switch (currentMapW)
    {
    case 0:
        break;

    case 5:
        body.push_back({1,1});
        Scene->Collision(y,x);
        break;
    case 6:
        body.pop_back();
        //Scene->Collision(y,x);
        if(body.size()<MIN_SNAKEBODY)
        {
            Scene->SetDie(true);
        }
        break;
    default:
        break;
    }
    for (int i = body.size()-1; i > 0; i--)
    {
        body[i].first=body[i-1].first;
        body[i].second=body[i-1].second;
        Scene->SetMapW(body[i].first,body[i].second,4);
    }
    body[0]={y,x};
    Scene->SetMapW(body[0].first,body[0].second,3);
    Scene->SetMapW(1,4,body.size());
}
