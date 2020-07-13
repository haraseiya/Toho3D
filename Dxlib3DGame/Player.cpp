#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
    // プレイヤーモデルの削除
    MV1DeleteModel(m_model);
}

void Player::SetPosition() const
{
    // プレイヤーセットポジション
    MV1SetPosition(m_model, VGet(0.0f, 0.0f, 0.0f));
}

void Player::Load()
{
    // プレイヤーモデルの読み込み
    m_model = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (m_model == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }
}

void Player::Draw()
{
    // プレイヤーモデルの描画
    MV1DrawModel(m_model);
}
