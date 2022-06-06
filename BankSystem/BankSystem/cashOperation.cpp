#include "cashOperation.h"

//Конструктор
CashOperation::CashOperation(Account _from_account, long long _amount_of_money,
	TypeOfOperation _type_of_operation, Date _date_of_operation,
	Time _time_of_opearion,
	StatusOfCashOperation _status_of_cash_operation, int _number_of_department)
{
	from_account = &_from_account;
	amount_of_money = _amount_of_money;
	type_of_operation = _type_of_operation;
	date_of_operation = _date_of_operation;
	time_of_operation = _time_of_opearion;
	status_of_cash_operation = _status_of_cash_operation;
	number_of_department = _number_of_department;
}

//Выполнить операцию
void CashOperation::Execute() {
	//Обработка случаев отказа
	if (from_account->get_amount_of_money() + amount_of_money < 0) {
		status_of_cash_operation = Cash_Denied;
	}
	if (amount_of_money < 0 && from_account->get_limit() < -amount_of_money) {
		status_of_cash_operation = Cash_Denied;
	}

	if (status_of_cash_operation == Cash_Done) {
		from_account->change_ammount_of_money(amount_of_money);
		cout << "Operation is complete" << endl;
	}
	else {
		cout << "Operation is denied. Try again" << endl;
	}
}