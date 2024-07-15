#pragma once
#include "Wnd.h"
class __declspec(dllexport) ChildrenWnd : public Wnd
{
public:
	ChildrenWnd(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height);
	virtual ~ChildrenWnd();

	virtual bool Init();
	int GetMessageDispatch();
	virtual LRESULT MessageProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) abstract;
};

