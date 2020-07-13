#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
    // �v���C���[���f���̍폜
    MV1DeleteModel(m_model);
}

void Player::SetPosition() const
{
    // �v���C���[�Z�b�g�|�W�V����
    MV1SetPosition(m_model, VGet(0.0f, 0.0f, 0.0f));
}

void Player::Load()
{
    // �v���C���[���f���̓ǂݍ���
    m_model = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (m_model == -1)
    {
        printfDx("�v���C���[�̓ǂݍ��݂Ɏ��s���܂���");
    }
}

void Player::Draw()
{
    // �v���C���[���f���̕`��
    MV1DrawModel(m_model);
}
