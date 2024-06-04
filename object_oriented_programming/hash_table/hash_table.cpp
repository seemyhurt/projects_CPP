//Вариант 1
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <ctime>
#include <clocale>
#include <cmath>
#include <Windows.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int MAX = 1500;								//максимальный размер таблицы
const wchar_t * TypeOfKey = L"dddsdd";			//тип ключа
void getnum(int& num);								//пользовательский ввод целочисленного значения
void getwstring(wchar_t mas[], int size);				//пользовательский ввод строки
bool compare(wchar_t  a[], wchar_t b[]);				//сравнение двух массивов
void copy_val(wchar_t  a[], wchar_t b[], int n);		//копировать один массив в другой
int random(int a, int b);								//сгенерировать случайное число из диапазона
void GenerateKey(wchar_t TKey[]);				//сгенерировать случайный ключ
bool CheckCorrectKey(wchar_t TKey[]);			//проверка корректности введенного ключа
void GenerateValue(wchar_t Tvalue[]);			//сгенерировать случайное значение
int good_hash(wchar_t key[]);							//удачная хеш-функция
int bad_hash(wchar_t key[]);								//неудачная хеш-функция
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//элемент хеш-таблицы
struct hash_item
{
	wchar_t key[7];			//ключ
	wchar_t value[20];	//значение
};
//элемент связного списка, который хранит элементы после коллизии
struct note
{
	hash_item item;   // элемент
	note* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// класс линейного списка
class NOTE
{
private:
	note* end; //указатель на начальный элемент
	note* first; //указатель на конечный элемент
public:
	// конструктор
	NOTE(hash_item insert_item)
	{
		addfirstitem(insert_item);
	}
	~NOTE()
	{}
	// добавление элемента в начало списка
	void addfirstitem(hash_item insert_item)
	{
		note* newlink = new note;			// выделяем память
		newlink->item = insert_item;		// запоминаем данные
		if (first == NULL)						//если добавляем первый элемент
		{
			newlink->next = NULL;
			end = newlink;
		}
		else if (end == first)				//если добавляем второй элемент
		{
			newlink->next = first;			// перезаписываем first
			first->next = NULL;
		}
		else
			newlink->next = first;			
		first = newlink;						 // first теперь указывает на новый элемент
	}
	// добавление элемента в конец списка
	void addenditem(hash_item insert_item)
	{
		note* newlink = new note;		// выделяем память
		newlink->item = insert_item;		// запоминаем данные
		//если нет первого элемента - создаем первый
		if (first == NULL)
		{
			newlink->next = NULL;
			first = newlink;
		}
		else if (end == first)					//если добавляем второй элемент
		{
			newlink->next = NULL;         // перезаписываем end
			first->next = newlink;
		}
		else
		{
			newlink->next = NULL;         // смещаем end
			end->next = newlink;
		}
		end = newlink;
	}
	//очистка списка
	void Free()
	{
		if (first == NULL) return;
		//перебираем список начиная с первого элемента
		note* current = first;
		note* temp;
		while (current)
		{
			//запоминаем значение и переходим к следующему элементу
			temp = current;
			current = current->next;
			//очищаем значение
			delete temp;
		}
		//сбрасываем указатели на начало и конец списка
		first = NULL;
		end = NULL;
	}
	//удаление объекта списка
	note* delObj(note* cut_item)
	{
		if (cut_item == first)
		{
			first = first->next;
		}
		else
		{
			note* current = first;
			//используем дополнительный указатель на предшествующий объект
			//путем прохождения всего списка до нужного объекта
			while (current->next != cut_item)
				current = current->next;
			// удаление элемента
			current->next = cut_item->next;
			// если удаляемый объект последний в списке
			// обновляем значение указателя на последний объект
			if (cut_item == end) end = current;
		}
		// очищаем память
		delete cut_item;
		return first;
	}
	//получение первого элемента списка
	note* getfirst() { return first; }
}; //конец класса NOTE
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//класс хеш-таблицы
class HashTable
{
private:
	int size;							//количество сегментов
	NOTE* link_list[MAX]; //массив указателей к связным спискам
public:
	//конструктор
	HashTable(int SIZE_TABLE)
	{
		size = SIZE_TABLE;
		create_overflow_buckets();
	}
	// создать ячейки переполнения; массив связных списков
	void create_overflow_buckets() 
	{
		for (int i = 0; i < size; i++)
			link_list[i] = NULL;
	}
	//создать элемент таблицы ключ/значение
	hash_item create_item(wchar_t key[], wchar_t value[])
	{                 
		hash_item item;
		//копируем значения
		copy_val(key, item.key, 7);
		copy_val(value, item.value, 20);
		return item;
	}
	// очистить таблицу
	void free_table()
	{
		for (int i = 0; i < size; i++)
		{
			if (link_list[i] != NULL)
			{
				link_list[i]->Free();		//очистить список
				link_list[i] = NULL;	//обнулить указатели
				delete link_list[i];
			}
		}
	}
	//вставить элемент в таблицу
	void ht_insert(wchar_t key[], wchar_t value[])
	{
		// Создаем элемент
		hash_item add_item = create_item(key, value);
		// Вычисляем ключ
		int index =good_hash(key);
		// Ключ не занят
		if (link_list[index] == NULL)
		{
			link_list[index] = new NOTE(add_item);
		}
		else if (link_list[index]!= NULL)
		{
			note* current_item = link_list[index]->getfirst();
			//Сценарий 1: только обновить значение
			while (current_item)
			{
				if (compare(key, current_item->item.key))
				{
					copy_val(value, current_item->item.value, 20);
					return;
				}
				current_item = current_item->next;
			}
			// Сценарий 2: коллизия
			link_list[index]->addenditem(add_item);
			return;
		}
	}
	// Выполняет поиск ключа в хэш-таблице и возвращает значение
	const wchar_t* ht_search(wchar_t key[])
	{
		int index = good_hash(key);
		NOTE* head = link_list[index];
		if (head != NULL) 
		{
			note* current = head->getfirst();
			while (current)
				{
					if (compare(key, current->item.key)) return current->item.value;
					else current = current->next;
				}
		}
		return NULL;
	}
	// Выполняет поиск ключа в хэш-таблице и возвращает указатель на элемент
	note* search(wchar_t key[])
	{
		int index = good_hash(key);
		NOTE* head = link_list[index];
		if (head != NULL)
		{
			note* current = head->getfirst();
			while (current)
			{
				if (compare(key, current->item.key)) return current;
				else current = current->next;
			}
		}
		return NULL;
	}
	//удалить элемент по ключу
	void del_key(wchar_t key[])
	{
		int index = good_hash(key);
		NOTE* head = link_list[index];
		note* del_key = search(key);
		if (del_key == NULL) wcout << L"Ключ " << key << L" не найден" << endl;
		else 
		{
			if (head->delObj(del_key) == NULL) link_list[index] = NULL;
			wcout << L"Ключ удален" << endl;
		}
	}
	//удалить элементы по индексу
	void del_key(int index)
	{
		NOTE* head = link_list[index];
		if (head == NULL)
		{
			wcout << L"Не найдены элементы по данному индексу" << endl;
			return;
		}
		note* current;
		if (head != NULL)
		{
			current = head->getfirst();
			wcout << L"Удалены следующие пары ключ/значение:" << endl;
			while (current)
			{
				wcout << L"Ключ:" << current->item.key << L"\tЗначение: " << current->item.value << endl;
				current = current->next;
			}
		}
		head->Free();
		link_list[index] = NULL;
	}
	//вывести на экран найденное значение
	void print_search(wchar_t key[])
	{
		if (ht_search(key) == NULL) wcout << L"Ключ " << key << L" не найден" << endl;
		else  wcout << L"Ключ:" << key << L"\tЗначение: " << ht_search(key) << endl;
	}
	//вывести таблицу
	void print_table()
	{
		note* current;
		wcout << L"\n\t\t\tHash Table\n-------------------------------------------------------------\n";
		for (int i = 0; i < size; i++)
		{                        
			if (link_list[i] != NULL)
			{
				current = link_list[i]->getfirst();
				while (current)
				{
					wcout << L"Индекс: " << i << L"\tКлюч:" << current->item.key << L"\tЗначение: " << current->item.value << endl;
					current = current->next;
				}
				wcout << L"-------------------------------------------------------------\n";
			}
		}
	}
	//выгрузить в файл массив содержащий распределение колизий для данной таблицы
	void collision_table()
	{
		wofstream outfile(L"collision_table.txt");
		int A[MAX];
		for (int i = 0; i < (MAX - 1); i++) A[i] = 0;
		note* current;
		for (int i = 0; i < size; i++)
		{
			if (link_list[i] != NULL)
			{
				current = link_list[i]->getfirst();
				while (current)
				{
					A[i] = A[i] + 1;
					current = current->next;
				}
			}
		}
		for (int i = 0; i < MAX-1; i++) outfile << A[i] << L"\n";
	}
	//выгрузить в файл массив, содержащий распределение коллизий для данной хеш-функции
	void collision_hash()
	{
		wofstream outfile(L"collision_hash.txt");
		int A[MAX];
		wchar_t key[7];
		int index;
		for (int i = 0; i < (MAX - 1); i++) A[i] = 0;
		for (int i = 0; i < MAX * 3; i++)
		{
			GenerateKey(key);
			index = good_hash(key);
			A[index] = A[index] + 1;
		}
		for (int i = 0; i < MAX - 1; i++) outfile << A[i] << L"\n";
	}
}; //конец класса hash_table
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    //печать и ввод русских символов
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	HashTable ht(MAX);	//создать хеш-таблицу
	wchar_t key[7];					//ключ
	wchar_t value[20];			//значение
	int answer = -1;
	while (answer != 0)
	{
		//пользовательское меню
        wcout << endl
            << L"1 - Добавить пару ключ/значение" << endl
            << L"2 - Показать хеш-таблицу" << endl
            << L"3 - Найти значение по ключу" << endl
            << L"4 - Удалить значение по ключу" << endl
            << L"5 - Удалить значения по индексу" << endl
            << L"6 - Заполнить часть таблицы случайными значениями" << endl
            << L"7 - Сохранить в файл распределение коллизий текущей хеш-таблицы" << endl
            << L"8 - Сохранить в файл распределение коллизий заданной хеш-функции" << endl
            << L"9 - Очистить таблицу" << endl
            << L"0 - Выход\nВыберите действие: ";
		//выбор пункта меню и проверка на ошибки
		wcin.clear();
		wcin.ignore(wcin.rdbuf()->in_avail());
		wcin >> answer;
		while (wcin.fail() || answer < 0 || answer > 9)
		{
			wcin.clear(); // Очистить поток ввода
			wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
			wcout << L"Ошибка ввода, выберите действие: ";
			wcin >> answer;
		}
		switch (answer)
		{
			//добавить пару ключ/значение
		case 1:
		{
			wcout << L"Введите ключ: ";
			getwstring(key, 7);
			while (!CheckCorrectKey(key))
			{
				wcout << L"Неверный формат ключа. Введите повторно: ";
				getwstring(key, 7);
			}
			wcout << L"Введите значение: ";
			getwstring(value, 20);
			ht.ht_insert(key, value);
			break;
		}
		//вывести хеш-таблицу
		case 2:
		{
			ht.print_table();
			break;
		}
		//поиск значения по ключу
		case 3:
		{
			wcout << L"Введите ключ: ";
			getwstring(key, 7);
			ht.print_search(key);
			break;
		}
		//удалить элемент по ключу
		case 4:
		{
			wcout << L"Введите ключ: ";
			getwstring(key, 7);
			ht.del_key(key);
			break;
		}
		//удалить элементы по индексу
		case 5:
		{
			int index;
			wcout << L"Введите индекс: ";
			getnum(index);		
			while (index < 0 || index > MAX)
			{
				wcout << L"\nНекорректный индекс. Введите повторно:";
				getnum(index);
			}
			ht.del_key(index);
			break;
		}
		//заполнить таблицу случайными значениями
		case 6:
		{
			int index;
			wcout << L"Введите количество элементов: ";
			getnum(index);
			while (index < 0)
			{
				wcout << L"\nНекорректное число. Введите повторно:";
				getnum(index);
			}
			for (int i = 0; i < index; i++)
			{
				GenerateKey(key);
				GenerateValue(value);
				ht.ht_insert(key, value);
			}
			break;
		}
		//распределение коллизий для данной таблицы
		case 7:
		{
			ht.collision_table();
			wcout << L"\nРаспределение коллизий сохранены в файле collision_table.txt" << endl;
			break;
		}
		//распределение коллизий используемой хеш-функции
		case 8:
		{
			ht.collision_hash();
			wcout << L"\nРаспределение коллизий сохранены в файле collision_hash.txt" << endl;
			break;
		}
		//очистить таблицу
		case 9:
		{
			ht.free_table();
			wcout << L"\nТаблица очищена" << endl;
			break;
		}
		}
	}
	ht.free_table();
	//обнаружение утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;
}
//пользовательский ввод целочисленного значения
void getnum(int& num)
{
	//очистить буфер
	wcin.clear();
	wcin.ignore(wcin.rdbuf()->in_avail());
	//получить число
	wcin >> num;
	//проверить на ошибки
	while (wcin.fail())
	{
		wcin.clear(); // Очистить поток ввода
		wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
		wcout << L"Некорректный ввод. Введите целочисленное значение: ";
		wcin >> num;
	}
}
//пользовательский ввод строки
void getwstring(wchar_t mas[], int size)
{
	//очистить буфер
	wcin.clear();
	wcin.ignore(wcin.rdbuf()->in_avail());
	//получить строку
	wcin.getline(mas, size);
	//проверить на ошибки
	while (wcin.fail())
	{
		wcin.clear(); // Очистить поток ввода
		wcin.ignore(wcin.rdbuf()->in_avail()); // Очистить буфер
		wcout << L"Ошибка ввода. Введите строку: ";
		wcin.getline(mas, size);
	}
}
//сравнение двух массивов
bool compare(wchar_t  a[], wchar_t b[])
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
//копировать один массив в другой
void copy_val(wchar_t  a[], wchar_t b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//сгенерировать случайное число из диапазона
int random(int a, int b)
{
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}
//сгенерировать случайный ключ
void GenerateKey(wchar_t TKey[])
{
	for (int i = 0; i < 6; i++)
	{
        if (TypeOfKey[i] == 's') TKey[i] = random(65, 91);
        if (TypeOfKey[i] == 'd') TKey[i] = random(48, 58);
	}
	TKey[6] = '\0';
}
//проверка корректности введенного ключа
bool CheckCorrectKey(wchar_t TKey[])
{
	for (int i = 0; TKey[i] != '\0'; i++)
	{
        if (TypeOfKey[i] == 's')
			if ((int)TKey[i] < 65 || (int)TKey[i] > 90) return false;
        if (TypeOfKey[i] == 'd')
			if ((int)TKey[i] < 48 || (int)TKey[i] > 57) return false;
	}
	return true;
}
//сгенерировать случайное значение
void GenerateValue(wchar_t Tvalue[])
{
	for (int i = 0; i < 19; i++)
		Tvalue[i] = random(33, 126);
	Tvalue[19] = '\0';
}
//удачная хеш-функция
int good_hash(wchar_t key[]) {
    float minKeyCode = 0;
	for (int i = 0; TypeOfKey[i] != '\0'; i++) {
        if (TypeOfKey[i] == 's') {
            minKeyCode += powf(65, 2);
		}
        if (TypeOfKey[i] == 'd') {
            minKeyCode += powf(48, 2);
		}
	}
    auto h = (int)((pow((int)key[0], 2) + pow((int)key[1], 2) + pow((int)key[2], 2) +
        pow((int)key[3], 2) + pow((int)key[4], 2) + pow((int)key[5], 2)) - minKeyCode) % MAX;

    return h;
}

//неудачная хеш-функция
int  bad_hash(wchar_t key[])
{
	int maxKeyCode=0, minKeyCode=0;
	for (int i = 0; TypeOfKey[i] != '\0'; i++)
	{
        if (TypeOfKey[i] == 's')
		{
			maxKeyCode += 90;
			minKeyCode += 65;
		}
        if (TypeOfKey[i] == 'd')
		{
			maxKeyCode += 57;
			minKeyCode += 48;
		}
	}
	int coefOfDel = maxKeyCode - minKeyCode;
	int h = 0;
	for (int i = 0; TypeOfKey[i] != '\0'; i++)
	{
		h += (int)key[i];
	}
	h = (h - minKeyCode) * (MAX / coefOfDel);
	return h;
}
