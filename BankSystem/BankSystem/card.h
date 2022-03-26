#pragma once
#include <iostream>
#include <string>
#include "client.h"

//Значения платёжной системы
enum PaymentSystem { Lisa, MasterBart, HoMiR };

//Класс Карта
class Card
{
	//Айди счёта, к которому привязана карта
	int binded_account_id;
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
	Card(int _binded_account_id, PaymentSystem _payment_system,
		Date _date_of_expire, long long _card_limit_on_money_withdrawal);
	//Сеттер лиимита
	void set_limit(long long limit);
	//Функция перепривязки карты
	void change_binded_account(int id);
	//Геттер айди аккаунта, к которому привязаны
	int get_binded_account_id();
	//Геттер лимита траты денег на карте
	long long get_card_limit();
	//Вывод информации о карте
	void print_information();
};

