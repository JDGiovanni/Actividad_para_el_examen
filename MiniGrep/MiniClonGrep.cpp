#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	cout << "Ingrese la palabra a resaltar" << endl;
    
    string palabra;
    
    cin>> palabra;
    
    cout << "En que color? (1 = Azul | 2 = Verde | 3 = Cyan | 4 = Rojo | 5 = Magenta)" << endl;
  
    
    fstream archivo("archivo.txt");

 
    string palabras[] = {palabra};
	int contador_palabras = 0;

    int color;
    cin >> color;

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
		
		contador_palabras++;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
      } else {
        cout << palabra << " ";
      }
    }
    cout << endl;
    cout << endl;
    cout << "Palabras resaltadas: " << contador_palabras<< endl;
    
    return 0;
  }

