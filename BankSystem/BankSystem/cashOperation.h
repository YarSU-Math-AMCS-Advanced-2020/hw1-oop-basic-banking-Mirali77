#pragma once
#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

enum class TypeOfOperation { Withdrawing, Adding };
enum class StatusOfCashOperation { Cash_Done, Cash_Denied };
class CashOperation
{
	int from_account_id;
	long long amount_of_money;
	TypeOfOperation type_of_operation;
	Date date_of_operation;
	Time time_of_operation;
	StatusOfCashOperation status_of_cash_operation;
	int number_of_department;
public:
	CashOperation(int _from_account_id, long long _amount_of_money,
		TypeOfOperation _type_of_operation, Date _date_of_operation,
		Time _time_of_opearion,
		StatusOfCashOperation _status_of_cash_operation, int _number_of_department);
};

