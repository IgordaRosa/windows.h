#ifndef UNICODE
#define UNICODE 
#endif 

#ifndef HEADER
#define HEADER 

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Windowsx.h>
#include "resource.h"
#include <iostream>
#include "Resources/icon.h"

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
     {
     case WM_CREATE:
        
        return 0;
     case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

WNDCLASS EstilizarJanela(HINSTANCE hInstance, HICON hIcon)
{
    WNDCLASS window;
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WindowProcedure;
    window.cbClsExtra = 0;
    window.cbWndExtra = 0;
    window.hInstance = hInstance;
    window.hIcon   =   hIcon;
    window.hCursor =   LoadCursor(NULL, IDC_ARROW);
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); //(HBRUSH)(COLOR_WINDOW + 1);
    window.lpszMenuName = NULL;
    window.lpszClassName = L"Janela";

    return window;
}

HWND CriarJanela(HINSTANCE hInstance)
{
    return CreateWindow(
    L"Janela",
    L"Programa",
    WS_OVERLAPPED | WS_SYSMENU,
    GetSystemMetrics(SM_CXSCREEN) /2 - 960/2,
    GetSystemMetrics(SM_CYSCREEN) /2 - 540/2,
    960,
    540,
    NULL,
    NULL,
    hInstance,
    NULL
    );
}

#endif 