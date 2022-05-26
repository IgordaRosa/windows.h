#ifndef UNICODE
#define UNICODE
#endif 

#ifndef HEADER
#define HEADER 

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include "../Recursos/Resources.h"
#include <iostream>


LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
     {
     case WM_DESTROY:
         PostQuitMessage(0);
         return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

WNDCLASS EstilizarJanela(HINSTANCE hInstance)
{
    WNDCLASS window;
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WinProc;
    window.cbClsExtra = 0;
    window.cbWndExtra = 0;
    window.hInstance = hInstance;
    window.hIcon = LoadIcon(NULL, IDI_WARNING);
    window.hCursor = LoadCursor(NULL, IDC_ARROW);
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 4); //(HBRUSH)(COLOR_WINDOW + 1);
    window.lpszMenuName = NULL;
    window.lpszClassName = L"Janela";
    return window;
}

HWND CriarJanela(HINSTANCE hInstance)
{
    return CreateWindow(
    L"Janela",
    L"Programa",
    WS_POPUP,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    GetSystemMetrics(SM_CXSCREEN),
    GetSystemMetrics(SM_CYSCREEN),
    NULL,
    NULL,
    hInstance,
    NULL
    );
}

#endif 