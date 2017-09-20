//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   WindowManager.h
//!
//! @brief  �E�B���h�E�̃w�b�_�t�@�C��
//!
//! @date   2017/09/15
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include <memory>
#include <Windows.h>
class WindowManager
{
private:
public:
	//�R���X�g���N�^
	WindowManager() {}
	//�f�X�g���N�^
	~WindowManager() {}
	//������
	HRESULT WindowManager::Initialize(HINSTANCE,
		INT iX, INT iY, INT iWidth, INT iHeight, LPCWSTR WindowName);
	//�E�B���h�E�v���V�[�W���[
	static LRESULT CALLBACK MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	//HWND��getter
	HWND GethWnd() { return m_hWnd; };
private:
	HWND m_hWnd;
};