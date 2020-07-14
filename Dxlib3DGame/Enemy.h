#pragma once
#include "DxLib.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	const VECTOR GetPosition() const { return m_pos; }
	void SetPosition() const;

	void Load();
	void Draw();

private:
	int m_model;
	VECTOR m_pos;
	VECTOR m_rotate;
};
