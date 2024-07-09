#include "pch.h"
#include "Wnd.h"

Wnd::Wnd(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height)
    : _hInstance(hInstance), _spawnX(spawnX), _spawnY(spawnY), _width(width), _height(height), _hwnd(0)
{
    ::memcpy(_className, className, sizeof(wchar_t) * wcslen(className));
    ::memcpy(_titleName, titleName, sizeof(wchar_t) * wcslen(titleName));
}

Wnd::~Wnd()
{
}

bool Wnd::Init()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof(LONG_PTR); // ���� ����
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _className;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		int errorCode = GetLastError();
		return false;
	}

	_hwnd = CreateWindow(
		_className,
		_titleName,
		WS_OVERLAPPEDWINDOW,
		_spawnX, _spawnY,
		_width, _height,
		NULL,
		NULL,
		_hInstance,
		this 
	);

	if (!_hwnd)
	{
		int errorCode = GetLastError();
		return false;
	}

	return true;
}

int Wnd::GetMessageDispatch()
{
	ShowWindow(_hwnd, 10);
	UpdateWindow(_hwnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT Wnd::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Wnd* wnd = nullptr;

	if (message == WM_NCCREATE)
	{
		LPCREATESTRUCT pCS = (LPCREATESTRUCT)lParam;
		SetLastError(0);
		wnd = reinterpret_cast<Wnd*>(pCS->lpCreateParams);

		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)wnd))
		{
			if (GetLastError() != 0) return E_FAIL;
		}
	}
	else
	{
		wnd = reinterpret_cast<Wnd*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	if (wnd)
		return wnd->MessageProc(hWnd, message, wParam, lParam);

	return DefWindowProc(hWnd, message, wParam, lParam);
}
