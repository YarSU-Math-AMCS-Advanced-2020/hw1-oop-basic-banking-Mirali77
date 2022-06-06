#pragma once
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//����� ����
class Date {
public:
	int day;
	int month;
	int year;
};

//����� ������
class Client
{
	//���� �������
	int client_id;
public:
	//����� �����������
	Date time_of_registration;
	//������ ���� �������
	void set_client_id(int id);
};

//����� ���������� ����
class Individual : public Client {
	//���
	string name;
	//�������
	string surname;
	//��������
	string patronymic;
	//������� ��������
	bool has_patronymic; // ������
	//���� ��������
	Date birth_date;
	//���������� �����
	string phone_number;
public:
	//�����������
	Individual(string _name, string _surname, string _patronymic,
		Date _birth_date, string _phone_number);
	//����� ���������� � �������
	void print_information();
};

//����� ����������� ����
class Buisness : public Client {
	//��������
	string name;
	//�����
	string adress;
	//���������� ����� �����
	string service_phone_number;
public:
	//�����������
	Buisness(string _name, string _adress, string _service_phone_number);
	//����� ���������� � �������
	void print_information();
};

