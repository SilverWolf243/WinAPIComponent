#include "pch.h"
#include "ChildrenWnd.h"

ChildrenWnd::ChildrenWnd(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height)
    : Wnd(hInstance, className, titleName, spawnX, spawnY, width, height)
{
}

ChildrenWnd::~ChildrenWnd()
{
}

bool ChildrenWnd::Init()
{
    return false;
}

int ChildrenWnd::GetMessageDispatch()
{
    return 0;
}
