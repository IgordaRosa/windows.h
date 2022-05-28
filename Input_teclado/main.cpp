#include "headers/header.hpp"  

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    MSG mssg;    

    WNDCLASS window = EstilizarJanela(hInstance);

    if(!RegisterClass(&window))
    {
        MessageBox(NULL, L"Erro na criacao da janela!", L"Erro", MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CriarJanela(hInstance);

    ShowWindow(hwnd, nCmdShow);

    UpdateWindow(hwnd);
    

    while(GetMessage(&mssg, NULL, 0, 0))
    {
        TranslateMessage(&mssg);
        DispatchMessage(&mssg);
    }
    
    return mssg.wParam;
}