#include "transaction.h"

//Конструктор
Transaction::Transaction(Card _from_card, Card _to_card,
	long long _ammount_of_money, Currency _operation_currency,
	Date _date_of_transaction, Time _time_of_transaction,
	TransactionStatus _transaction_status)
{
	from_card = &_from_card;
	to_card = &_to_card;
	ammount_of_money = _ammount_of_money;
	operation_currency = _operation_currency;
	date_of_transaction = _date_of_transaction;
	time_of_transaction = _time_of_transaction;
	transaction_status = _transaction_status;
	from_account = from_card->get_binded_account();
	to_account = to_card->get_binded_account();
}

//Выполнение транзакции
void Transaction::Execute() {
	//Обработка случаев отказа
	if (!is_currency_same(*from_account, *to_account)) {
		transaction_status = TransactionStatus::Denied;
	}
	if (ammount_of_money > from_account->get_amount_of_money()) {
		transaction_status = TransactionStatus::Denied;
	}
	if (ammount_of_money > from_account->get_limit()) {
		transaction_status = TransactionStatus::Denied;
	}
	if (ammount_of_money > from_card->get_card_limit()) {
		transaction_status = TransactionStatus::Denied;
	}

	if (transaction_status == Denied) {
		cout << "Transfer is denied. Try again" << endl;
	}
	else {
		to_account->change_ammount_of_money(ammount_of_money);
		from_account->change_ammount_of_money(-ammount_of_money);
		cout << "Transfer is complete!" << endl;
	}
}