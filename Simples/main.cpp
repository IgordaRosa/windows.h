#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <iostream>

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    const wchar_t mensagem[] = L"Ola Windows";
    MessageBox(NULL, mensagem , L"Janelinha", 0);
    return 0;
}