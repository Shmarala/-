#include <iostream>
#include <windows.h>
#include <limits>
#include <string>
#include <iomanip>
#include <unordered_set>

// --------------------Учетки---------------------------------
size_t userSize = 3;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер администратор,", "Администратор", "Продавец" };
std::string* loginArr = new std::string[userSize]{ "admin0","admin","user" };
std::string* passArr = new std::string[userSize]{ "1234","123","12" };
std::string* statusArr = new std::string[userSize]{ userStatus[0],userStatus[1], userStatus[2] };
double* bonusArr = new double[userSize] {0.0, 0.0, 0.0};
unsigned int* userIDArr = new unsigned int[userSize] {1, 2, 3};
unsigned int currentId = 0;
std::string currentStatus;



void ChangeUsers();
void ShowUsers(int mode = 0);
void ChangePass();
void DeleteUser();
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
void ChangeName();
void DeleteItem();
void AddNewUser();
template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);

//-----------------------------------------------------------




// ----------------Продажи----------------------------------
size_t checkSize = 0;
int* idArrCheck;
std::string *nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cashIncome = 0.0;
double bankIncome = 0.0;
double cash = 30000 + rand() % 50000;

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();

//------------------------------------------------------------




// ----------------Служебные----------------------------------
std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
bool isLoginSetCreated = false;
bool isPassSetCreated = false;



void Start();
bool Login();
void SetloginSymbols();
void SetPassSymbols();
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
inline void Err(int time = 1500);
void ShowIncome();
bool Logout();
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
		delete[] idArr;
		delete[] nameArr;
		delete[] countArr;
		delete[] priceArr;
		delete[] bonusArr;
		delete[] userIDArr;
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
					if (isStorageCreated == false)
					{
						CreateStorage();
					}
					system("cls");
					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
					if (isStorageCreated == false)
					{
						
					}
					system("cls");
					ShowSuperAdminMenu();
					
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
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
		}
		else if (currentStatus == userStatus[2])
		{
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
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
				currentId = userIDArr[i];
				return true;
			}
		}
		Err();
	}
}
void SetloginSymbols()
{
	for (char i = '0'; i <= '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	isLoginSetCreated = true;
}
void SetPassSymbols()
{
	for (char i = '!'; i <= '&'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '('; i <= '+'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '/'; i <= '~'; i++)
	{
		passSymbols.insert(i);
	}
	isPassSetCreated = true;
}
bool CheckLogin(const std::string& str)
{
	if (str.size() < 8 || str.size() > 20)
	{
		std::cout << "Ошибка длинны логина\n"; 
		Sleep(1500);
		return false;
	}
	
	for (char sym : str)
	{
		if (!loginSymbols.count(sym))
		{
			std::cout << "Некоректный логин\n";
			Sleep(1500);
			return false; 
		}
	}
	return true;
}
bool CheckPass(const std::string& str)
{
	int numCount = 0;
	int symCount = 0;
	if (str.size() < 0 || str.size() > 20)
	{
		std::cout << "Ошибка длины пароля";
		Sleep(1500);
		return false;
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

		if (choose == "1" && storageSize > 0 )
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0 )
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "\nСклад пустой...\n";
			}
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

void ChangePass()                                            
{
	std::string newPass1, newPass2, choose;
	int userId = 0, isAdmin = 0;
	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВыберите номер пользователя для смены пароля\"exit\" для выхода";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена изменения пароля";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId < isAdmin || userId > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}
		while (true)
		{
			system("cls");
			if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
			{
				std::cout << "Нельзя менять пароль админу!\n";
				Sleep(1500);
				break;
			}
			std::cout << "Введите новый пароль для пользователя" << loginArr[userId] << ": ";
			Getline(newPass1);
			std::cout << "Подтвердите новый пароль для пользователя" << loginArr[userId] << ": ";
			Getline(newPass2);
			if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
			{
				passArr[userId] = newPass1;
				std::cout << "Успешно\n";
				Sleep(1500);
				break;
			}
			else
			{
				std::cout << "Повторите попытку!\n";
				Sleep(1200);
			}
		}
	}
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
	double price[staticSize]{ 333.33, 10.99, 15000, 1760.99, 3000.99, 666666, 300.88, 40000, 99999999999, 77777 };
	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}
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
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t\t" << "Кол-во\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(35) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\t\t\n";
		}
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
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\n";
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
		std::cout << "2 - Изменить название товара\n";
		std::cout << "3 - Удалить товар\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1" && storageSize > 0)
		{
			AddNewItem();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
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
			system("cls");
			std::cout << "Добавление нового товара!\n\nВведите \"exit\" для прекращения операции\n\n";
			std::cout << "Введите кол-во нового товара";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stod(newCount);
				if (count > 1000|| count < 0)
				{
					std::cout << "Ошибка максимальной кол-ва товара";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}


		}

		while (exit)
		{
			system("cls");
			std::cout << "Добавление нового товара!\n\nВведите \"exit\" для прекращения операции\n\n";
			std::cout << "Введите цену нового товара";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 14999.9 || price < 0)
				{
					std::cout << "Ошибка максимальной цены товара";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}


		}

		while (exit)
		{
			std::cout << "Новый товар:" << newName << "\n";
			std::cout << " Кол-во:" << count << "\n";
			std::cout << "Цена:" << price << "\n";
			std::cout << "Подтвердить?\n1 - да\n2- нет\nВвод:";
			Getline(choose);
			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				FillArray(idArrTemp, idArr, storageSize - 1);
				FillArray(nameArrTemp, nameArr, storageSize - 1);
				FillArray(countArrTemp, countArr, storageSize - 1);
				FillArray(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp;
				delete[]nameArrTemp;
				delete[]countArrTemp;
				delete[]priceArrTemp;
				std::cout << "Идёт подготовка....";
				Sleep(2000);
				std::cout << "Товар успешно добвлен\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "отмена\n\n";
				Sleep(1500);
				break;

			}
			else
			{
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}
}
void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции\n";
			Sleep(1500);
			break;
		}

		std::cout << "Введите новое название товара: ";
		Getline(newName);
		if (newName.size() <= 0 || newName.size() >= 80 )
		{
			std::cout << "Ошибка имени. Максимальная длина 80 символов\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId); 
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка!";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << "---->" << newName << "\n\n";
				std::cout << "Подтвердить?\n1-Да\n2-Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Смена названия завершена\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена операции...";
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
void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage();
		std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "\nотмена операции удаления ";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка Id\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Товар на удаление: " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1- да\n2- нет\n Ввод: ";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];
					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}


					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идёт подготовка....";
					Sleep(2000);
					std::cout << "Товар успешно удалён\n\n";
					Sleep(1500);
					break;
				}
				if (choose == "2")
				{
					std::cout << "\nОтмена.....";
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

void ChangeUsers()
{
	if (isLoginSetCreated == false)
	{
		SetloginSymbols();
	}

	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "0 - Выйти из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);

		if (choose == "1")
		{
			AddNewUser();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}
}
void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t"
				<< statusArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t"
				<< statusArr[i] << "\n";
		}
		system("pause");
	}
}
void AddNewUser()
{
	std::string newLogin, newPass, newRole, choose;
	while (exit)
	{
		system("cls");
		std::cout << " Пользователь: " << newLogin << "\n";
		std::cout << "Пароль: " << newPass << "\n";
		std::cout << "Роль: " << newRole <<  "\n";
		std::cout << "Подтвердить?\n1- да\n2- нет\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			userSize++;
			if (newRole == userStatus[2])
			{
				staffCount++;
			}
			std::string* loginArrTemp = new std::string[userSize];
			std::string* passinArrTemp = new std::string[userSize];
			std::string* statusinArrTemp = new std::string[userSize];
			double* bonusArrTemp = new double[userSize];
			unsigned int* userIDArrTemp = new unsigned int[userSize];

			FillArray(loginArrTemp, loginArr, userSize - 1);
			FillArray(passinArrTemp, passArr, userSize - 1);
			FillArray(statusinArrTemp, statusArr, userSize - 1);
			FillArray(bonusArrTemp, bonusArr, userSize - 1);
			FillArray(userIDArrTemp, userIDArr, userSize - 1);

			loginArrTemp[userSize - 1] = newLogin;
			passinArrTemp[userSize - 1] = newPass;
			statusinArrTemp[userSize - 1] = newRole;
			bonusArrTemp[userSize-1] = 0.0;
			userIDArrTemp[userSize - 1] = userSize;

			std::swap(loginArr, loginArrTemp);
			std::swap(passArr, passinArrTemp);
			std::swap(statusArr, statusinArrTemp);
			std::swap(bonusArr, bonusArrTemp);
			std::swap(userIDArr, userIDArrTemp);  
			delete[]loginArrTemp, statusinArrTemp, passinArrTemp, bonusArrTemp, userIDArrTemp;

			std::cout << "Идет подготовка...";
			Sleep(1500);

		}
	}
}
void DeleteUser()
{
	std::string chooseId, checkPass, choose;
	int userId = 0, isAdmin = 1;
	while (true)
	{
		if (currentStatus == userStatus[0] && userSize < 2)
		{
			std::cout << "Нету доступных пользователей для удаления\n";
			Sleep(1500);
			return;
		}
		else if (currentStatus == userStatus[1] && staffCount)
		{
			std::cout << "Нет допустимых пользователей для удаления\n";
			Sleep(1500);
			return;
		}
		ShowUsers();
		std::cout << "\nВыберите номер пользователя для удаления или \"exit\" для выхода";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена удаления пользователя";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId < isAdmin || userId > userSize-1)
			{
				std::cout << "Пользователя с таким номером не существует!";
				Sleep(1500);
				break;
			}
			while (true)
			{
				system("cls");
				if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
				{
					std::cout << "Нелья удалять администратора!";
					Sleep(1500);
					break;
				}
				std::cout << "Удаление пользователя: " << loginArr[userId] << "\n\n";
				std::cout << "Для подтверждения введите пароль супер админа или \"exit\" для выхода";
				Getline(checkPass);
				if (checkPass == "exit")
				{
					std::cout << "ОТмена операции удаления\n";
					Sleep(1500);
					break;
				}
				else if (checkPass == passArr[0])
				{
					
					if (statusArr[userId] == userStatus[2])
					{
						staffCount--;
					}
					userSize--;
					std::string* loginArrTemp = new std::string[userSize];
					std::string* passinArrTemp = new std::string[userSize];
					std::string* statusinArrTemp = new std::string[userSize];
					double* bonusArrTemp = new double[userSize];
					unsigned int* userIDArrTemp = new unsigned int[userSize];

					for (size_t i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userId = c)
						{
							c++;
						}
						loginArrTemp[i] = loginArr[c];
						passinArrTemp[i] = passArr[c];
						statusinArrTemp[i] = statusArr[c];
						bonusArrTemp[i] = bonusArr[c];
						userIDArrTemp[i] = i + 1;
					}
					

					std::swap(loginArr, loginArrTemp);
					std::swap(passArr, passinArrTemp);
					std::swap(statusArr, statusinArrTemp);
					std::swap(bonusArr, bonusArrTemp);
					std::swap(userIDArr, userIDArrTemp);
					delete[]loginArrTemp;
					delete[]statusinArrTemp;
					delete[]passinArrTemp;
					delete[]bonusArrTemp;
					delete[]userIDArrTemp;

					std::cout << "Идет подготовка...";
					Sleep(1500);
					std::cout << "\nПользоавтель успешно удалён";
					Sleep(1500);
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else
		{
			Err();
		}
	}
}

void Selling()
{
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0;
	int index = -1;
	int sleepTimer = 0;
	double money = 0.0, totalSum = 0.0;
	bool isFirst = false;
	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите Id товара для покупки или \"exit\" для завершения выбора товаров: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			system("cls");
			if (isFirst == false)
			{
				std::cout << "Выход без покупок";
				Sleep(1500);
				break;
			}
			
			PrintCheck(totalSum);
			std::cout << "\nПодтвердить покупку?\n1- да\n2- добавить еще товар\n3- Отмена\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Выберите спопсоб оплаты\n1-Наличными\n2- Безнал\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "\nК оплате " << totalSum;
						std::cout << "Введите кол-во наличных";
						Getline(chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stod(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "Нет возможности дать сдачи";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши: " << money << "\n\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << " рублей\n";
								Sleep(2000);
								cash += totalSum;
								cashIncome += totalSum;
								bonusArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						std::cout << "Приложите карту\n\n";
						Sleep(1500);
						sleepTimer = 501;
						if (rand() % 10  <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(sleepTimer);
								sleepTimer -= 100;
							}
							std::cout << "\nСоединение не установленно. Повторите попытку\n\n";
							Sleep(1500);
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(sleepTimer);
								sleepTimer -= 100;
							}
							std::cout << "\nОплата прошла успешно. Спасибо за покупку!\n\n";
							Sleep(1500);
							bankIncome += totalSum;
							bonusArr[currentId] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "rijiy" || choose == "Rijiy")
					{
						std::cout << "Великий Семён оплатил ваш счёт. Всего доброго";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}

				}
				delete[] idArrCheck;
				delete[] nameArrCheck;
				delete[] countArrCheck;
				delete[] priceArrCheck;
				delete[] totalPriceArrCheck;

				idArrCheck = nullptr;
				nameArrCheck = nullptr;
				countArrCheck = nullptr;
				priceArrCheck = nullptr;
				totalPriceArrCheck = nullptr;
				break;
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";
				StorageReturner();
				Sleep(1500);
				system("cls");
				return;
			}
			else
			{
				Err();
				continue;
			}
			system("pause");
			delete[] idArrCheck;
			delete[] nameArrCheck;
			delete[] countArrCheck;
			delete[] priceArrCheck;
			delete[] totalPriceArrCheck;

			idArrCheck = nullptr;
			nameArrCheck = nullptr;
			countArrCheck = nullptr;
			priceArrCheck = nullptr;
			totalPriceArrCheck = nullptr;
			checkSize = 0;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара: ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки товара: " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count < 1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва! Максимум: " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}
		CheckArrAppend();
		if (isFirst == false)
		{
			isFirst == true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index]= nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар добавлен в чек\n\n";
		Sleep(1000);
	}
}
void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int *countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArray(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[] idArrCheckTemp;
	delete[] nameArrCheckTemp;
	delete[] countArrCheckTemp;
	delete[] priceArrCheckTemp;
	delete[] totalPriceArrCheckTemp;

}
void PrintCheck(double& totalSum)
{
	std::cout << "\t" << "Id\t" << std::left << std::setw(25) << "Название товара\t\t" <<
		"Цена за ед\t" << "Кол-во\t" << "Итого\n";
	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i]
			<< "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "Итого к оплате: " << totalSum << "\n\n";
}

void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;




}

void ShowIncome()
{
	system("cls");
	std::cout << "Текущая прибыль за смену\n\n";
	std::cout << "Рассчет наличными: " << cashIncome << "\n";
	std::cout << "Рассчет безналичными: " << bankIncome << "\n";
	std::cout << "Итого: " << cashIncome + bankIncome << "\n\n";
	std::cout << "Итого: " << bonusArr[currentId] << "\n\n";

	system("pause");
	system("cls");
}
bool Logout()
{
	std::string choose;
	system("cls");
	std::cout << "Для подтверждения выхода из пользователя введите свой пароль или \"exit\" для возврата в меню: ";
	Getline(choose);
	if (choose == "exit")
	{
		return true;
	}
	else if (choose == passArr[currentId - 1] || choose == passArr[0])
	{
		system("cls");
		return false;
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
 