#include "Enemy.h"

Enemy::Enemy()
{
    m_pos.x = 0.0f;
    m_pos.y = 10.0f;
    m_pos.z = -50.0f;

    // 初期の向き
    m_rotate.x = 0.0f;
    m_rotate.y = 90.0f;
    m_rotate.z = 0.0f;
}

Enemy::~Enemy()
{
    // モデルの削除
    MV1DeleteModel(m_model);
}

void Enemy::SetPosition() const
{
    // セットポジション
    MV1SetPosition(m_model, m_pos);

    // 回転値をセット
    MV1SetRotationXYZ(m_model, m_rotate);
}

void Enemy::Load()
{
    // モデルの読み込み
    m_model = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (m_model == -1)
    {
        printfDx("エネミーの読み込みに失敗しました");
    }
}

void Enemy::Draw()
{
    // モデルの描画
    MV1DrawModel(m_model);
}
