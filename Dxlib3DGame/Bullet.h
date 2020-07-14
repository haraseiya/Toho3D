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

	VECTOR m_pos;				// �e�̃|�W�V����

	float m_radius;				// �e�̔��a
	int m_divNum;				// �e�̃|���S���ׂ̍���
	
	unsigned int m_diffColorR;	// �f�B�t���[�Y�J���[��
	unsigned int m_diffColorG;	// �f�B�t���[�Y�J���[��
	unsigned int m_diffColorB;	// �f�B�t���[�Y�J���[��

	unsigned int m_specColorR;	// �X�y�L�����[�J���[��
	unsigned int m_specColorG;	// �X�y�L�����[�J���[��
	unsigned int m_specColorB;	// �X�y�L�����[�J���[��

	int m_fillFlag;				// �e��h��Ԃ����ǂ���
};