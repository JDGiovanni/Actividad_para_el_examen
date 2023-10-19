#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {

  fstream archivo("archivo.txt");
  
  cout << "¿Que palabras desea imprimir?" << endl;
  string palabra1;
  cin >> palabra1;
  
  string palabras[] = {palabra1};


  cout << "En que color? (0 = Negro | 1 = Azul | 2 = Verde | 3 = Cian | 4 = Rojo | 5 = Magenta)" << endl;
  int color;
  cout << endl;
  cin >> color;

  // Inicializamos el índice del arreglo en 0
  int i = 0;

  while (!archivo.eof()) {

    string palabra;
    archivo >> palabra;


    bool encontrada = false;
    for (int j = 0; j < sizeof(palabras) / sizeof(palabras[0]); j++) {
      if (palabra == palabras[j]) {
        encontrada = true;
        break;
      }
    }

    if (encontrada) {

      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

      cout << palabra << " ";

      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
    } else {
    	
      cout << palabra << " ";
      
    }
  }

  return 0;
}
