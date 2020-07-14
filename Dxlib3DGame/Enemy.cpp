#include "Enemy.h"

Enemy::Enemy()
{
    // 初期位置
    m_pos = VGet(0.0f, 10.0f, -50.0f);

    // 初期の向き
    m_rotate = VGet(0.0f, 90.0f, 0.0f);
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
