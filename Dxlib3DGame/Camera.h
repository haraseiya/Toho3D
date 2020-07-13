#pragma once
#include "DxLib.h"

class Camera
{
public:
	Camera();
	~Camera();

	const VECTOR GetPosition() const { return m_pos; }
	void SetPosition() const;

	void Control();

private:
	VECTOR m_pos;
};
