#include "headers/header.hpp" 

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    MSG msg;    

    WNDCLASS window;
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc = WinProc;
    window.cbClsExtra = 0;
    window.cbWndExtra = 0;
    window.hInstance = hInstance;
    window.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
    window.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR));
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 4); //(HBRUSH)(COLOR_WINDOW + 1);
    window.lpszMenuName = NULL;
    window.lpszClassName = L"Janela";

    if(!RegisterClass(&window))
    {
        MessageBox(NULL, L"Erro na criacao da janela!", L"Erro", MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CriarJanela(hInstance);

    ShowWindow(hwnd, nCmdShow);

    UpdateWindow(hwnd);
    

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}