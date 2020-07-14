#include "Player.h"

Player::Player()
{
    // 初期位置
    m_pos.x = 0.0f;
    m_pos.y = 0.0f;
    m_pos.z = 0.0f;
}

Player::~Player()
{
    // モデルの削除
    MV1DeleteModel(m_model);
}

void Player::SetPosition() const
{
    // セットポジション
    MV1SetPosition(m_model, m_pos);
}

void Player::Load()
{
    // モデルの読み込み
    m_model = MV1LoadModel("Assets/ModelMarisa/Marisa.pmx");
    if (m_model == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }
}

void Player::Draw()
{
    // モデルの描画
    MV1DrawModel(m_model);
}

void Player::Update()
{
    // 操作
    if (CheckHitKey(KEY_INPUT_W)) { m_pos.y += 0.1; }
    if (CheckHitKey(KEY_INPUT_A)) { m_pos.x += 0.1; }
    if (CheckHitKey(KEY_INPUT_S)) { m_pos.y -= 0.1; }
    if (CheckHitKey(KEY_INPUT_D)) { m_pos.x -= 0.1; }
}
