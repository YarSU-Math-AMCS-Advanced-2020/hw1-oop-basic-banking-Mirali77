#include "card.h"

//�����������
Card::Card(Account _binded_account, PaymentSystem _payment_system,
	Date _date_of_expire, long long _card_limit_on_money_withdrawal = -1)
{
	binded_account = &_binded_account;
	payment_system = _payment_system;
	date_of_expire = _date_of_expire;
	card_limit_on_money_withdrawal = _card_limit_on_money_withdrawal;
}

//������ ����
void Card::set_card_id(int id) {
	card_id = id;
}

//������ ������
void Card::set_limit(long long limit) {
	card_limit_on_money_withdrawal = limit;
}

//������������ �����
void Card::change_binded_account(Account _account) {
	binded_account = &_account;
}

//������ �������� �����
Account* Card::get_binded_account_id() {
	return binded_account;
}

//������ ������ �����
long long Card::get_card_limit() {
	return card_limit_on_money_withdrawal;
}

//����� ����������
void Card::print_information() {
	cout << "Card's information: " << endl;
	cout << "Id: " << card_id << endl;
	cout << "Binded account id: " << binded_account << endl;
	cout << "Payment system: ";
	if (payment_system == Lisa) {
		cout << "Lisa" << endl;
	}
	else if (payment_system == MasterBart) {
		cout << "MasterBart" << endl;
	}
	else {
		cout << "HoMiR" << endl;
	}
	cout << "Date of expire: " << date_of_expire.day <<
		"." << date_of_expire.month << "." << date_of_expire.year << endl;
	cout << "Limit on money withdrawal: " << card_limit_on_money_withdrawal << endl;
}

//������ ������ �� ���� ��������
Account* Card::get_binded_account() {
	return binded_account;
}