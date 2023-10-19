#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {

    string palabra;
  
    fstream archivo("archivo.txt");

    string palabras[] = {palabra};

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

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | FOREGROUND_INTENSITY);
      } else {
        cout << palabra << " ";
      }
    }
    return 0;
  }

