#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
    // �v���C���[���f���̍폜
    MV1DeleteModel(m_model);
}

void Enemy::SetPosition() const
{
    // �v���C���[�Z�b�g�|�W�V����
    MV1SetPosition(m_model, VGet(10.0f, 0.0f, 0.0f));
}

void Enemy::Load()
{
    // �v���C���[���f���̓ǂݍ���
    m_model = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (m_model == -1)
    {
        printfDx("�v���C���[�̓ǂݍ��݂Ɏ��s���܂���");
    }
}

void Enemy::Draw()
{
    // �v���C���[���f���̕`��
    MV1DrawModel(m_model);
}
