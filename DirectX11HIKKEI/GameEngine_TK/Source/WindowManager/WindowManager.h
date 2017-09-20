//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   WindowManager.h
//!
//! @brief  ウィンドウのヘッダファイル
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
	//コンストラクタ
	WindowManager() {}
	//デストラクタ
	~WindowManager() {}
	//初期化
	HRESULT WindowManager::Initialize(HINSTANCE,
		INT iX, INT iY, INT iWidth, INT iHeight, LPCWSTR WindowName);
	//ウィンドウプロシージャー
	static LRESULT CALLBACK MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	//HWNDのgetter
	HWND GethWnd() { return m_hWnd; };
private:
	HWND m_hWnd;
};