#include "headers/header.hpp" 

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    MSG msg;    

    WNDCLASS window = EstilizarJanela(hInstance);

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