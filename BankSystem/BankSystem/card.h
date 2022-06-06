#pragma once
#include <iostream>
#include <string>
#include "client.h"
#include "account.h"

//�������� �������� �������
enum PaymentSystem { Lisa, MasterBart, HoMiR };

//����� �����
class Card
{
	//����, � �������� ��������� �����
	Account* binded_account;
	//�������� �������
	PaymentSystem payment_system;
	//���� ���������� �����
	Date date_of_expire;
	//����� ����� ����� �� �����
	long long card_limit_on_money_withdrawal;
	//���� �����
	int card_id;
public:
	//������ ����
	void set_card_id(int id);
	//�����������
	Card(Account _binded_account, PaymentSystem _payment_system,
		Date _date_of_expire, long long _card_limit_on_money_withdrawal);
	//������ �������
	void set_limit(long long limit);
	//������� ������������ �����
	void change_binded_account(Account _account);
	//������ ���� ��������, � �������� ���������
	Account* get_binded_account_id();
	//������ ������ ����� ����� �� �����
	long long get_card_limit();
	//����� ���������� � �����
	void print_information();
	//������ ������ �� ���� ��������
	Account* get_binded_account();
};

