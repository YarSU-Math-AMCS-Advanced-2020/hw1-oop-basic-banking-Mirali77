#pragma once
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//Класс Дата
class Date {
public:
	int day;
	int month;
	int year;
};

//Класс Клиент
class Client
{
	//Айди клиента
	int client_id;
public:
	//Время регистрации
	Date time_of_registration;
	//Сеттер айди клиента
	void set_client_id(int id);
};

//Класс Физическое Лицо
class Individual : public Client {
	//Имя
	string name;
	//Фамилия
	string surname;
	//Отчество
	string patronymic;
	//Наличие отчества
	bool has_patronymic; // Убрать
	//Дата рождения
	Date birth_date;
	//Телефонный номер
	string phone_number;
public:
	//Конструктор
	Individual(string _name, string _surname, string _patronymic,
		Date _birth_date, string _phone_number);
	//Вывод информации о клиенте
	void print_information();
};

//Класс Юридическое лицо
class Buisness : public Client {
	//Название
	string name;
	//Адрес
	string adress;
	//Телефонный номер фирмы
	string service_phone_number;
public:
	//Конструктор
	Buisness(string _name, string _adress, string _service_phone_number);
	//Вывод информации о клиенте
	void print_information();
};

