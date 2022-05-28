#ifndef UNICODE
#define UNICODE
#endif 

#ifndef HEADER
#define HEADER 

#define WIN32_LEAN_AND_MEAN
#include <windows.h> 
#include <windowsx.h>
#include <iostream>

int WinX = 1280;
int WinY = 720;
bool fullscreen = false;

//const unsigned MaxInput = 64;
//char msg[MaxInput] = {0};
bool vkKeys[256] = {0};

bool focus = true;

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch (message)
    {
    case WM_KILLFOCUS:
        //strcpy(msg,"até mais!!");
        focus = false;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
    case WM_SETFOCUS:
        //strcpy(msg, "bem vindo!!");
        focus = true;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_KEYDOWN:
        vkKeys[wParam] = true;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_KEYUP:
        vkKeys[wParam] = false;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);

        if(vkKeys[VK_UP])
            DrawText(hdc, L"UP", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if(vkKeys[VK_DOWN])
            DrawText(hdc, L"DOWN", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if(vkKeys[VK_LEFT])
            DrawText(hdc, L"LEFT", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if(vkKeys[VK_RIGHT])
            DrawText(hdc, L"RIGHT", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if(vkKeys[VK_SPACE])
            DrawText(hdc, L"SPACE", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        rect.bottom -=100;
        if(focus)
            DrawText(hdc, L"Bem vindo!!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        else
            DrawText(hdc, L"Ate mais!!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
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
    window.hIcon = LoadIcon(NULL, IDI_WARNING);
    window.hCursor = LoadCursor(NULL, IDC_ARROW);
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2); //(HBRUSH)(COLOR_WINDOW + 1);
    window.lpszMenuName = NULL;
    window.lpszClassName = L"Janela";
    return window;
}

HWND CriarJanela(HINSTANCE hInstance)
{
    if(fullscreen)
    {
    return CreateWindowEx(
    NULL,
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
    else
    {
    return CreateWindowEx(
    NULL,
    L"Janela",
    L"Programa",
    WS_OVERLAPPED | WS_SYSMENU,
    GetSystemMetrics(SM_CXSCREEN) /2 - WinX/2,
    GetSystemMetrics(SM_CYSCREEN) /2 - WinY/2,
    WinX,
    WinY,
    NULL,
    NULL,
    hInstance,
    NULL
    );
    }
}

#endif 