#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	~Player();

	const VECTOR GetPosition() const { return m_pos; }
	void SetPosition() const;

	void Load();
	void Draw();
	void Update();

private:
	int m_model;
	VECTOR m_pos;
};