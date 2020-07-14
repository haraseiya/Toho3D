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
	int m_vehicleModel;
	int m_anim;
	int m_attachAnimIndex;
	float m_totalAnimTime;
	float m_playTime;

	VECTOR m_pos;
};