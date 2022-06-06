#pragma once
#include <iostream>
#include <string>
#include "transaction.h"
#include "account.h"

using namespace std;

//Значения типа операции с наличными (Снятие денег, зачисление)
enum TypeOfOperation { Withdrawing, Adding };

//Значения статуса операции с наличными
enum StatusOfCashOperation { Cash_Done, Cash_Denied };

//Класс Операция с наличными
class CashOperation
{
	//Счёт, с которым идёт операция
	Account* from_account;
	//Количество денег в операции
	long long amount_of_money;
	//Тип операции
	TypeOfOperation type_of_operation;
	//Дата операции
	Date date_of_operation;
	//Время операции
	Time time_of_operation;
	//Статус операции
	StatusOfCashOperation status_of_cash_operation;
	//Номер отделения, в котором произошла операция
	int number_of_department;
public:
	//Конструктор
	CashOperation(Account _from_account, long long _amount_of_money,
		TypeOfOperation _type_of_operation, Date _date_of_operation,
		Time _time_of_opearion,
		StatusOfCashOperation _status_of_cash_operation, int _number_of_department);
	//Выполнить операцию
	void Execute();
};

