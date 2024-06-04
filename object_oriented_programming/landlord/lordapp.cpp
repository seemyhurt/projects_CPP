// lordApp.cpp
// файл, поставляемый клиенту.
#include "landlord.h"
#include "clocale"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	userInterface theUserInterface;
	theUserInterface.interact();
	return 0;
}
