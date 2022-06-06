#pragma once
#include <iostream>
#include <string>
#include "account.h"
#include "client.h"
#include "card.h"
using namespace std;

//�������� �������� ����������
enum TransactionStatus { IsToProcess, IsProcessing, Done, Denied };

//����� �����
class Time {
public:
	int hour;
	int minute;
	int second;
};

//����� ����������
class Transaction
{
	//�����, � �������� ��� ������������ �����
	Card* from_card;
	//�����, �� ������� ��� ������������ �����
	Card* to_card;
	//����, � �������� ��� ������������ �����
	Account* from_account;
	//����, �� ������� ��� ������������ �����
	Account* to_account;
	//���������� ������������� �����
	long long ammount_of_money;
	//������ ��������
	Currency operation_currency;
	//���� ����������
	Date date_of_transaction;
	//����� ����������
	Time time_of_transaction;
	//������ ����������
	TransactionStatus transaction_status;
public:
	//�����������
	Transaction(Card _from_card, Card _to_card,
		long long _ammount_of_money, Currency _operation_currency,
		Date _date_of_transaction, Time _time_of_transaction,
		TransactionStatus _transaction_status);

	//��������� ����������
	void Execute();
};

