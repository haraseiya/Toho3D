#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "SkyBox.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウモードにする
    ChangeWindowMode(TRUE);

    // 画面の解像度指定
    SetGraphMode(1024, 768, 32);

    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    // 描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Camera* camera = new Camera();
    SkyBox* skybox = new SkyBox();

    player->Load();
    enemy->Load();
    skybox->Load();
    camera->Control();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // プレイヤー処理
        player->SetPosition();
        player->Draw();

        // エネミー処理
        enemy->SetPosition();
        enemy->Draw();

        // スカイボックス処理
        skybox->SetPosition();
        skybox->Draw();

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    delete player;
    delete enemy;
    delete skybox;
    delete camera;

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}