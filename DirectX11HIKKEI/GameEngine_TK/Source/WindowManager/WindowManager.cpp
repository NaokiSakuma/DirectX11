//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   WindowManager.cpp
//!
//! @brief  ウィンドウのソースファイル
//!
//! @date   2017/09/15
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#include "WindowManager.h"

std::unique_ptr<WindowManager> WindowManager::winManager = nullptr;
//LRESULT WindowManager::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	return (hWnd, uMsg, wParam, lParam);
//}

//----------------------------------------------------------------------
//! @brief windowMangerの生成
//!
//! @param[in] なし
//!
//! @return windowManager
//----------------------------------------------------------------------
WindowManager & WindowManager::GetInstance()
{
	//Singleton
	if (!winManager)
		winManager.reset(new WindowManager());
	return *winManager;
}

////----------------------------------------------------------------------
////! @brief 初期化
////!
////! @param[in] windowの設定
////!
////! @return 成功したか
////----------------------------------------------------------------------
//HRESULT WindowManager::Initialize(HINSTANCE hInstance,
//	INT iX, INT iY, INT iWidth, INT iHeight, LPCWSTR WindowName)
//{
//	// ウィンドウの定義
//	WNDCLASSEX  wc;
//	ZeroMemory(&wc, sizeof(wc));
//	wc.cbSize = sizeof(wc);
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.lpfnWndProc = WndProc;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
//	wc.lpszClassName = WindowName;
//	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	RegisterClassEx(&wc);
//	//ウィンドウの作成
//	m_hWnd = CreateWindow(WindowName, WindowName, WS_OVERLAPPEDWINDOW,
//		0, 0, iWidth, iHeight, 0, 0, hInstance, 0);
//	if (!m_hWnd)
//	{
//		return E_FAIL;
//	}
//	//ウインドウの表示
//	ShowWindow(m_hWnd, SW_SHOW);
//	UpdateWindow(m_hWnd);
//
//	return S_OK;
//}

LRESULT WindowManager::MsgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_KEYDOWN:
		switch ((char)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

