#include "account.h"

//Конструктор
Account::Account(Currency _currency, long long _limit_on_money_withdrawal,
	int _binded_client_id)
{
	currency = _currency;
	limit_on_money_withdrawal = _limit_on_money_withdrawal;
	binded_client_id = _binded_client_id;
	amount_of_money = 0;
}

//Сравнение валют
bool is_currency_same(Account& const account1, Account& const account2) {
	return account1.currency == account2.currency;
}

//Изменение количества денег
void Account::change_ammount_of_money(long long money_change) {
	amount_of_money += money_change;
}

//Сеттер айди
void Account::set_account_id(int id) {
	account_id = id;
}

//Изменение лимита
void Account::change_limit(long long limit) {
	limit_on_money_withdrawal = limit;
}

//Геттер лимита
long long Account::get_limit() {
	return limit_on_money_withdrawal;
}

//Геттер валюты
Currency Account::get_currency() {
	return currency;
}

//Геттер количества денег
long long Account::get_amount_of_money() {
	return amount_of_money;
}

//Вывод информации
void Account::print_information() {
	cout << "Account's information: " << endl;
	cout << "Id: " << account_id << endl;
	cout << "Currency: ";
	if (currency == Ruble) {
		cout << "Ruble" << endl;
	}
	else if (currency == Dollar) {
		cout << "Dollar" << endl;
	}
	else {
		cout << "Euro" << endl;
	}
	cout << "Limit on money withdrawal: " << limit_on_money_withdrawal << endl;
	cout << "Binded client id: " << binded_client_id << endl;
	cout << "Amount of money: " << amount_of_money << endl;
}