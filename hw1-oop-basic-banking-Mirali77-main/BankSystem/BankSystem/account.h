#pragma once
#include <iostream>
#include <string>
using namespace std;

//Значения валют
enum Currency { Ruble, Dollar, Euro };

//Класс Счёт
class Account
{
	//Валюта
	Currency currency;
	//Лимит на трату денег
	long long limit_on_money_withdrawal;
	//Айди клиента, к которому привязан счёт  
	int binded_client_id;
	//Количество денег на счету
	long long amount_of_money;
	//Айди аккаунта
	int account_id; 
	//Сделать ссылку на клиента
public:
	//Конструктор
	Account(Currency _currency, long long _limit_on_money_withdrawal, int _binded_client_id);
	//Сеттер айди счёта
	void set_account_id(int id);
	//Функция изменения лимита
	void change_limit(long long limit);
	//Геттер лимита
	long long get_limit();
	//Сравнение валют между двумя счетами
	friend bool is_currency_same(Account& const, Account& const);
	//Функция изменения количества денег
	void change_ammount_of_money(long long money_change);
	//Геттер валюты
	Currency get_currency();
	//Геттер количества денег
	long long get_amount_of_money();
	//Вывод информации о счёте
	void print_information();
};