#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {

    // Declaramos una variable para almacenar la palabra
    string palabra;
    // Declaramos un archivo txt
    fstream archivo("archivo.txt");

    // Declaramos un arreglo de palabras
    string palabras[] = {palabra};

    // Declaramos una variable para almacenar el color
    int color;
    cin >> color;

    // Inicializamos el índice del arreglo en 0
    int i = 0;

    while (!archivo.eof()) {

      // Leemos una palabra del archivo
      string palabra;
      archivo >> palabra;

      // Buscamos la palabra en el arreglo
      bool encontrada = false;
      for (int j = 0; j < sizeof(palabras) / sizeof(palabras[0]); j++) {
        if (palabra == palabras[j]) {
          encontrada = true;
          break;
        }
      }

      // Si la palabra se encontró, la resaltamos
      if (encontrada) {

        // Establecemos el color del texto
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

        // Imprimimos la palabra
        cout << palabra << " ";

        // Restablecemos el color del texto
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
      } else {
        cout << palabra << " ";
      }
    }
    return 0;
  }

