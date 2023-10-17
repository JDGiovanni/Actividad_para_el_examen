#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
  // Solicitar el texto al usuario
  cout << "Ingrese el texto: ";
  string texto;
  getline(cin, texto);

  // Solicitar el carácter a buscar
  cout << "Ingrese el caracter a buscar: ";
  char caracter;
  cin >> caracter;

  // Solicitar el color del resaltado
  cout << "Ingrese el color del resaltado (0-15): ";
  int color;
  cin >> color;

  // Iterar por el texto
  for (int i = 0; i < texto.length(); i++)
  {
    // Si el carácter actual coincide con el carácter buscado
    if (texto[i] == caracter)
    {
      // Establecer el color del carácter resaltado
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole, color);

      // Imprimir el carácter resaltado
      cout << texto[i];

      // Restaurar el color del texto normal
      SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | 7);
    }
    else
    {
      cout << texto[i];
    }
  }

  return 0;
}