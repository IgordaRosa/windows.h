#ifndef UNICODE
#define UNICODE
#endif 

#ifndef HEADER
#define HEADER 

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    switch(message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rect);
        //DrawText(hdc, L"Janelinhaaa!!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        //ou TextOut(hdc, X, Y, "texto", -1);
        EndPaint(hwnd, &ps);
        return 0;
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
    window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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