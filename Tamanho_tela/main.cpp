#include "headers/header.hpp"

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
    int resp = MessageBox(NULL, L"Vamos calcular o tamanho da tela?" , L"Janelinha", MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION);
    
    if(resp == IDYES)
    {
        int cxScreen = GetSystemMetrics(SM_CXSCREEN);
        int cyScreen = GetSystemMetrics(SM_CYSCREEN);

        stringstream text;

        text << cxScreen << " x " << cyScreen;
        std::cout << text.str().c_str() << std:: endl;

        MessageBox(NULL,
        LPCWSTR(text.str().c_str()),
        L"tamanho da tela",
        MB_OK | MB_ICONINFORMATION);

    }
    else
    {
        MessageBox(NULL,
        L"Um Jogo deve conhecer o tamanho da tela!",
        L"Mensagem",
        MB_OK | MB_ICONWARNING);
        
    }   

    return 0;
}