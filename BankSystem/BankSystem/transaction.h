#pragma once
#include <iostream>
#include <string>
#include "account.h"
#include "client.h"
using namespace std;

//Значения статусов транзакции
enum TransactionStatus { IsToProcess, IsProcessing, Done, Denied };

//Класс Время
class Time {
public:
	int hour;
	int minute;
	int second;
};

//Класс Транзакция
class Transaction
{
	//Айди карты, с которого идёт перечисление денег
	int from_card_id;
	//Айди карты, на которую идёт перечисление денег
	int to_card_id;
	//Количество перечисленных денег
	long long ammount_of_money;
	//Валюта перевода
	Currency operation_currency;
	//Дата транзакции
	Date date_of_transaction;
	//Время транзакции
	Time time_of_transaction;
	//Статус транзакции
	TransactionStatus transaction_status;
public:
	//Конструктор
	Transaction(int _from_card_id, int _to_card_id,
		long long _ammount_of_money, Currency _operation_currency,
		Date _date_of_transaction, Time _time_of_transaction,
		TransactionStatus _transaction_status);
};

