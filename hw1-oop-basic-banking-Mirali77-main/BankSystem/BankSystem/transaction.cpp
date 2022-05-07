#include "transaction.h"

//Конструктор
Transaction::Transaction(int _from_card_id, int _to_card_id,
	long long _ammount_of_money, Currency _operation_currency,
	Date _date_of_transaction, Time _time_of_transaction,
	TransactionStatus _transaction_status)
{
	from_card_id = _from_card_id;
	to_card_id = _to_card_id;
	ammount_of_money = _ammount_of_money;
	operation_currency = _operation_currency;
	date_of_transaction = _date_of_transaction;
	time_of_transaction = _time_of_transaction;
	transaction_status = _transaction_status;
}