#include <iostream>
#include <windows.h>
#include <limits>
#include <string>
#include <iomanip>

// --------------------Учетки---------------------------------
size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор,", "Администратор", "Продавец" };
std::string* loginArr = new std::string[userSize]{ "admin","user" };
std::string* passArr = new std::string[userSize]{ "1234","123" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus;
//-----------------------------------------------------------


// ------------------------Склад-----------------------------
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();
void ChangeStorage();
void AddNewItem();

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);

//-----------------------------------------------------------


// ----------------Служебные----------------------------------

void Start();
bool Login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
inline void Err(int time = 1500);
//------------------------------------------------------------
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();
	delete[]loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}

	return 0;
}

void Start()
{

	std::string choose;

	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберетие склад\n1 - Готовый склад\n2 - Создать новый\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					system("cls");
					CreateStorage();
					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
					// создать новый склад
				}
				else
				{
					Err();
				}
			}
			CreateStorage();
		}
		else if (currentStatus == userStatus[1])
		{
			CreateStorage();
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершение работы программы\n\n\n";
	}

}
bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "\t\t\tМагазин Антихрист\t\t\t\n";
		std::cout << "Введите логин: ";
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
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобрый ден!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();
	}
}
void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редактировать персонал\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			Err();
		}

	}
}
bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длины числа. Максимум девятизначные числа!\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введенные данные не являются числом!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;

}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}
inline void Err(int time)
{
	std::cout << "Некорректный ввод\n\n\n";
	Sleep(time);
	system("cls");
}
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
	isStorageCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(priceArr, price, storageSize);
}
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(35) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\t\t\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t\t\n";
		}
	}
}
void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int count = 0, id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или слово \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции пополнение товара!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для пополнения: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 777)
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 777";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << "--->" << countArr[id] + count << "\n\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}

}
void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int count = 0, id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или слово \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции списания товара!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для списания: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во -" << countArr[id] << "\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << "--->" << countArr[id] - count << "\n\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списание товара\n\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}
}
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить товар\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2")
		{
			
		}
		else if (choose == "3")
		{
	
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			Err();
		}
	}
}
void ChangePrice()
{
	std::string chooseId, choosePrice, choose;
	unsigned int id = 0;
	double newPrice = 0.0;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или слово \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции изменения цуны!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новую цену товара:  ";
		Getline(choosePrice);

		if (IsNumber(chooseId) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseId) - 1;
			newPrice = std::stod(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0 || newPrice > 7777777)
			{
				std::cout << "Некорректный id или цена\nМаксимальная цена 7777777";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t" << priceArr[id] << "--->" << newPrice << "\n\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = newPrice;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}
}
void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВедите \"exit\" для прекращения операции\n\n";
			std::cout << "Введите название нового товара";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 80)
			{
				std::cout << "Ошибка имени. Максимальная длинна 80 символов\n";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}

		while (exit)
		{

			
			

		}



	}


}
template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArray[i] = staticArray[i];
	}
}
