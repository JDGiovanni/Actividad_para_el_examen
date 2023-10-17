#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);
    
    cout << "Hola mundo" << endl;
    
    SetConsoleTextAttribute(hConsole, 2);
    
    cout << "Adios mundo" << endl;
    
    SetConsoleTextAttribute(hConsole, 7);
    
    return 0;
}
