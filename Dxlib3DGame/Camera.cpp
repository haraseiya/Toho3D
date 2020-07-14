#include "Camera.h"
#include "Player.h"

Camera::Camera()
{
    //ƒJƒƒ‰‚Ì•`‰æ‹——£
    SetCameraNearFar(1.0f, 10000.0f);

    // ƒJƒƒ‰‚ÌÀ•W‚ğ‰Šú‰»
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

