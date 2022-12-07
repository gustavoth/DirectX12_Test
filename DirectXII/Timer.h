#ifndef _TIMER_H
#define _TIMER_H

#include <windows.h>                          // acesso ao contador de alta precis�o do Windows
#include "Types.h"                            // tipos espec�ficos do motor

class Timer
{
private:
    static LARGE_INTEGER freq;                // frequ�ncia do contador
    LARGE_INTEGER start, end;                 // valores de in�cio e fim do contador
    bool stoped;                              // estado da contagem
    
public:
    Timer();                                  // construtor

    void   Start();                           // inicia/retoma contagem do tempo
    void   Stop();                            // p�ra contagem do tempo
    double Reset();                           // reinicia contagem e retorna tempo transcorrido
    double Elapsed();                         // retorna tempo transcorrido em segundos    
    bool   Elapsed(double secs);              // verifica se transcorreu "secs" segundos

    llong  Stamp();                           // retorna valor atual do contador
    double Elapsed(llong stamp);              // retorna tempo transcorrido desde a marca
    bool   Elapsed(llong stamp, double secs); // testa se transcorreu o tempo desde a marca
}; 

inline bool Timer::Elapsed(double secs)
{ return (Elapsed() >= secs ? true : false); }

inline bool Timer::Elapsed(llong stamp, double secs)
{ return (Elapsed(stamp) >= secs ? true : false); }

#endif