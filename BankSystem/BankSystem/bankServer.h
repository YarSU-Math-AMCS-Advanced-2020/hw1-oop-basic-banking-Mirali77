#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "account.h"
#include "card.h"
#include "cashOperation.h"
#include "client.h"
#include "transaction.h"
using namespace std;

//Класс Банковский сервер
class BankServer {
	//База клиентов-юр.лиц.
	map<int, Individual> IndividualClientBase;
	//База клиентов-физ.лиц
	map<int, Buisness> BuisnessClientBase;
	//Свободный айди для нового пользователя
	int free_client_id = 1;

	//База счетов
	map<int, Account> AccountBase;
	//База закрытых счетов
	map<int, Account> ClosedAccountBase;
	//Свободный айди для нового счёта
	int free_account_id = 1;

	//База карт
	map<int, Card> CardBase;
	//База закрытых карт
	map<int, Card> ClosedCardBase;
	//Свободный айди для новой карты
	int free_card_id = 1;

	//База транзакций
	vector<Transaction> TransactionBase;

	//База операций с наличными
	vector<CashOperation> CashOperationBase;
public:

	//Регистрация клиента
	void ClientRegistration();

	//Изменение информации о клиенте
	void ChangingClientInformation();

	//Перевод денег
	void Transfer();

	//Операция с наличными
	void OperateWithCash(bool withdraw_everything);

	//Открытие счёта
	void OpeningAccount();

	//Закрытие счёта
	void ClosingAccount();

	//Установление лимита на вывод денег со счёта
	void SetLimitOnWithdrawal();

	//Создание карты
	void CreatingCard();

	//Перепривязка карты к другому счёту
	void BindingCardToAnotherAccount();

	//Закрытие карты
	void ClosingCard();

	//Установка лимита на вывод денег через карту
	void SetLimitOnCardWithdrawal();

	//Вывод информации о клиенте
	void Print_client_info();

	//Вывод информации о счёте
	void Print_account_info();

	//Вывод информации о карте
	void Print_card_info();
};