#include "CScene.h"

int main(int, char**){
    
    CScene * Scene;
    Scene = new CScene();

    Scene->Init();
    Scene->Run();

    delete Scene;
    Scene = NULL;
}
