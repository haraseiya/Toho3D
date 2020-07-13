#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int playerModel;
    int enemyModel;
    int skydomeModel;

    VECTOR cameraPos;

    // �E�B���h�E���[�h�ɂ���
    ChangeWindowMode(TRUE);

    // ��ʂ̉𑜓x�w��
    SetGraphMode(1024, 768, 32);

    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    // �J�����̍��W��������
    cameraPos.x = 5.0f;
    cameraPos.y = 20.0f;
    cameraPos.z = -30.0f;

    SetCameraNearFar(1.0f, 150.0f);
    SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0.0f,10.0f,0.0f));

    // �v���C���[���f���̓ǂݍ���
    playerModel = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (playerModel == -1)
    {
        printfDx("�v���C���[�̓ǂݍ��݂Ɏ��s���܂���");
    }

    // �G�l�~�[���f���̓ǂݍ���
    enemyModel = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (enemyModel == -1)
    {
        printfDx("�G�l�~�[�̓ǂݍ��݂Ɏ��s���܂���");
    }

    // �X�J�C�h�[�����f���̓ǂݍ���
    skydomeModel = MV1LoadModel("Assets/SkyDome/Dome_BB602.x");
    if (skydomeModel == -1)
    {
        printfDx("�X�J�C�h�[���̓ǂݍ��݂Ɏ��s���܂���");
    }

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ��ʂ��N���A
        ClearDrawScreen();

        // �v���C���[�Z�b�g�|�W�V����
        MV1SetPosition(playerModel, VGet(0.0f, 0.0f, 0.0f));

        // �v���C���[���f���̕`��
        MV1DrawModel(playerModel);

        // �G�l�~�[�Z�b�g�|�W�V����
        MV1SetPosition(enemyModel, VGet(10.0f, 0.0f, 0.0f));

        // �G�l�~�[���f���̕`��
        MV1DrawModel(enemyModel);

        // �X�J�C�h�[���Z�b�g�|�W�V����
        MV1SetPosition(skydomeModel, VGet(0.0f, 0.0f, 0.0f));

        // �X�J�C�h�[���Z�b�g�|�W�V����
        MV1SetScale(skydomeModel, VGet(1.0f, 1.0f, 1.0f));

        // �X�J�C�h�[���̕`��
        MV1DrawModel(skydomeModel);

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // �v���C���[���f���̍폜
    MV1DeleteModel(playerModel);

    // �G�l�~�[���f���̍폜
    MV1DeleteModel(enemyModel);

    // �G�l�~�[���f���̍폜
    MV1DeleteModel(enemyModel);

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}