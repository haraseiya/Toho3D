#include "SkyBox.h"

SkyBox::SkyBox()
{
    // �X�J�C�h�[���Z�b�g�|�W�V����
    MV1SetScale(m_model, VGet(100.0f, 100.0f, 100.0f));
}

SkyBox::~SkyBox()
{
    // �v���C���[���f���̍폜
    MV1DeleteModel(m_model);
}

void SkyBox::SetPosition() const
{
    // �X�J�C�h�[���Z�b�g�|�W�V����
    MV1SetPosition(m_model, VGet(0.0f, 0.0f, 0.0f));
}

void SkyBox::Load()
{
    // �v���C���[���f���̓ǂݍ���
    m_model = MV1LoadModel("Assets/Model/SkyDome/Dome_BB602.x");
    if (m_model == -1)
    {
        printfDx("�v���C���[�̓ǂݍ��݂Ɏ��s���܂���");
    }
}

void SkyBox::Draw()
{
    // �X�J�C�h�[���̕`��
    MV1DrawModel(m_model);
}
