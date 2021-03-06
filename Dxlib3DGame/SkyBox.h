#pragma once
#include "DxLib.h"

class SkyBox
{
public:
	SkyBox();
	~SkyBox();

	const int GetPosition() const { return m_pos; }
	void SetPosition() const;

	void Load();
	void Draw();

private:
	int m_model;
	int m_pos;
};