#pragma once
#include <iostream>
#include <string>
#include "account.h"
#include "client.h"
#include "card.h"
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
	//Карта, с которого идёт перечисление денег
	Card* from_card;
	//Карта, на которую идёт перечисление денег
	Card* to_card;
	//Счёт, с которого идёт перечисление денег
	Account* from_account;
	//Счёт, на который идёт перечисление денег
	Account* to_account;
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
	Transaction(Card _from_card, Card _to_card,
		long long _ammount_of_money, Currency _operation_currency,
		Date _date_of_transaction, Time _time_of_transaction,
		TransactionStatus _transaction_status);

	//Выполнить транзакцию
	void Execute();
};

