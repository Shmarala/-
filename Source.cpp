#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
/*Магазин церковной утвари*/
/*------------------------------------Учетки---------------------------------------------------------------------------------------------*/
size_t userSize = 2;
std::string userStatus[3]{"Супер администратор,", "Администратор", "Продавец"};
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2]};
std::string currentStatus;
//-----------------------------------------------------------------------------------------------------------------------------------//
// 
//--------------------------------Служебные-----------------------------------------------------------------------------------------//
void Start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int ime = 1500);
//--------------------------------------------------------------------------------------------------------------------------------//
// 
//--------------------------------Склад------------------------------------------------------------------------------------------//

size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool staticStorageCreated = false;
void CreateStorage()
{
	const int staticSize = 10;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Икона с Фаритом","Вазелиновая свеча(30см)","Кадило(кальян со вкусом мята-лайм)",
		"Пластинка с песней Михаила Круга","Крестик с лицом Фарита","Значок Pythona",
		"Святая имба 1л","Татуировка крестов(тюремных)","Роллс Ройс(Владельца церкви)",
		"Татуировка куполов на спине"
	};
	unsigned int count[staticSize]{ 20,30,6,100,42, 666, 40,20, 1,30 };
	double price[staticSize]{ 333.33, 10.99, 15000, 1760.99, 3000.99, 666666, 300.88, 40000, 9999999999999, 77777 };
	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	staticStorageCreated = true;
}
//---------------------------------------------------------------------------------------------------------------------------//


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[]loginArr, passArr, statusArr;
	if (staticStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}
	return 0;
}
inline void Err(int time)
{
	std::cout << "Некоректный ввод!\n\n";
	Sleep(time);
	system("cls");
}
void Start()
{
	/*Магазин церковной утвари*/
	std::cout << "\n\n\nАнтихрист\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			// открытие магазина + создание склада
		}
		else if (currentStatus == userStatus[1])
		{
			// открытие магазина + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			// открытие простого магазина
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершение работы программы ";
	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "\nВведите логин: ";
		Getline(login);
		std::cout << "\nВведите пароль: ";
		Getline(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[0] && pass == passArr[i]);
			{
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобропожаловать!\n\n";
				std::cout << "Ваш статус" << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
			Err();
		}
	}
}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

