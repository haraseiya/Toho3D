#include "SkyBox.h"

SkyBox::SkyBox()
{
    // スカイドームセットポジション
    MV1SetScale(m_model, VGet(100.0f, 100.0f, 100.0f));
}

SkyBox::~SkyBox()
{
    // プレイヤーモデルの削除
    MV1DeleteModel(m_model);
}

void SkyBox::SetPosition() const
{
    // スカイドームセットポジション
    MV1SetPosition(m_model, VGet(0.0f, 0.0f, 0.0f));
}

void SkyBox::Load()
{
    // プレイヤーモデルの読み込み
    m_model = MV1LoadModel("Assets/Model/SkyDome/Dome_BB602.x");
    if (m_model == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }
}

void SkyBox::Draw()
{
    // スカイドームの描画
    MV1DrawModel(m_model);
}
