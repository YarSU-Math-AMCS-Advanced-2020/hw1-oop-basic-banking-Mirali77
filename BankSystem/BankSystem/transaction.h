#pragma once
#include <iostream>
#include <string>
#include "account.h"
#include "client.h"
using namespace std;

enum class TransactionStatus { IsToProcess, IsProcessing, Done, Denied };

class Time {
public:
	int hour;
	int minute;
	int second;
};

class Transaction
{
	int from_card_id;
	int to_card_id;
	long long ammount_of_money;
	Currency operation_currency;
	Date date_of_transaction;
	Time time_of_transaction;
	TransactionStatus transaction_status;
public:
	Transaction(int _from_card_id, int _to_card_id,
		long long _ammount_of_money, Currency _operation_currency,
		Date _date_of_transaction, Time _time_of_transaction,
		TransactionStatus _transaction_status);
};

