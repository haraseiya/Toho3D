#include "Enemy.h"

Enemy::Enemy()
{
    m_pos.x = 0.0f;
    m_pos.y = 10.0f;
    m_pos.z = -50.0f;

    // �����̌���
    m_rotate.x = 0.0f;
    m_rotate.y = 90.0f;
    m_rotate.z = 0.0f;
}

Enemy::~Enemy()
{
    // ���f���̍폜
    MV1DeleteModel(m_model);
}

void Enemy::SetPosition() const
{
    // �Z�b�g�|�W�V����
    MV1SetPosition(m_model, m_pos);

    // ��]�l���Z�b�g
    MV1SetRotationXYZ(m_model, m_rotate);
}

void Enemy::Load()
{
    // ���f���̓ǂݍ���
    m_model = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (m_model == -1)
    {
        printfDx("�G�l�~�[�̓ǂݍ��݂Ɏ��s���܂���");
    }
}

void Enemy::Draw()
{
    // ���f���̕`��
    MV1DrawModel(m_model);
}
