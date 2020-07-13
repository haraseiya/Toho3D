#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int modelHandle;

    VECTOR cameraPos;

    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    // 描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    ChangeWindowMode(TRUE);

    // カメラの座標を初期化
    cameraPos.x = 5.0f;
    cameraPos.y = 20.0f;
    cameraPos.z = -10.0f;

    SetCameraNearFar(1.0f, 150.0f);
    SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0.0f,10.0f,0.0f));

    // ３Ｄモデルの読み込み
    modelHandle = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (modelHandle == -1)
    {
        printfDx("モデルの読み込みに失敗しました");
    }


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // 画面に映る位置に３Ｄモデルを移動
        MV1SetPosition(modelHandle, VGet(0.0f, 0.0f, 0.0f));

        // ３Ｄモデルの描画
        MV1DrawModel(modelHandle);

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // モデルハンドルの削除
    MV1DeleteModel(modelHandle);

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}