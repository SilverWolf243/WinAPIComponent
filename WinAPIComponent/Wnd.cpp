#include "pch.h"
#include "Wnd.h"

Wnd::Wnd(HINSTANCE hInstance, const wchar_t className, const wchar_t titleName, int spawnX, int spawnY, int width, int height)
    : _hInstance(hInstance), _spawnX(spawnX), _spawnY(spawnY), _width(width), _height(height)
{
}

Wnd::~Wnd()
{
}

bool Wnd::Init()
{
    return false;
}

int Wnd::GetMessageDispatch()
{
    return 0;
}
