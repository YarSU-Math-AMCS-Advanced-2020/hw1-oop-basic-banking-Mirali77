#include "cashOperation.h"

//Конструктор
CashOperation::CashOperation(int _from_account_id, long long _amount_of_money,
	TypeOfOperation _type_of_operation, Date _date_of_operation,
	Time _time_of_opearion,
	StatusOfCashOperation _status_of_cash_operation, int _number_of_department)
{
	from_account_id = _from_account_id;
	amount_of_money = _amount_of_money;
	type_of_operation = _type_of_operation;
	date_of_operation = _date_of_operation;
	time_of_operation = _time_of_opearion;
	status_of_cash_operation = _status_of_cash_operation;
	number_of_department = _number_of_department;
}