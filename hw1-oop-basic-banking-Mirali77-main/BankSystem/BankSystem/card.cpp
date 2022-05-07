#include "card.h"

//Конструктор
Card::Card(int _binded_account_id, PaymentSystem _payment_system,
	Date _date_of_expire, long long _card_limit_on_money_withdrawal = -1)
{
	binded_account_id = _binded_account_id;
	payment_system = _payment_system;
	date_of_expire = _date_of_expire;
	card_limit_on_money_withdrawal = _card_limit_on_money_withdrawal;
}

//Сеттер айди
void Card::set_card_id(int id) {
	card_id = id;
}

//Сеттер лимита
void Card::set_limit(long long limit) {
	card_limit_on_money_withdrawal = limit;
}

//Перепривязка карты
void Card::change_binded_account(int id) {
	binded_account_id = id;
}

//Геттер привязки карты
int Card::get_binded_account_id() {
	return binded_account_id;
}

//Геттер лимита карты
long long Card::get_card_limit() {
	return card_limit_on_money_withdrawal;
}

//Вывод информации
void Card::print_information() {
	cout << "Card's information: " << endl;
	cout << "Id: " << card_id << endl;
	cout << "Binded account id: " << binded_account_id << endl;
	cout << "Payment system: ";
	if (payment_system == Lisa) {
		cout << "Lisa" << endl;
	}
	else if (payment_system = MasterBart) {
		cout << "MasterBart" << endl;
	}
	else {
		cout << "HoMiR" << endl;
	}
	cout << "Date of expire: " << date_of_expire.day <<
		"." << date_of_expire.month << "." << date_of_expire.year << endl;
	cout << "Limit on money withdrawal: " << card_limit_on_money_withdrawal << endl;
}