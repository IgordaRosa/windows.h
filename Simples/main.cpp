#ifndef UNICODE
#define UNICODE
#endif 

#include <stdio.h>
#include <windows.h>
//#include <iostream>

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    const wchar_t mensagem[] = L"OlaWindows";
    MessageBox(NULL, mensagem , L"Janelinha", 0);
    return 0;
}