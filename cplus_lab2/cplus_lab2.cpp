#include <iostream>
#include <string>
using namespace std;

struct FIO
{
	char surname[56];
	char name[32];
	char patronomyc[56];
};

struct Adress
{
	int index;
	char country[32];
	char region[32];
	char district[32];
	char city[32];
	char street[32];
	int home;
	int apartment;
};

struct Owner
{
	FIO name;
	Adress adress;
	long long int phonenumber;
	int number;
	long long int phonenumber1;
	int count;
	int figure1;
	int figure2;
	int figure3;
};

void addMemory(Owner*& array, int& size)
{
	Owner* new_array = new Owner[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}

	size++;

	delete[] array;

	array = new_array;
}

void searchOwner(Owner* array, int size)
{
	string surname;
	int num, choose, number = 0;
	long long int phonenumber = 0;

	cout << "Хотите отыскать нужного владельца  по номеру телефона(1) или по фамилии(2)?Введите соответсвующую цифру: ";
	cin >> num;

	if (num == 1)
	{
		cout << "Введите номер телефона: ";
		cin >> phonenumber;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (phonenumber == array[i].phonenumber1)
			{
				cout << "Фамилия: " << array[i].name.surname << endl << "Имя: " << array[i].name.name << endl << "Отчество: " << array[i].name.patronomyc << endl;
				cout << "\tАдрес: " << endl << "Почтовый инлекс: " << array[i].adress.index << ", Страна: " << array[i].adress.country << ", Регион:" << array[i].adress.region;
				cout << ", Город: " << array[i].adress.city << "Улица: " << array[i].adress.street << ", Дом: " << array[i].adress.home << ", Квартира: " << array[i].adress.apartment << endl;
				cout << "Номер телефона: " << array[i].phonenumber1 << endl;
				number++;
			}
		}
		if (number == 0)
		{
			cout << "Владельца с указанным номером не найдено!" << endl << endl;
		}
		cout << "Желаете продолжить поиск?(1 - да, нет - иное число)" << endl;
		cin >> choose;
		if (choose == 1)
		{
			searchOwner(array, size);
			number = 0;
		}

		else
		{
			number = 0;
		}
		cout << "\n";

	}


	if (num == 2)
	{
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (surname == array[i].name.surname)
			{
				cout << "Фамилия: " << array[i].name.surname << endl << "Имя: " << array[i].name.name << endl << "Отчество: " << array[i].name.patronomyc << endl;
				cout << "\tАдрес: " << endl << "Почтовый инлекс: " << array[i].adress.index << ", Страна: " << array[i].adress.country << ", Регион:" << array[i].adress.region;
				cout << ", Город: " << array[i].adress.city << "Улица: " << array[i].adress.street << ", Дом: " << array[i].adress.home << ", Квартира: " << array[i].adress.apartment << endl;
				cout << "Номер телефона: " << array[i].phonenumber << endl;
				number++;
			}
		}

		if (number == 0)
		{
			cout << "Владельца с указанной фамилией не найдено!" << endl;
		}
		cout << "Желаете продолжить поиск?(1 - да, нет - иное число)" << endl;
		cin >> choose;
		if (choose == 1)
		{
			searchOwner(array, size);
			number = 0;
		}

		else
		{
			number = 0;
		}
		cout << "\n";
	}

}

void sort(Owner* array, int size)
{
	Owner temp;

	int choose = 0;
	cout << "Желаете отсортировать массив?Сортировка по номеру телефона (1),не сортировать(2)" << endl;
	cin >> choose;
	if (choose == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].count == 12)
			{
				array[i].figure1 = array[i].phonenumber1 / 100000000000;
				array[i].figure2 = (array[i].phonenumber1 / 10000000000) % 10;
				array[i].figure3 = (array[i].phonenumber1 / 1000000000) % 10;
			}

			if (array[i].count == 11)
			{
				array[i].figure1 = array[i].phonenumber1 / 10000000000;
				array[i].figure2 = (array[i].phonenumber1 / 1000000000) % 10;
				array[i].figure3 = (array[i].phonenumber1 / 100000000) % 10;
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (array[i].figure1 > array[i + 1].figure1&& array[i].figure2 > array[i + 1].figure2&& array[i].figure3 > array[i + 1].figure3)
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
		}
		cout << endl;
		cout << "Массив успешно отсортирован!" << endl << endl;
	}

	else
	{
		cout << "Вы решили не сортировать" << endl << endl;
	}

}


void printArr(Owner* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Владелец под номером " << i + 1 << endl;
		cout << "Фамилия: " << array[i].name.surname << endl << "Имя: " << array[i].name.name << endl << "Отчество: " << array[i].name.patronomyc << endl;
		cout << "\tАдрес: " << endl << "Почтовый инлекс: " << array[i].adress.index << ", Страна: " << array[i].adress.country << ", Регион:" << array[i].adress.region;
		cout << ", Город: " << array[i].adress.city << "Улица: " << array[i].adress.street << ", Дом: " << array[i].adress.home << ", Квартира: " << array[i].adress.apartment << endl;
		cout << "Номер телефона: " << array[i].phonenumber1 << endl;
		cout << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "RU");

	Owner* array;
	int size = 0;
	do
	{
		cout << "Введите количество владельцев стац. телефонов:" << endl;
		cin >> size;
	} while (size < 1);

	array = new Owner[size];

	for (int i = 0; i < size; i++)
	{
		if (size == 1)
		{

			cout << "Введите фамилию:";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(array[i].name.surname, 56);
			cout << endl;

		}

		else
		{
			cout << "Введите фамилию " << i + 1 << " человека: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(array[i].name.surname, 56);
			cout << endl;

		}

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].name.name, 56);
		cout << endl;

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].name.patronomyc, 56);
		cout << endl;

		do
		{
			cout << "Введите почтовый индекс: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> array[i].adress.index;
			cout << endl;
		} while (array[i].adress.index >= 100000 || array[i].adress.index < 10000);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].adress.country, 32);
		cout << endl;

		cout << "Введите регион: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].adress.region, 32);
		cout << endl;

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].adress.city, 32);
		cout << endl;

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(array[i].adress.street, 32);
		cout << endl;

		cout << "Введите номер дома: ";
		cin >> array[i].adress.home;
		cout << endl;

		cout << "Введите номер квартиры: ";
		cin >> array[i].adress.apartment;
		cout << endl;

		do
		{
			array[i].count = 0;
			do
			{
				//находим количество цифр в номере;
				cout << "Введите Номер Телефона: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> array[i].phonenumber;
				array[i].phonenumber1 = array[i].phonenumber;
				do
				{
					array[i].count++;
				} while ((array[i].phonenumber /= 10) > 0);
			} while (array[i].count <= 10);
		} while (array[i].count >= 13);

		cout << endl << "________________________________________________________________________________" << endl << endl;

		if (i == size - 1)
		{
			array[i].number = 0;
			cout << "Добавить еще одного владельца?(1 - да, другое число - нет)" << endl;
			cin >> array[i].number;

			if (array[i].number == 1)
			{
				addMemory(array, size);
			}
		}
	}
	if (size > 1)
	{
		sort(array, size);
		searchOwner(array, size);

	}
	else
	{
		cout << "Вы ввели информацию только об одном владельце!(поиск и сортировка невозможна)" << endl << endl;
	}

	cout << "Вывод информации о владельцах: " << endl;
	printArr(array, size);

}
