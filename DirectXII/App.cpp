#include "App.h"
#include "Engine.h"


// Inicializa��o de membros est�ticos da classe
Graphics* & App::graphics  = Engine::graphics;       // componente gr�fico 
Window*   & App::window    = Engine::window;         // janela da aplica��o
Input*    & App::input     = Engine::input;          // dispositivos de entrada
double    & App::frameTime = Engine::frameTime;      // tempo do �ltimo quadro

App::App()
{
}

App::~App()
{
}