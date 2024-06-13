#include "CScene.h"
#include "CSnake.h"
#include "CMap.h"
#include "CItems.h"
#include"CGates.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::Run()
{
    snakey=snakex=10;
    this->Init();
    

    
    while(1){
        this->Update();
        clear();
        if(youDie)
        {
            break;
        }
        this->Render();
        input=ERR;
        int ch;
        while((ch=getch())!=ERR)
        {
            input = ch;
        }
        usleep(TICKTIME);
    }
    endwin();
}

void CScene::Init()
{
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr,TRUE);
    keypad(stdscr, TRUE);

    srand(time(NULL));

    
    youDie=false;
    Snake=new CSnake(snakey,snakex);
    Items=new CItems(GROW_MAKE,POISON_MAKE);
    Gates=new CGates();
    CurrentMap=new CMap();
    CurrentMap->Init(1);
}


void CScene::Update()
{
    MapUpdate();

    Items->Update(this);

    Gates->Update(this);

    Snake->Update(this,input);



}

void CScene::Render()
{
    for (int i = 1; i <= 21; i++)
    {
        for (int j = 1; j <= 21; j++)
        {
            if (map[i][j][0]==0)
            {
                mvprintw(i,j*2,".");
            }
            else
            {
                mvprintw(i,j*2,to_string(map[i][j][0]).c_str());
            }
            
        }
    }
}

void CScene::MapUpdate()
{
    for (int i = 0; i <= 22; i++)
    {
        for (int j = 0; j <= 22; j++)
        {
            map[i][j][0]=CurrentMap->map[i][j];
        }
    }
}

void CScene::SetDie(bool isDie)
{
    youDie=isDie;
}

int CScene::GetMapW(int y, int x)
{
    return map[y][x][0];
}

void CScene::SetMapW(int y, int x, int w)
{
    map[y][x][0]=w;
}

void CScene::SetMapW(int y, int x, int w, int w2)
{
    map[y][x][0]=w;
    map[y][x][1]=w2;
}

void CScene::ItemCollision(int y, int x)
{
    switch (map[y][x][0])
    {
    case 5:
        Items->Collision(map[y][x][1],0);
        break;
    case 6:
        Items->Collision(map[y][x][1],1);
        break;
    default:
        break;
    }
}

void CScene::GateCollision(int y, int x,int dir)
{
    pair<pair<int,int>,int> a=Gates->Collision(this,map[y][x][1],dir);
    Snake->SetPos(a.first.first,a.first.second);
    Snake->SetDir(a.second);
}

void CScene::GateOn()
{
    Gates->SetWarp(true);
}

void CScene::GateOff()
{
    Gates->SetWarp(false);
}
