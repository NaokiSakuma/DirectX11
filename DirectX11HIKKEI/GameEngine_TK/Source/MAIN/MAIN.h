//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MAIN.h
//!
//! @brief  ���C���̃w�b�_�t�@�C��
//!
//! @date   2017/09/15
//!
//! @author N.Sakuma
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

//�w�b�_�[�t�@�C���̃C���N���[�h
#include <d3d11.h>
#include <d3dx10.h>
#include <d3dx11.h>
#include <d3dCompiler.h>
#include "..\WindowManager\WindowManager.h"

//�K�v�ȃ��C�u�����t�@�C���̃��[�h
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3dx10.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"d3dCompiler.lib")
//�x����\��
#pragma warning(disable : 4305)
//�萔��`
#define WINDOW_WIDTH 640 //�E�B���h�E��
#define WINDOW_HEIGHT 480 //�E�B���h�E����
#define APP_NAME L"�X�v���C�g 2D�X�N���[����� �w�i�F�𔲂�"
//�}�N��
#define SAFE_RELEASE(x) if(x){x->Release(); x=NULL;}
#define ALIGN16 _declspec(align(16))
//���_�̍\����
struct SimpleVertex
{
	D3DXVECTOR3 Pos; //�ʒu
	D3DXVECTOR2 UV; //�e�N�X�`���[���W
};
//Simple�V�F�[�_�[�p�̃R���X�^���g�o�b�t�@�[�̃A�v�����\���� �������V�F�[�_�[���̃R���X�^���g�o�b�t�@�[�ƈ�v���Ă���K�v����
struct SIMPLESHADER_CONSTANT_BUFFER
{
	ALIGN16 D3DXMATRIX mW;			//���[���h���W
	ALIGN16 float ViewPortWidth;	//window�̕�
	ALIGN16 float ViewPortHeight;	//window�̍���
};
//
//class MAIN
//MAIN�N���X
class MAIN
{
public:
	//�R���X�g���N�^
	MAIN();
	//�f�X�g���N�^
	~MAIN();

	//HRESULT InitWindow(HINSTANCE, INT, INT, INT, INT, LPCWSTR);
	//LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	HRESULT InitD3D(HWND);
	HRESULT InitModel();
	HRESULT MakeShader(LPSTR, LPSTR, LPSTR, void**, ID3DBlob**);
	void Loop();
	void App();
	void Render();
	void DestroyD3D();

	//HWND m_hWnd;
	ID3D11Device* m_pDevice;
	ID3D11DeviceContext* m_pDeviceContext;
	IDXGISwapChain* m_pSwapChain;
	ID3D11RenderTargetView* m_pBackBuffer_TexRTV;
	ID3D11DepthStencilView* m_pBackBuffer_DSTexDSV;
	ID3D11Texture2D* m_pBackBuffer_DSTex;
	ID3D11InputLayout* m_pVertexLayout;
	ID3D11VertexShader* m_pVertexShader;
	ID3D11PixelShader* m_pPixelShader;
	ID3D11Buffer* m_pConstantBuffer;
	ID3D11Buffer* m_pVertexBuffer;

	ID3D11SamplerState* m_pSampler;//�e�N�X�`���[�̃T���v���[
	ID3D11ShaderResourceView* m_pTexture;//�e�N�X�`���[�i�p�ӂ���̂̓��\�[�X�r���[�����ł����j
	ID3D11BlendState* m_pBlendState;


	HWND m_testWnd;
};
