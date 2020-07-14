#include "Player.h"

Player::Player()
{
    // 初期位置
    m_pos = VGet(0.0f, 0.0f, 0.0f);

    // アニメーションの現在の再生時間
    m_playTime = 0.0f;

    m_attachAnimIndex = MV1AttachAnim(m_model, 0, m_anim, TRUE);
    m_totalAnimTime = MV1GetAttachAnimTotalTime(m_model, m_attachAnimIndex);
}

Player::~Player()
{
    // モデルの削除
    MV1DeleteModel(m_model);
    MV1DeleteModel(m_vehicleModel);
}

void Player::SetPosition() const
{
    // セットポジション
    MV1SetPosition(m_model, m_pos);
    MV1SetPosition(m_vehicleModel, m_pos);
}

void Player::Load()
{
    // モデルの読み込み
    m_model = MV1LoadModel("Assets/Model/ModelMarisa/Marisa.pmx");
    if (m_model == -1)
    {
        printfDx("プレイヤーの読み込みに失敗しました");
    }

    // モデルの読み込み
    m_vehicleModel = MV1LoadModel("Assets/Model/Houki.pmx");
    if (m_vehicleModel == -1)
    {
        printfDx("箒の読み込みに失敗しました");
    }

    // アニメーションの読み込み
    m_anim = MV1LoadModel("Assets/Animation/Idle.vmd");
    if (m_anim == -1)
    {
        printfDx("プレイヤーアニメーションの読み込みに失敗");
    }
}

void Player::Draw()
{
    // モデルの描画
    MV1DrawModel(m_model);
    MV1DrawModel(m_vehicleModel);
}

void Player::Update()
{
    // 操作
    if (CheckHitKey(KEY_INPUT_W)) { m_pos.y += 0.1; }
    if (CheckHitKey(KEY_INPUT_A)) { m_pos.x += 0.1; }
    if (CheckHitKey(KEY_INPUT_S)) { m_pos.y -= 0.1; }
    if (CheckHitKey(KEY_INPUT_D)) { m_pos.x -= 0.1; }

    m_playTime += 1.0f;

    if (m_playTime >= m_totalAnimTime)
    {
        m_playTime = 0.0f;
    }

    MV1SetAttachAnimTime(m_model, m_attachAnimIndex, m_playTime);
}
