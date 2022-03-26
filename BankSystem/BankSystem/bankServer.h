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

class BankServer {
	map<int, Individual> IndividualClientBase;
	map<int, Buisness> BuisnessClientBase;
	int free_client_id = 1;

	map<int, Account> AccountBase;
	map<int, Account> ClosedAccountBase;
	int free_account_id = 1;

	map<int, Card> CardBase;
	map<int, Card> ClosedCardBase;
	int free_card_id = 1;

	vector<Transaction> TransactionBase;

	vector<CashOperation> CashOperationBase;
public:
	void ClientRegistration();

	void ChangingClientInformation();

	void Transfer();

	void OperateWithCash(bool withdraw_everything);

	void OpeningAccount();

	void ClosingAccount();

	void SetLimitOnWithdrawal();

	void CreatingCard();

	void BindingCardToAnotherAccount();

	void ClosingCard();

	void SetLimitOnCardWithdrawal();

	void Print_client_info();

	void Print_account_info();

	void Print_card_info();
};