#include "bankServer.h"

//Регистрация клиента
void BankServer::ClientRegistration() {
	int date, month, year;
	string type;
	//Запрос даты
	cout << "Enter the date (we are checking you for not being a robot) (Day, Month, Year): ";
	cin >> date >> month >> year;
	//Запрос типа клиента
	cout << "What kind of client are you? (Individual, Buisness): ";
	cin >> type;
	//Если тип - юр.лицо
	if (type == "Individual" || type != "Buisness") {
		string name;
		string surname;
		string patronymic_answer;
		string patronymic = "";
		Date birth_date;
		string phone_number;
		//Запрос имени
		cout << "Enter your name: ";
		cin >> name;
		//Запрос фамилии
		cout << "Enter your surname: ";
		cin >> surname;
		//Запрос отчества
		cout << "Do you have patronymic? (Yes, No): ";
		cin >> patronymic_answer;
		if (patronymic_answer == "Yes") {
			cout << "Enter your patronymic: ";
			cin >> patronymic;
		}
		//Запрос даты рождения
		cout << "Enter your birthdate (Day, Month, Year): ";
		cin >> birth_date.day >> birth_date.month >> birth_date.year;
		//Запрос номера телефона
		cout << "Last step" << endl << "Enter your phone number: ";
		cin >> phone_number;
		cout << "Thank you. Registration is in processing..." << endl;

		//Регистрация
		Individual new_client(name, surname, patronymic, birth_date, phone_number);
		new_client.set_client_id(free_client_id);
		IndividualClientBase.insert(make_pair(free_client_id, new_client));
		free_client_id++;

		cout << "Registration complete! Your id: " << free_client_id - 1 << endl;
	}
	//Если тип - физ.лицо
	else {
		string name;
		string adress;
		string service_phone_number;
		//Запрос названия
		cout << "Enter the name of organisation: ";
		cin >> name;
		//Запрос адреса
		cout << "Enter the adress: ";
		cin >> adress;
		//Запрос номера телефона фирмы
		cout << "Enter the service phone number: ";
		cin >> service_phone_number;
		cout << "Thank you. Registration is in processing..." << endl;

		//Регистрация
		Buisness new_client(name, adress, service_phone_number);
		new_client.set_client_id(free_client_id);
		BuisnessClientBase.insert(make_pair(free_client_id, new_client));
		free_client_id++;

		cout << "Registration complete! Your id: " << free_client_id - 1 << endl;
	}
}

//Изменение информации о клиенте
void BankServer::ChangingClientInformation() {
	//Запрос айди клиента
	int id;
	cout << "Enter your id: ";
	cin >> id;
	if (IndividualClientBase.find(id) != IndividualClientBase.end()) {
		map<int, Individual>::iterator found_node = IndividualClientBase.find(id);
		string name;
		string surname;
		string patronymic_answer;
		string patronymic = "";
		Date birth_date;
		string phone_number;
		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your surname: ";
		cin >> surname;
		cout << "Do you have patronymic? (Yes, No): ";
		cin >> patronymic_answer;
		if (patronymic_answer == "Yes") {
			cout << "Enter your patronymic: ";
			cin >> patronymic;
		}
		cout << "Enter your birthdate (Day, Month, Year): ";
		cin >> birth_date.day >> birth_date.month >> birth_date.year;
		cout << "Last step" << endl << "Enter your phone number: ";
		cin >> phone_number;
		cout << "Thank you. Editing is in processing..." << endl;

		Individual changed_client(name, surname, patronymic, birth_date, phone_number);
		changed_client.set_client_id(id);
		found_node->second = changed_client;

		cout << "Editing complete!" << endl;
	}
	else if (BuisnessClientBase.find(id) != BuisnessClientBase.end()) {
		map<int, Buisness>::iterator found_node = BuisnessClientBase.find(id);

		string name;
		string adress;
		string service_phone_number;
		cout << "Enter the name of organisation: ";
		cin >> name;
		cout << "Enter the adress: ";
		cin >> adress;
		cout << "Enter the service phone number: ";
		cin >> service_phone_number;
		cout << "Thank you. Editing is in processing..." << endl;

		Buisness changed_client(name, adress, service_phone_number);
		changed_client.set_client_id(id);
		found_node->second = changed_client;

		cout << "Editing complete!" << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Перевод денег
void BankServer::Transfer() {
	int from_card_id;
	int to_card_id;
	//Запрос айди карты с которой переводим
	cout << "Enter the card id from which you transfer the money: ";
	cin >> from_card_id;
	if (CardBase.find(from_card_id) != CardBase.end()) {
		//Запрос айди карты, на которую переводим
		cout << "Enter the account id to which you transfer the money: ";
		cin >> to_card_id;
		if (CardBase.find(to_card_id) != CardBase.end()) {
			map<int, Card>::iterator from_card = CardBase.find(from_card_id);
			map<int, Card>::iterator to_card = CardBase.find(to_card_id);
			map<int, Account>::iterator from_account =
				AccountBase.find(from_card->second.get_binded_account_id());
			map<int, Account>::iterator to_account =
				AccountBase.find(to_card->second.get_binded_account_id());
			long long money;
			//Запрос количества денег для перевода
			cout << "Enter the amount of money to transfer: ";
			cin >> money;
			Currency currency = from_account->second.get_currency();
			Date date;
			Time time;
			TransactionStatus status = IsToProcess;
			//Запрос даты
			cout << "Enter today's date (For verification) (Day, Month, Year): ";
			cin >> date.day >> date.month >> date.year;
			//Запрос времени
			cout << "Enter the time (For verification) (Hour, Minute, Second): ";
			cin >> time.hour >> time.minute >> time.second;
			cout << "Transfer is in process..." << endl;

			//Обработка случаев отказа
			if (!is_currency_same(from_account->second, to_account->second)) {
				status = TransactionStatus::Denied;
			}
			if (money > from_account->second.get_amount_of_money()) {
				status = TransactionStatus::Denied;
			}
			if (money > from_account->second.get_limit()) {
				status = TransactionStatus::Denied;
			}
			if (money > from_card->second.get_card_limit()) {
				status = TransactionStatus::Denied;
			}

			//Регистрация транзакции
			Transaction new_transfer(from_card->second.get_binded_account_id(),
				to_card->second.get_binded_account_id(), money, currency, date, time,
				status);
			if (status == Denied) {
				cout << "Transfer is denied. Try again" << endl;
			}
			else {
				to_account->second.change_ammount_of_money(money);
				from_account->second.change_ammount_of_money(-money);
				cout << "Transfer is complete!" << endl;
			}
			TransactionBase.push_back(new_transfer);
		}
		else {
			cout << "Wrong id. Try again" << endl;
		}
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Операция с наличными
void BankServer::OperateWithCash(bool withdraw_everything) {
	//Запрос айди карты
	int card_id;
	cout << "Enter the card id: ";
	cin >> card_id;
	if (CardBase.find(card_id) != CardBase.end()) {
		string answer;
		map<int, Card>::iterator found_card = CardBase.find(card_id);
		map<int, Account>::iterator found_account =
			AccountBase.find(found_card->second.get_binded_account_id());
		long long money = -1, amount_of_money;
		TypeOfOperation type = Withdrawing;
		//Если не опеределелно нужно, что нужно снимать всё с карты или нет
		if (!withdraw_everything) {
			//Запрос типа операции
			cout << "What cash operation do you need? (Withdrawing, Adding): ";
			cin >> answer;
			if (answer == "Withdrawing") {
				type = Withdrawing;
			}
			else {
				money *= -1;
				type = Adding;
			}
			//Запрос количества денег для операции
			cout << "Enter the amount of money: ";
			cin >> amount_of_money;
			money *= amount_of_money;
		}
		//Иначе сумма денег для операции - всё, что есть
		else {
			money = -found_account->second.get_amount_of_money();
		}
		Date date;
		Time time;
		int number_of_department;
		//Запрос даты
		cout << "Enter today's date (For verification) (Day, Month, Year): ";
		cin >> date.day >> date.month >> date.year;
		//Запрос времени
		cout << "Enter the time (For verification) (Hour, Minute, Second): ";
		cin >> time.hour >> time.minute >> time.second;
		StatusOfCashOperation status = Cash_Done;

		//Обработка случаев отказа
		if (found_account->second.get_amount_of_money() + money < 0) {
			status = Cash_Denied;
		}
		if (money < 0 && found_account->second.get_limit() < -money) {
			status = Cash_Denied;
		}
		if (money < 0 && found_card->second.get_card_limit() < -money) {
			status = Cash_Denied;
		}

		//Запрос номера отделения
		cout << "Enter the number of department: ";
		cin >> number_of_department;
		cout << "Operation is processing..." << endl;

		//Регистрация операции
		CashOperation cash_operation(found_account->first, money, type,
			date, time, status, number_of_department);
		if (status == Cash_Done) {
			found_account->second.change_ammount_of_money(money);
			cout << "Operation is complete" << endl;
		}
		else {
			cout << "Operation is denied. Try again" << endl;
		}
	}
	else if (!withdraw_everything) {
		cout << "Wrong id. Try again" << endl;
	}
}

//Открытие счёта
void BankServer::OpeningAccount() {
	//Запрос айди счёта
	int id;
	cout << "Enter your id: ";
	cin >> id;
	if (IndividualClientBase.find(id) != IndividualClientBase.end() ||
		BuisnessClientBase.find(id) != BuisnessClientBase.end()) {
		string currency_answer;
		Currency currency = Ruble;
		long long limit_on_money_withdrawal;
		//Запрос валюты
		cout << "Enter the currency of account (Ruble, Dollar, Euro): ";
		cin >> currency_answer;
		if (currency_answer == "Ruble") {
			currency = Ruble;
		}
		else if (currency_answer == "Dollar") {
			currency = Dollar;
		}
		else if (currency_answer == "Euro") {
			currency = Euro;
		}
		//Запрос лимита
		cout << "Enter the limit on money withdrawal: ";
		cin >> limit_on_money_withdrawal;
		cout << "Thank you. Creating account is in process..." << endl;

		//Регистрация
		Account new_account(currency, limit_on_money_withdrawal, id);
		new_account.set_account_id(free_account_id);
		AccountBase.insert(make_pair(free_account_id, new_account));
		free_account_id++;

		cout << "Account is created! Account id: " << free_account_id - 1 << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Закрытие счёта
void BankServer::ClosingAccount() {
	//Запрос айди аккаунта
	int id;
	cout << "Enter account id: ";
	cin >> id;
	if (AccountBase.find(id) != AccountBase.end()) {
		string answer;
		map<int, Account>::iterator found_account = AccountBase.find(id);
		//Запрос типа дальнейших действий
		cout << "What to do with the money on the account (Transfer, Withdraw): ";
		cin >> answer;
		//Перевод на другую карту
		if (answer == "Transfer") {
			Transfer();
		}
		//Снятие наличиных
		else {
			OperateWithCash(true);
		}
		cout << "Closing account is in processing..." << endl;

		//Перенос счёта в базу закрытых
		ClosedAccountBase.insert(make_pair(id, found_account->second));
		AccountBase.erase(found_account);
		cout << "Account is closed!" << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Установка лимита на вывод со счёта
void BankServer::SetLimitOnWithdrawal() {
	//Запрос айди счёта
	int id;
	cout << "Enter account id: ";
	cin >> id;
	if (AccountBase.find(id) != AccountBase.end()) {
		map<int, Account>::iterator found_account;
		long long limit_on_withdrawal;
		//Запрос лимита
		cout << "What limit do you want to set on account?: ";
		cin >> limit_on_withdrawal;
		cout << "Changing the limit is in process..." << endl;

		//Изменение лимита
		found_account->second.change_limit(limit_on_withdrawal);

		cout << "Limit is changed!" << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Создание карты
void BankServer::CreatingCard() {
	//Запрос айди
	int id;
	cout << "Enter account id: ";
	cin >> id;
	if (AccountBase.find(id) != AccountBase.end()) {
		string answer;
		PaymentSystem payment_system = Lisa;
		Date date_of_expire;
		long long limit_on_withdrawal = AccountBase.find(id)->second.get_limit();
		//Запрос даты
		cout << "Enter today's date(checking for being real) (Day, Month, Year): ";
		cin >> date_of_expire.day >> date_of_expire.month >> date_of_expire.year;
		//Установка даты закрытия карты
		date_of_expire.year += 5;
		//Запрос платёжной системы
		cout << "Enter the paying system (Lisa, MasterBart, HoMiR): ";
		cin >> answer;
		if (answer == "Lisa") {
			payment_system = Lisa;
		}
		else if (answer == "MasterBart") {
			payment_system = MasterBart;
		}
		else if (answer == "HoMiR") {
			payment_system = HoMiR;
		}
		//Запрос лимита на вывод денег с карты
		cout << "Do you want to set a limit on cash withdrawal? (Yes, No): ";
		cin >> answer;
		if (answer == "Yes") {
			cout << "Enter the limit: ";
			cin >> limit_on_withdrawal;
		}
		cout << "Creating a card is in process..." << endl;

		//Регистрация
		Card new_card(id, payment_system, date_of_expire, limit_on_withdrawal);
		new_card.set_card_id(free_card_id);
		CardBase.insert(make_pair(free_card_id, new_card));
		free_card_id++;

		cout << "Card is created. Card id: " << free_card_id - 1 << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Перепривязка карты к другому счёту
void BankServer::BindingCardToAnotherAccount() {
	int card_id;
	int account_id;
	//Запрос айди карты
	cout << "Enter the card id: ";
	if (CardBase.find(card_id) != CardBase.end()) {
		//Запрос айди счёта
		cout << "Enter the account id: ";
		cin >> account_id;
		if (AccountBase.find(account_id) != AccountBase.end()) {
			//Перепривязка карты с к данному счёту
			map<int, Card>::iterator found_card = CardBase.find(card_id);
			found_card->second.change_binded_account(account_id);
			cout << "Binding complete!" << endl;
		}
		else {
			cout << "Wrong id. Try again" << endl;
		}
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Закрытие карты
void BankServer::ClosingCard() {
	//Запрос айди карты
	int id;
	cout << "Enter the card id: ";
	cin >> id;
	if (CardBase.find(id) != CardBase.end()) {
		//Перенос карты в базу закрытых
		map<int, Card>::iterator found_card = CardBase.find(id);
		ClosedCardBase.insert(*found_card);
		CardBase.erase(found_card);
		cout << "Card is closed" << endl;
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Установка лимита на вывод денег с карты
void BankServer::SetLimitOnCardWithdrawal() {
	//Запрос айди
	int id;
	cout << "Enter the card id: ";
	cin >> id;
	if (CardBase.find(id) != CardBase.end()) {
		map<int, Card>::iterator found_card = CardBase.find(id);
		long long new_limit;
		//Запрос лимита
		cout << "Enter the limit on card withdrawal: ";
		cin >> new_limit;
		//Установка нового лимита
		found_card->second.set_limit(new_limit);
		cout << "Limit is changed" << endl;
	}
	else {
		cout << "Wrong id. Try again";
	}
}

//Вывод информации о клиенте
void BankServer::Print_client_info() {
	int id;
	cout << "Enter client's id: ";
	cin >> id;
	if (IndividualClientBase.find(id) != IndividualClientBase.end()) {
		IndividualClientBase.find(id)->second.print_information();
	}
	else if (BuisnessClientBase.find(id) != BuisnessClientBase.end()) {
		BuisnessClientBase.find(id)->second.print_information();
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Вывод информации о счёте
void BankServer::Print_account_info() {
	int id;
	cout << "Enter account's id: ";
	cin >> id;
	if (AccountBase.find(id) != AccountBase.end()) {
		AccountBase.find(id)->second.print_information();
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}

//Вывод информации о карте
void BankServer::Print_card_info() {
	int id;
	cout << "Enter card's id: ";
	cin >> id;
	if (CardBase.find(id) != CardBase.end()) {
		CardBase.find(id)->second.print_information();
	}
	else {
		cout << "Wrong id. Try again" << endl;
	}
}