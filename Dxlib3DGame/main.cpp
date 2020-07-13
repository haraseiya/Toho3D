#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int playerModel;
    int enemyModel;

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

    // �v���C���[���f���̓ǂݍ���
    playerModel = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (playerModel == -1)
    {
        printfDx("���f���̓ǂݍ��݂Ɏ��s���܂���");
    }

    // �G�l�~�[���f���̓ǂݍ���
    enemyModel = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (playerModel == -1)
    {
        printfDx("���f���̓ǂݍ��݂Ɏ��s���܂���");
    }

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ��ʂ��N���A
        ClearDrawScreen();

        // ��ʂɉf��ʒu�Ƀv���C���[���f�����ړ�
        MV1SetPosition(playerModel, VGet(0.0f, 0.0f, 0.0f));

        // �v���C���[���f���̕`��
        MV1DrawModel(playerModel);

        // ��ʂɉf��ʒu�ɃG�l�~�[���f�����ړ�
        MV1SetPosition(enemyModel, VGet(5.0f, 0.0f, 0.0f));

        // �G�l�~�[���f���̕`��
        MV1DrawModel(enemyModel);

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // �v���C���[���f���̍폜
    MV1DeleteModel(playerModel);

    // �G�l�~�[���f���̍폜
    MV1DeleteModel(enemyModel);

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}