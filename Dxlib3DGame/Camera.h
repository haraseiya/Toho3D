#pragma once
#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();
	~Camera();

	const VECTOR GetPosition() const { return m_pos; }
	void SetPosition() const;

	void Update(Player& player);

private:
	VECTOR m_pos;
	VECTOR m_lookAtPos;
};
