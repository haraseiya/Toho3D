#include "Player.h"

Player::Player()
{
    // �����ʒu
    m_pos.x = 0.0f;
    m_pos.y = 0.0f;
    m_pos.z = 0.0f;
}

Player::~Player()
{
    // ���f���̍폜
    MV1DeleteModel(m_model);
}

void Player::SetPosition() const
{
    // �Z�b�g�|�W�V����
    MV1SetPosition(m_model, m_pos);
}

void Player::Load()
{
    // ���f���̓ǂݍ���
    m_model = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (m_model == -1)
    {
        printfDx("�v���C���[�̓ǂݍ��݂Ɏ��s���܂���");
    }
}

void Player::Draw()
{
    // ���f���̕`��
    MV1DrawModel(m_model);
}

void Player::Update()
{
    // ����
    if (CheckHitKey(KEY_INPUT_W)) { m_pos.y += 0.1; }
    if (CheckHitKey(KEY_INPUT_A)) { m_pos.x += 0.1; }
    if (CheckHitKey(KEY_INPUT_S)) { m_pos.y -= 0.1; }
    if (CheckHitKey(KEY_INPUT_D)) { m_pos.x -= 0.1; }
}
