#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Bullet.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �E�B���h�E���[�h�ɂ���
    ChangeWindowMode(TRUE);

    // ��ʂ̉𑜓x�w��
    SetGraphMode(1024, 768, 32);

    // �c�w���C�u�����̏�����
    if (DxLib_Init() == -1)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    // �C���X�^���X����
    Player* player = new Player();
    Enemy* enemy = new Enemy();
    Camera* camera = new Camera();
    SkyBox* skybox = new SkyBox();
    Bullet* bullet = new Bullet();

    // ���f�����[�h
    player->Load();
    enemy->Load();
    skybox->Load();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ��ʂ��N���A
        ClearDrawScreen();

        // �v���C���[����
        player->SetPosition();
        player->Draw();
        player->Update();

        // �G�l�~�[����
        enemy->SetPosition();
        enemy->Draw();

        // �X�J�C�{�b�N�X����
        skybox->SetPosition();
        skybox->Draw();

        // �J��������
        camera->Update(*player);

        // �e�̕`��
        bullet->Draw();

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // �������
    delete player;
    delete enemy;
    delete skybox;
    delete camera;

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}