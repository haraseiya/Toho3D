#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Bullet.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウモードにする
    ChangeWindowMode(TRUE);

    // 画面の解像度指定
    SetGraphMode(1024, 768, 32);

    // ＤＸライブラリの初期化
    if (DxLib_Init() == -1)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    // 描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    // インスタンス生成
    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Camera* camera = new Camera();
    SkyBox* skybox = new SkyBox();
    Bullet* bullet = new Bullet();

    // モデルロード
    player->Load();
    enemy->Load();
    skybox->Load();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // プレイヤー処理
        player->SetPosition();
        player->Draw();
        player->Update();

        // エネミー処理
        enemy->SetPosition();
        enemy->Draw();

        // スカイボックス処理
        skybox->SetPosition();
        skybox->Draw();

        // カメラ処理
        camera->Update(*player);

        // 弾の描画
        bullet->Draw();

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // 解放処理
    delete player;
    delete enemy;
    delete skybox;
    delete camera;

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}