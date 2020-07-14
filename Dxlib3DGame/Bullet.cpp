#include "Bullet.h"

Bullet::Bullet()
{
	m_pos = VGet(0.0f, 10.0f, 10.0f);

	m_radius = 5.0f;
	m_divNum = 32;

	m_diffColorR = 255;
	m_diffColorG = 0;
	m_diffColorB = 0;

	m_specColorR = 255;
	m_specColorG = 0;
	m_specColorB = 0;

	m_fillFlag = TRUE;
}

Bullet::~Bullet()
{

}

void Bullet::SetPosition() const
{

}

void Bullet::Draw()
{
	DrawSphere3D(m_pos, m_radius, m_divNum, GetColor(m_diffColorR, m_diffColorG, m_diffColorB),
		GetColor(m_specColorR, m_specColorG, m_specColorB), m_fillFlag);
}
