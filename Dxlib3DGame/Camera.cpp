#include "Camera.h"

Camera::Camera()
{
    // ƒJƒƒ‰‚ÌÀ•W‚ğ‰Šú‰»
    m_pos.x = 5.0f;
    m_pos.y = 20.0f;
    m_pos.z = -30.0f;
}

Camera::~Camera()
{

}

void Camera::SetPosition() const
{

}


void Camera::Control()
{
    SetCameraNearFar(1.0f, 150.0f);
    SetCameraPositionAndTarget_UpVecY(m_pos, VGet(0.0f, 10.0f, 0.0f));
}
