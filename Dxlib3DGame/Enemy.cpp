#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
    // プレイヤーモデルの削除
    MV1DeleteModel(m_model);
}

void Enemy::SetPosition() const
{
    // プレイヤーセットポジション
    MV1SetPosition(m_model, VGet(10.0f, 0.0f, 0.0f));
}

void Enemy::Load()
{
    // プレイヤーモデルの読み込み
    m_model = MV1LoadModel("Assets/ModelReimu/Reimu.pmx");
    if (m_model == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }
}

void Enemy::Draw()
{
    // プレイヤーモデルの描画
    MV1DrawModel(m_model);
}
