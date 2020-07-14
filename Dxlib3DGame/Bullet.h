#pragma once
#include "DxLib.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	const VECTOR GetPosition() const { return m_pos; }
	void SetPosition() const;
	void Draw();

private:

	VECTOR m_pos;				// 弾のポジション

	float m_radius;				// 弾の半径
	int m_divNum;				// 弾のポリゴンの細かさ
	
	unsigned int m_diffColorR;	// ディフューズカラー赤
	unsigned int m_diffColorG;	// ディフューズカラー緑
	unsigned int m_diffColorB;	// ディフューズカラー青

	unsigned int m_specColorR;	// スペキュラーカラー赤
	unsigned int m_specColorG;	// スペキュラーカラー緑
	unsigned int m_specColorB;	// スペキュラーカラー青

	int m_fillFlag;				// 弾を塗りつぶすかどうか
};