#include "Enemy.h"

Enemy::Enemy()
{
    // �����ʒu
    m_pos = VGet(0.0f, 10.0f, -50.0f);

    // �����̌���
    m_rotate = VGet(0.0f, 90.0f, 0.0f);
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
