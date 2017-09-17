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
	WindowManager() {// m_pWM = nullptr; 
					 //m_pWM = &WindowManager::GetInstance();
	}
	~WindowManager() {}
	//windowManagerの生成
	static WindowManager& GetInstance();
	//
	//static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	//初期化
	HRESULT WindowManager::Initialize(HINSTANCE hInstance,
		INT iX, INT iY, INT iWidth, INT iHeight, LPCWSTR WindowName)
	{
		// ウィンドウの定義
		WNDCLASSEX  wc;
		ZeroMemory(&wc, sizeof(wc));
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = MsgProc;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		wc.lpszClassName = WindowName;
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		RegisterClassEx(&wc);
		//ウィンドウの作成
		m_hWnd = CreateWindow(WindowName, WindowName, WS_OVERLAPPEDWINDOW,
			0, 0, iWidth, iHeight, 0, 0, hInstance, 0);
		if (!m_hWnd)
		{
			return E_FAIL;
		}
		//ウインドウの表示
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);

		return S_OK;
	}
	//
	static LRESULT CALLBACK MsgProc(HWND, UINT, WPARAM, LPARAM);
	HWND GethWnd() { return m_hWnd; };
private:
	static std::unique_ptr<WindowManager> winManager;
	HWND m_hWnd;
	//WindowManager* m_pWM;
};