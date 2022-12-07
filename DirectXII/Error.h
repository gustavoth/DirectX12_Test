#ifndef _ERROR_H
#define _ERROR_H

#include <windows.h>            // fun��es do windows
#include <string>               // tipo string
using std::string;              // uso de string sem std::

class Error
{
private:
    HRESULT hrCode;             // c�digo de erro do windows
    string funcName;            // nome da fun��o em que ocorreu o erro
    string fileName;            // nome do arquivo em que ocorreu o erro
    int lineNum;                // n�mero da linha do erro
    
public:
    Error();                    
    Error(HRESULT hr, const string & func, const string & file, int line);            
    string ToString() const;    
};

// O c�digo precisa ser uma macro porque o nome do arquivo, 
// linha e fun��o precisam ser capturados no local do erro 

#ifndef ThrowIfFailed
#define ThrowIfFailed(x)                                               \
{                                                                      \
    HRESULT hr = (x);                                                  \
    if(FAILED(hr)) { throw Error(hr, __func__, __FILE__, __LINE__); }  \
}
#endif

#endif