#pragma once
#include <iostream>
#include <string>
#include "transaction.h"
#include "account.h"

using namespace std;

//�������� ���� �������� � ��������� (������ �����, ����������)
enum TypeOfOperation { Withdrawing, Adding };

//�������� ������� �������� � ���������
enum StatusOfCashOperation { Cash_Done, Cash_Denied };

//����� �������� � ���������
class CashOperation
{
	//����, � ������� ��� ��������
	Account* from_account;
	//���������� ����� � ��������
	long long amount_of_money;
	//��� ��������
	TypeOfOperation type_of_operation;
	//���� ��������
	Date date_of_operation;
	//����� ��������
	Time time_of_operation;
	//������ ��������
	StatusOfCashOperation status_of_cash_operation;
	//����� ���������, � ������� ��������� ��������
	int number_of_department;
public:
	//�����������
	CashOperation(Account _from_account, long long _amount_of_money,
		TypeOfOperation _type_of_operation, Date _date_of_operation,
		Time _time_of_opearion,
		StatusOfCashOperation _status_of_cash_operation, int _number_of_department);
	//��������� ��������
	void Execute();
};

