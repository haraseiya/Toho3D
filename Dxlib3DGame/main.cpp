#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int playerModel;
    int enemyModel;
    int skydomeModel;

    VECTOR cameraPos;

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

    // カメラの座標を初期化
    cameraPos.x = 5.0f;
    cameraPos.y = 20.0f;
    cameraPos.z = -30.0f;

    SetCameraNearFar(1.0f, 150.0f);
    SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0.0f,10.0f,0.0f));

    // プレイヤーモデルの読み込み
    playerModel = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (playerModel == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }

    // エネミーモデルの読み込み
    enemyModel = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (enemyModel == -1)
    {
        printfDx("エネミーの読み込みに失敗しました");
    }

    // スカイドームモデルの読み込み
    skydomeModel = MV1LoadModel("Assets/SkyDome/Dome_BB602.x");
    if (skydomeModel == -1)
    {
        printfDx("スカイドームの読み込みに失敗しました");
    }

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // プレイヤーセットポジション
        MV1SetPosition(playerModel, VGet(0.0f, 0.0f, 0.0f));

        // プレイヤーモデルの描画
        MV1DrawModel(playerModel);

        // エネミーセットポジション
        MV1SetPosition(enemyModel, VGet(10.0f, 0.0f, 0.0f));

        // エネミーモデルの描画
        MV1DrawModel(enemyModel);

        // スカイドームセットポジション
        MV1SetPosition(skydomeModel, VGet(0.0f, 0.0f, 0.0f));

        // スカイドームセットポジション
        MV1SetScale(skydomeModel, VGet(1.0f, 1.0f, 1.0f));

        // スカイドームの描画
        MV1DrawModel(skydomeModel);

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // プレイヤーモデルの削除
    MV1DeleteModel(playerModel);

    // エネミーモデルの削除
    MV1DeleteModel(enemyModel);

    // エネミーモデルの削除
    MV1DeleteModel(enemyModel);

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}