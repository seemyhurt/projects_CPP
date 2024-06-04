#include <iostream>
#include <clocale>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;
///////////////////////////////////////////////////////////
const int MAX = 12;
wchar_t month[MAX][MAX] = {L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December"};

void printHead();
int day_in_month(int num);
void getwstring(wchar_t* mas);
void getnum(int& num);
///////////////////////////////////////////////////////////
class CONTACT
{
private:
	wchar_t* surname = new wchar_t[MAX];
	wchar_t* name = new wchar_t[MAX];
	long long number = 0; 
	int* date = new int[3];
public:
	// конструктор по умолчанию
	CONTACT()
	{ 
		this->get();
	}
	// конструктор с пятью аргументами
	CONTACT(wchar_t* surname, wchar_t* name, long long num, int * date) : surname(surname), name(name), number(num), date(date)
	{ }
	void display() const // вывод на экран
	{
        wstring print_name = surname;
        print_name += L" ";
		print_name += name;
        wcout << endl << left << setw(24) << print_name
			<< L"|\t" << number
			<< L"\t|\t" << date[0] << L" " <<  month[date[1] - 1] << L" " << date[2];
	}
	void get() // ввод данных пользователем
	{
        wcout << L"\n\nВведите данные нового контакта: " << endl;
        wcout << L"Фамилия: ";
        getwstring(surname);
        wcout << L"Имя: ";
        getwstring(name);
		wcin.clear();
		wcin.ignore(wcin.rdbuf()->in_avail());
        wcout << L"Номер телефона: ";
		wcin>>number;
		while (wcin.fail() || number < pow(10,10) || number > pow(10, 11))
		{
			wcin.clear(); // Очистить поток ввода
			wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
            wcout << L"Неверный формат. Введите номер телефона: ";
			wcin >> number;
		}
        wcout << L"Дата рождения ";
		input_date();

	}
	void input_date()
	{
        wcout << L"\nДень: ";
		getnum(date[0]);
        wcout << L"Месяц: ";
		getnum(date[1]);
        wcout << L"Год: ";
		getnum(date[2]);
		while (date[1] > 12 || date[0] > day_in_month(date[1]) || date[2] > 2022 || date[2] < 1900)
		{
            wcout << L"Неверный формат даты. Введите повторно";
			input_date();
		}
	}
	wchar_t* getname() { return name; }
	wchar_t* getsurname() { return surname; }

	bool issurname(wchar_t * find_sur)
	{
        if (!wcscmp(this->surname, find_sur)) return true;
		else return false;
	}
	bool isperson(wchar_t* find_sur, wchar_t* find_name )
	{
        if (!wcscmp(this->surname, find_sur) && !wcscmp(this->name, find_name)) return true;
		else return false;
	}
}; // конец класса CONTACT


///////////////////////////////////////////////////////////
struct note  // один элемент списка
{
	CONTACT * person;   // некоторые данные
	note* next; // указатель на следующую структуру
};

///////////////////////////////////////////////////////////
class NOTE // список
{
private:
	note* end;
	note* first;
public:
	NOTE()            // конструктор без параметров
	{
		first = NULL;
		end = NULL;
	}     // первого элемента пока нет
	void addfirstitem(CONTACT* contact) // добавление элемента в начало
	{
		note* newlink = new note;      // выделяем память
		newlink->person = contact;             // запоминаем данные
		newlink->next = first;         // запоминаем значение first
		first = newlink;               // first теперь указывает на новый элемент
	}
	///////////////////////////////////////////////////////////
	void addenditem(CONTACT* contact) // добавление элемента в конец
	{
		note* newlink = new note;      // выделяем память
		newlink->person = contact;             // запоминаем данные
		if (first == NULL)
		{
			first = newlink;
			newlink->next = NULL;
		}
		else
		{
			newlink->next = NULL;         // передвигаем end
			end->next = newlink;
		}
		end = newlink;               // end теперь указывает на новый элемент
	}
	///////////////////////////////////////////////////////////
	void findSurname(wchar_t* contact)
	{
		note* current = first;
		bool flag = false;
		while (current)
		{
			if (current->person->issurname(contact))
			{
				current->person->display();
				flag = true;
			}
			current = current->next;
		}
        if (!flag) wcout << L"\nКонтакты с такой фамилией не найдены" << endl;
	}
	///////////////////////////////////////////////////////////
	note* findContact(CONTACT* contact)
	{
		note* current = first;
		while (current)
		{
			if (current->person->isperson(contact->getsurname(), contact->getname())) return current;
			current = current->next;
		}
		return NULL;
	}
	///////////////////////////////////////////////////////////
	note* findContact(wchar_t* find_sur, wchar_t* find_name)
	{
		note* current = first;
		while (current)
		{
			if (current->person->isperson(find_sur, find_name))
				return current;
			current = current->next;
		}
        wcout << L"\nКонтакт не найден" << endl;
		return NULL;
	}
	///////////////////////////////////////////////////////////
	void delContact(wchar_t* find_sur, wchar_t* find_name)
	{
		note* cutCont = findContact(find_sur, find_name);
		if (cutCont == first) first = first->next;
		else
		{
			note* current = first;
			while (current->next != cutCont)
				current = current->next;
			// удаление элемента
			current->next = cutCont->next;
			if (cutCont == end) end = current;
		}
		delete cutCont;
	}
	///////////////////////////////////////////////////////////
	void display()
	{
		printHead();
		note* current = first;           // начинаем с первого элемента
		while (current)                 // пока есть данные
		{
			current->person->display();   // печатаем данные
			current = current->next;       // двигаемся к следующему элементу
		}
	}
	///////////////////////////////////////////////////////////
	void Free()
	{
		if (first == NULL) return;
		note* current = first;
		note* temp;
		while (current)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
		first = NULL;
	}
	note* getfirst() { return first; }
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
	int answer = -1;
	NOTE book;
	while (answer != 0)
	{
        wcout << endl <<
            L"1 - Добавить в конец" << endl <<
            L"2 - Вывод списка" << endl <<
            L"3 - Добавить в начало" << endl <<
            L"4 - Поиск контакта по фамилии" << endl <<
            L"5 - Удаление" << endl <<
            L"6 - Редактировать" << endl <<
            L"7 - Сохранить в файл" << endl <<
            L"0 - Выход\nВыберите действие: ";
        wcin.clear();
        wcin.ignore(wcin.rdbuf()->in_avail());
        wcin >> answer;
		while (wcin.fail() || answer < 0 || answer > 8)
		{
			wcin.clear(); // Очистить поток ввода
			wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
            wcout << L"Ошибка ввода, выберите действие: ";
			wcin >> answer;
		}
		switch (answer)
		{
		case 1:
		{
			CONTACT* contact = new CONTACT;
            if (book.findContact(contact)) wcout << L"Контакт с таким именем уже существует" << endl;
			else book.addenditem(contact);
			break;
		}
		case 2:
		{
			if (book.getfirst()) book.display();
            else wcout << L"Нет данных!" << endl;
			break;
		}
		case 3:
		{
			CONTACT* contact = new CONTACT;
            if (book.findContact(contact)) wcout << L"Контакт с таким именем уже существует" << endl;
			else book.addfirstitem(contact);
			break;
		}
		case 4:
		{
            if (!book.getfirst()) { wcout << L"Нет данных!" << endl; break; }
			wchar_t* surname = new wchar_t[MAX];
            wcout << L"\nВведите фамилию для поиска: ";
            getwstring(surname);
			book.findSurname(surname);
            wcout << L"\n\n";
			break;
		}
		case 5:
		{
            if (!book.getfirst()) { wcout << L"\nДанные отсутствуют!" << endl; break; }
			wchar_t* surname = new wchar_t[MAX];
			wchar_t* name = new wchar_t[MAX];
            wcout << L"Введите данные контакта, которого хотите удалить: " << endl;
            wcout << L"Фамилия: ";
            getwstring(surname);
            wcout << L"Имя: ";
            getwstring(name);
			book.delContact(surname, name);
			break;
		}
		}
	}
	return 0;
}
void printHead()
{
    wcout        << L"\n\n\t Имя" << right <<
        setw(13) << L"|" <<
        setw(19) << L"Номер телефона" <<
        setw(5)  << L"|" <<
        setw(21) << L"Дата рождения" << endl;
    wcout << L"-------------------------------------------------------------------------";
}
int day_in_month(int num) { return (28 + (num + (num / 8)) % 2 + 2 % num + 2 * (1 / num)); }
void getwstring(wchar_t* mas)
{
	wcin.clear();
	wcin.ignore(wcin.rdbuf()->in_avail());
	wcin.getline(mas, MAX);
	while (wcin.fail())
	{
		wcin.clear(); // Очистить поток ввода
		wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
        wcout << L"Ошибка ввода. Введите строку: ";
		wcin.getline(mas, MAX);
	}
}
void getnum(int& num)
{
	wcin.clear();
	wcin.ignore(wcin.rdbuf()->in_avail());
	wcin >> num;
	while (wcin.fail())
	{
		wcin.clear(); // Очистить поток ввода
		wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
        wcout << L"Некорректный ввод. Введите целочисленное значение: ";
		wcin >> num;
	}
}
