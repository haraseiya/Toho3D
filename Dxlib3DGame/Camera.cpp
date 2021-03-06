#include "Camera.h"
#include "Player.h"

Camera::Camera()
{
    //カメラの描画距離
    SetCameraNearFar(1.0f, 10000.0f);

    // カメラの座標を初期化
    m_pos.x = 0.0f;
    m_pos.y = 20.0f;
    m_pos.z = 40.0f;
}

Camera::~Camera()
{

}

void Camera::SetPosition() const
{

}

void Camera::Update(Player& player)
{
    m_lookAtPos = player.GetPosition();
    SetCameraPositionAndTarget_UpVecY(m_pos, m_lookAtPos);
}

