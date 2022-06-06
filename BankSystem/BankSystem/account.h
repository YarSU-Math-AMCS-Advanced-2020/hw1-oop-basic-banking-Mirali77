#pragma once
#include <iostream>
#include <string>
#include "client.h"
using namespace std;

//�������� �����
enum Currency { Ruble, Dollar, Euro };

//����� ����
class Account
{
	//������
	Currency currency;
	//����� �� ����� �����
	long long limit_on_money_withdrawal;
	//������, � �������� �������� ����
	Client* binded_client;
	//���������� ����� �� �����
	long long amount_of_money;
	//���� ��������
	int account_id;
public:
	//�����������
	Account(Currency _currency, long long _limit_on_money_withdrawal, Client _binded_client);
	//������ ���� �����
	void set_account_id(int id);
	//������� ��������� ������
	void change_limit(long long limit);
	//������ ������
	long long get_limit();
	//��������� ����� ����� ����� �������
	friend bool is_currency_same(Account& const, Account& const);
	//������� ��������� ���������� �����
	void change_ammount_of_money(long long money_change);
	//������ ������
	Currency get_currency();
	//������ ���������� �����
	long long get_amount_of_money();
	//����� ���������� � �����
	void print_information();
	//������ ����
	int get_id();
};