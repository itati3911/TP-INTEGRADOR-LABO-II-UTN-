#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std;

int main() {

	SetConsoleOutputCP(CP_UTF8);

	Menu menu;

	menu.MostrarEntrada();

	system("pause");
  
  return 0;
}