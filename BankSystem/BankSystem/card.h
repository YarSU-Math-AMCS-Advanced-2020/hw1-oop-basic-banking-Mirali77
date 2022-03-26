#pragma once
#include <iostream>
#include <string>
#include "client.h"

enum class PaymentSystem { Lisa, MasterBart, HoMiR };

class Card
{
	int binded_account_id;
	PaymentSystem payment_system;
	Date date_of_expire;
	long long card_limit_on_money_withdrawal;
public:
	int card_id;
	void set_card_id(int id);
	Card(int _binded_account_id, PaymentSystem _payment_system,
		Date _date_of_expire, long long _card_limit_on_money_withdrawal);
	void set_limit(long long limit);
	void change_binded_account(int id);
	int get_binded_account_id();
	long long get_card_limit();
	void print_information();
};

