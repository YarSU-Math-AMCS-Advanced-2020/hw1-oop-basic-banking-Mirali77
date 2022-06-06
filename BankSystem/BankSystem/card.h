#pragma once
#include <iostream>
#include <string>
#include "client.h"
#include "account.h"

//Значения платёжной системы
enum PaymentSystem { Lisa, MasterBart, HoMiR };

//Класс Карта
class Card
{
	//Счёт, к которому привязана карта
	Account* binded_account;
	//Платёжная система
	PaymentSystem payment_system;
	//Дата отключения карты
	Date date_of_expire;
	//Лимит траты денег на карте
	long long card_limit_on_money_withdrawal;
	//Айди карты
	int card_id;
public:
	//Сеттер айди
	void set_card_id(int id);
	//Конструктор
	Card(Account _binded_account, PaymentSystem _payment_system,
		Date _date_of_expire, long long _card_limit_on_money_withdrawal);
	//Сеттер лиимита
	void set_limit(long long limit);
	//Функция перепривязки карты
	void change_binded_account(Account _account);
	//Геттер айди аккаунта, к которому привязаны
	Account* get_binded_account_id();
	//Геттер лимита траты денег на карте
	long long get_card_limit();
	//Вывод информации о карте
	void print_information();
	//Геттер ссылки на айди привязки
	Account* get_binded_account();
};

