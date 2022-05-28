#include "header.h" 

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) 
{
    MSG msg;    

    HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

    WNDCLASS window = EstilizarJanela(hInstance, hIcon);

    if(!RegisterClass(&window))
    {
        MessageBox(NULL, L"Erro na criacao da janela!", L"Erro", MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CriarJanela(hInstance);

    RECT winRect = {0,0,1280, 720};
    AdjustWindowRectEx(&winRect, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL, GetWindowExStyle(hwnd));

    MoveWindow(
        hwnd,
        GetSystemMetrics(SM_CXSCREEN) /2 -
        ((winRect.right - winRect.left) /2),
        GetSystemMetrics(SM_CYSCREEN) /2 -
        ((winRect.bottom - winRect.top) /2),
        winRect.right - winRect.left,
        winRect.bottom - winRect.top,
        TRUE
    );

    ShowWindow(hwnd, nCmdShow);

    UpdateWindow(hwnd);
    

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}