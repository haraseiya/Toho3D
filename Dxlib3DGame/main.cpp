#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int modelHandle;

    VECTOR cameraPos;

    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    ChangeWindowMode(TRUE);

    // �J�����̍��W��������
    cameraPos.x = 5.0f;
    cameraPos.y = 20.0f;
    cameraPos.z = -10.0f;

    SetCameraNearFar(1.0f, 150.0f);
    SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0.0f,10.0f,0.0f));

    // �R�c���f���̓ǂݍ���
    modelHandle = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (modelHandle == -1)
    {
        printfDx("���f���̓ǂݍ��݂Ɏ��s���܂���");
    }


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ��ʂ��N���A
        ClearDrawScreen();

        // ��ʂɉf��ʒu�ɂR�c���f�����ړ�
        MV1SetPosition(modelHandle, VGet(0.0f, 0.0f, 0.0f));

        // �R�c���f���̕`��
        MV1DrawModel(modelHandle);

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // ���f���n���h���̍폜
    MV1DeleteModel(modelHandle);

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}