#include "bankServer.h"

int main() {
	BankServer bank_server;
	bool continue_program = 1;
	int answer;
	while (continue_program) {
		cout << "Choose operation:" << endl;
		cout << "1 - Register new client: " << endl;
		cout << "2 - Change client's information" << endl;
		cout << "3 - Open new account" << endl;
		cout << "4 - Close account" << endl;
		cout << "5 - Set limit on withdrawal from account" << endl;
		cout << "6 - Create new card for account" << endl;
		cout << "7 - Binding card to another account" << endl;
		cout << "8 - Close a card" << endl;
		cout << "9 - Set limit on withdrawal from card" << endl;
		cout << "10 - Transfer money from one card to another" << endl;
		cout << "11 - Operate with cash (Withdrawal, Adding)" << endl;
		cout << "12 - Print client's information" << endl;
		cout << "13 - Print account's information" << endl;
		cout << "14 - Print card's information" << endl;
		cout << "15 - End program" << endl;
		cout << "Enter your choice: ";
		cin >> answer;
		switch (answer) {
		case 1:
			bank_server.ClientRegistration();
			system("pause");
			break;
		case 2:
			bank_server.ChangingClientInformation();
			system("pause");
			break;
		case 3:
			bank_server.OpeningAccount();
			system("pause");
			break;
		case 4:
			bank_server.ClosingAccount();
			system("pause");
			break;
		case 5:
			bank_server.SetLimitOnWithdrawal();
			system("pause");
			break;
		case 6:
			bank_server.CreatingCard();
			system("pause");
			break;
		case 7:
			bank_server.BindingCardToAnotherAccount();
			system("pause");
			break;
		case 8:
			bank_server.ClosingCard();
			system("pause");
			break;
		case 9:
			bank_server.SetLimitOnCardWithdrawal();
			system("pause");
			break;
		case 10:
			bank_server.Transfer();
			system("pause");
			break;
		case 11:
			bank_server.OperateWithCash(false);
			system("pause");
			break;
		case 12:
			bank_server.Print_client_info();
			system("pause");
			break;
		case 13:
			bank_server.Print_account_info();
			system("pause");
			break;
		case 14:
			bank_server.Print_card_info();
			system("pause");
			break;
		case 15:
			continue_program = false;
			break;
		default:
			cout << "Wrong operation. Try again" << endl << endl;
			system("pause");
			break;
		}
	}
	return 0;
}